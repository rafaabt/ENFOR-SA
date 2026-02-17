#ifndef MxM__H
#define MxM__H

#include <cstring>
#include "Gemmini.h"


/* the prepared inputs for streaming */
Input_t *inputLeftRight_streamable = nullptr;
Input_t *inputTopBottom_streamable = nullptr;

#define MAX_STREAM_SIZE 200 // max number of columns in the inputLeftRight, == max rows in input B

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
        inputLeftRight_streamable = new Input_t[DIM*MAX_STREAM_SIZE];
        inputTopBottom_streamable = new Input_t[DIM*MAX_STREAM_SIZE];
    }

    ~MxM() // this is going to be called automatically (i.e, no need for delete) due to the singleton pattern
    {
        printfinish();
        if(gemmini)
            delete gemmini;

        if(inputLeftRight_streamable)
            delete[] inputLeftRight_streamable;

        if(inputTopBottom_streamable)
            delete[] inputTopBottom_streamable;
    }

    /* A basic API to link apps to Gemmini */
#ifdef GEMM_OS
    uint32_t preload(const Output_t *m); // OS: preloads output types. WS: preloads weight/input types
    
    uint32_t stream(
        const Input_t *inputLeftRight, 
        const Input_t *inputTopBottom, 
        uint16_t stream_size);

    uint32_t flush(
        Output_t *outputC, 
        bool transpose_output=false);

#else // GEMM_WS
    uint32_t preload(const Input_t *m); // OS: preloads output types. WS: preloads weight/input types
   
    uint32_t stream(
        const Input_t *inputLeftRight, 
        Output_t *outputC, 
        uint16_t stream_size);

    uint32_t stream_bias(
        const Input_t *inputLeftRight, 
        const Output_t *inputTopBottom, 
        Output_t *outputC, 
        uint16_t stream_size);
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
    static void PrepareInputs(
        const Input_t *inputLeftRight, 
        const Input_t *inputTopBottom, 
        uint16_t stream_size);

#ifdef GEMM_OS
    uint32_t _gemmini_stream_os(
        const Input_t *inputLeftRight, 
        const Input_t *inputTopBottom,
        uint16_t stream_size);
#else
    uint32_t _gemmini_stream_ws(
        const Input_t *inputLeftRight, 
        const Output_t *inputTopBottom,
        Output_t *outputC,
        uint16_t stream_size);
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
uint32_t MxM::preload (const Output_t *m) // OS: Preloads D
#else
uint32_t MxM::preload (const Input_t *m)  // WS: Preloads B
#endif
{
    debugprintf ("MxM: preload()\n");
    return gemmini->preload(m);
}


#ifdef GEMM_OS

// OS: flush C from the accumulators. stores the outputs in outputC
uint32_t MxM::flush(Output_t *outputC, bool transpose_output)
{
    debugprintf ("MxM: flush()\n");
    return gemmini->flushOS(outputC, transpose_output);
}


/* Performs stream OS and keeps the data in the accumulators
   this essential for OS mode, for example, when computing tiled matrix multiplication,
   because the accumulators have to accumulate the results for each tile, without needing to accumulate this outside the array.
*/

/* OS: stream A and B */
uint32_t MxM::stream(
    const Input_t *inputLeftRight, 
    const Input_t *inputTopBottom,
    uint16_t stream_size) // [OS only] C = AxB (D must be preloaded first if it's not zero)
{    
    debugprintf ("MxM: Performing stream OS (%d %d)\n", DIM, DIM);
    uint32_t comp = _gemmini_stream_os(inputLeftRight, inputTopBottom, stream_size);
    return comp;
}


#else // GEMM_WS

/* Stream A. D is zero */
uint32_t MxM::stream(
    const Input_t *inputLeftRight, // A matrix
    Output_t *outputC,
    uint16_t stream_size) // [WS only] C = AxB (B must be preloaded first)
{    
    debugprintf ("MxM: Performing stream WS (%d %d)\n", DIM, DIM);
    return _gemmini_stream_ws(inputLeftRight, &Z[0][0], outputC, stream_size); // Z is the zero matrix
}


/* Stream A and D */
uint32_t MxM::stream_bias(
    const Input_t *inputLeftRight,  // A matrix
    const Output_t *inputTopBottom, // D matrix
    Output_t *outputC,
    uint16_t stream_size) // [WS only] C = AxB + D (B must be preloaded first)
{    
    debugprintf ("MxM: Performing stream WS (%d %d)\n", DIM, DIM);
    uint32_t r = _gemmini_stream_ws(inputLeftRight, inputTopBottom, outputC, stream_size);
    return r;
}
#endif


#ifdef GEMM_OS
uint32_t MxM::_gemmini_stream_os(
    const Input_t *inputLeftRight, // A matrix
    const Input_t *inputTopBottom, // B matrix
    uint16_t stream_size)
{
    debugprintf ("MxM: Performing _gemmini_stream_os (%d %d)\n", DIM, DIM);
    MxM::PrepareInputs(inputLeftRight, inputTopBottom, stream_size); // this will padd and transpose the matrices according to the requested type of stream (OS or WS)
    return gemmini->streamOS(inputLeftRight_streamable, inputTopBottom_streamable, 2*stream_size-1);
}

#else // GEMM_WS
uint32_t MxM::_gemmini_stream_ws(
    const Input_t *inputLeftRight,  // A matrix
    const Output_t *inputTopBottom, // D matrix
    Output_t *outputC,   // C = A.B + D ->  B must have been preloaded
    uint16_t stream_size)  
{
    debugprintf ("MxM: Performing _gemmini_stream_ws (%d %d)\n", DIM, DIM);
    MxM::PrepareInputs(inputLeftRight, inputTopBottom, stream_size); // the second parameter is not used for WS 
    return gemmini->streamWS(inputLeftRight_streamable, inputTopBottom_streamable, outputC, 2*stream_size-1);
}
#endif


void MxM::PrepareInputs(
    const Input_t *inputLeftRight, // A matrix
    const Input_t *inputTopBottom, // B or D matrix
    uint16_t stream_size)
{
    debugprintf ("MxM: Performing PrepareInputs()\n");
    //MxM::inputsPrep = true;

#ifdef GEMM_OS
    MatUtils::paddRowsWithZeros<Input_t>(inputLeftRight_streamable, inputLeftRight, stream_size);  // A with zero-padded rows
    MatUtils::paddRowsWithZerosTransp<Input_t>(inputTopBottom_streamable, inputTopBottom, stream_size); // B tranposed, then padded
    
    #if 0
    MatUtils::print(inputLeftRight, DIM, stream_size);
    MatUtils::print(inputLeftRight_streamable, DIM, 2*stream_size-1);
    printf("\n");
    exit(0);
    #endif

    #if 0
    MatUtils::print(inputTopBottom, DIM, stream_size);
    MatUtils::print(inputTopBottom_streamable, DIM, 2*stream_size-1);
    //exit(0);
    #endif

#else
    MatUtils::paddRowsWithZerosTransp<Input_t>(inputLeftRight_streamable, inputLeftRight, stream_size); // A transposed, then padded
    MatUtils::paddRowsWithZerosTransp<Input_t>(inputTopBottom_streamable, inputTopBottom, stream_size); // D transposed, then padded
#endif
}

#endif
