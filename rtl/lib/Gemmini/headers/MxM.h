#ifndef MxM__H
#define MxM__H

#include <cstring>
#include "Gemmini.h"


/* These are the "prepared" actual matrices Gemmini computes from (they read the values from A, B and D) 
    t: transposed; 
    p: padded; 
    tb: transposed then padded 
    bt: padded then transposed */

Input_t Ap[DIM][PDIM], Atp[DIM][PDIM], Btp[DIM][PDIM];
Output_t Dp[DIM][PDIM], Dtp[DIM][PDIM];


class MxM
{
public:

#if 0 // i cannot use this if we need more than one MxM instance (e.g., for parallel matmuls on Gemmini)
    // Delete the copy constructor and assignment operator to prevent copying
    MxM (const MxM&) = delete;
    MxM& operator=(const MxM&) = delete;

    // Static method to access the single instance
    static MxM& getInstance() 
    {
        static MxM instance;  // This instance is created only once
        return instance;
    }

    static MxM *getInstance(Gemmini *gemm) 
    {
        static MxM instance(gemm);  // This instance is created only once
        return &instance;
    }
#endif

    MxM(Gemmini *gemm)
    {
        gemmini = gemm;
    }

    ~MxM() // this is going to be called automatically (i.e, no need for delete) due to the singleton pattern
    {
        printfinish();
        if (gemmini)
            delete gemmini;
    }

    /* A basic API to link apps to Gemmini */
#ifdef GEMM_OS
    uint32_t preload(const Output_t m[DIM][DIM]); // OS: preloads output types. WS: preloads weight/input types
    uint32_t stream(const Input_t inputA[DIM][DIM], const Input_t inputB[DIM][DIM]);
    uint32_t flush(Output_t outputC[DIM][DIM], bool transpose_output=false);
#else // GEMM_WS
    uint32_t preload(const Input_t m[DIM][DIM]); // OS: preloads output types. WS: preloads weight/input types
    uint32_t stream(const Input_t inputA[DIM][DIM], Output_t outputC[DIM][DIM]);
    uint32_t stream_bias(const Input_t inputA[DIM][DIM], const Output_t inputD[DIM][DIM], Output_t outputC[DIM][DIM]);
#endif

    uint32_t reset();

    Gemmini *gemmini;

    void tick_test_perf(size_t trials) // just performs raw calls to the verilated simul to check the mean time per cycle
    {
        for (size_t i = 0; i < trials; i++)
        {
            gemmini->mesh->dut->CLK = 0; 
            gemmini->mesh->dut->eval();
            gemmini->mesh->dut->CLK = 1;
            gemmini->mesh->dut->eval();
        }
    }

private:

    static void PrepareInputs(const Input_t inputA[DIM][DIM], const Input_t inputB[DIM][DIM]);

#ifdef GEMM_OS
    uint32_t _gemmini_stream_os(const Input_t inputA[DIM][DIM], const Input_t  inputB[DIM][DIM]);
#else
    uint32_t _gemmini_stream_ws(const Input_t inputA[DIM][DIM], const Output_t inputD[DIM][DIM], Output_t outputC[DIM][DIM]);
#endif

    //static bool inputsPrep;
    //static bool tilesPrep;
};


//bool MxM::inputsPrep = false;
//bool MxM::tilesPrep  = false;


uint32_t MxM::reset()
{
    debugprintf ("MxM: reset()\n");
    return gemmini->resetMesh();
}

#ifdef GEMM_OS
uint32_t MxM::preload (const Output_t m[DIM][DIM]) 
#else
uint32_t MxM::preload (const Input_t m[DIM][DIM]) 
#endif
{
    debugprintf ("MxM: preload()\n");
    return gemmini->preload(m);
}


#ifdef GEMM_OS
uint32_t MxM::flush(Output_t outputC[DIM][DIM], bool transpose_output)
{
    debugprintf ("MxM: flush()\n");
    return gemmini->flushOS(outputC, transpose_output);
}


/* Performs stream OS and keeps the data in the accumulators
   this essential for OS mode, for example, when computing tiled matrix multiplication,
   because the accumulators have to accumulate the results for each tile, without needing to accumulate this outside the array.
*/

uint32_t MxM::stream(const Input_t inputA[DIM][DIM], const Input_t inputB[DIM][DIM]) // [OS only] C = AxB (D must be preloaded first if it's not zero)
{    
    debugprintf ("MxM: Performing stream OS (%d %d)\n", DIM, DIM);
    uint32_t comp = _gemmini_stream_os(inputA, inputB);
    return comp;
}


#else // GEMM_WS
uint32_t MxM::stream(const Input_t inputA[DIM][DIM], Output_t outputC[DIM][DIM]) // [WS only] C = AxB (B must be preloaded first)
{    
    debugprintf ("MxM: Performing stream WS (%d %d)\n", DIM, DIM);
    return _gemmini_stream_ws(inputA, Z, outputC);
}


uint32_t MxM::stream_bias(const Input_t inputA[DIM][DIM], const Output_t inputD[DIM][DIM], Output_t outputC[DIM][DIM]) // [WS only] C = AxB + D (B must be preloaded first)
{    
    debugprintf ("MxM: Performing stream WS (%d %d)\n", DIM, DIM);
    uint32_t r = _gemmini_stream_ws(inputA, inputD, outputC);
    return r;
}
#endif


#ifdef GEMM_OS
uint32_t MxM::_gemmini_stream_os(const Input_t inputA[DIM][DIM], const Input_t inputB[DIM][DIM])
{
    debugprintf ("MxM: Performing _gemmini_stream_os (%d %d)\n", DIM, DIM);
    MxM::PrepareInputs(inputA, inputB); // this will padd and transpose the matrices according to the requested type of stream (OS or WS)
    return gemmini->streamOS(Ap, Btp);
}

#else // GEMM_WS
uint32_t MxM::_gemmini_stream_ws(const Input_t inputA[DIM][DIM], const Output_t inputD[DIM][DIM], Output_t outputC[DIM][DIM])  // C = A.B + D -  B must have been preloaded
{
    debugprintf ("MxM: Performing _gemmini_stream_ws (%d %d)\n", DIM, DIM);
    MxM::PrepareInputs(inputA, inputD); // the second parameter is not used for WS 
    return gemmini->streamWS(Atp, Dtp, outputC);
}
#endif


void MxM::PrepareInputs(const Input_t inputA[DIM][DIM], const Input_t inputBorD[DIM][DIM])
{
    debugprintf ("MxM: Performing PrepareInputs()\n");
    //MxM::inputsPrep = true;

#ifdef GEMM_OS
    MatUtils::paddRowsWithZeros<Input_t, DIM, PDIM> (Ap, inputA); 
    MatUtils::paddRowsWithZerosTransp<Input_t, DIM, PDIM> (Btp, inputBorD);  // equivalent to MatUtils::transpose(.);  then MatUtils::paddRowsWithZeros(.); 
#else
    MatUtils::paddRowsWithZerosTransp<Input_t,  DIM, PDIM>(Atp, inputA);
    MatUtils::paddRowsWithZerosTransp<Output_t, DIM, PDIM>(Dtp, inputBorD);

    //MatUtils::paddRowsWithZeros<Input_t, DIM, PDIM> (Ap, inputA); 
    //MatUtils::paddRowsWithZeros<Output_t, DIM, PDIM>(Dp, inputBorD);
#endif
}

#endif