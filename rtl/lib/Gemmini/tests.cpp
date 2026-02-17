#include <iostream>
#include <vector>
#include <time.h>
#include "headers/MxM.h"


#define STREAM_SIZE 12

using namespace std;

static bool test_case_1();
static bool test_case_2();

/* Standard inputs the same size as the Gemmini grid */

Input_t *A1, *B1, *D1;
Input_t *A2, *B2, *D2;
Input_t *A3, *B3, *D3;

Output_t *Psum1, *Psum2;
Output_t *Cgold; // the golden matrix computed in sw for verification. SDCs are flagged when C != Cgold

/* Gemmini will store its outputs in the C matrix (for non-tiled MxM) */
Output_t *C; // the C output computed by the systolic array


void init()
{
    A1 = new Input_t[DIM*STREAM_SIZE];
    A2 = new Input_t[DIM*STREAM_SIZE];
    A3 = new Input_t[DIM*STREAM_SIZE];

    B1 = new Input_t[DIM*STREAM_SIZE];
    B2 = new Input_t[DIM*STREAM_SIZE];
    B3 = new Input_t[DIM*STREAM_SIZE];

    D1 = new Input_t[DIM*STREAM_SIZE];
    D2 = new Input_t[DIM*STREAM_SIZE];
    D3 = new Input_t[DIM*STREAM_SIZE];

    Psum1 = new Output_t[DIM*DIM];
    Psum2 = new Output_t[DIM*DIM];

    C = new Output_t[DIM*DIM];
    Cgold = new Output_t[DIM*DIM];
}


void finish()
{
    delete[] A1;
    delete[] A2; 
    delete[] A3; 
    delete[] B1; 
    delete[] B2;
    delete[] B3;
    delete[] Psum1; 
    delete[] Psum2;
    delete[] D1;
    delete[] D2;
    delete[] D3;
    delete[] C;
    delete[] Cgold; 
}

// valgrind --leak-check=full --track-origins=yes ./bin/CustomGemminiOSMediumSoCConfig

int main (int argc, char** argv) 
{
    simOpt = parseOptions(argc, argv);

    init();
    
    printf ("Testing with Gemmini %s\n", GEMM_CONFIG_ALIAS);

#define TEST_CASES 2

    bool (*test_cases[])(void) = {test_case_1, test_case_2};

    bool passed[TEST_CASES] = {0};


    for(uint32_t i = 0; i < TEST_CASES; i++)
        passed[i] = test_cases[i]();

    for(uint32_t i = 0; i < TEST_CASES; i++)
    {
        if(passed[i])
            printf("Test %u: %sPassed%s\n", i, GREEN, RESET); 
        else
            printf("Test %u: %sFailed%s\n", i, RED, RESET);
    }

    finish();

    return 0;
}


#ifdef GEMM_OS

#define TRIALS 10

static bool test_case_1()
{
    /* Test: C = A1B1 + A2B2 + A3B3 + D1 */

    printf("Running test case: %s\n", __FUNCTION__);

    //MxM *mxm = MxM::getInstance(new Gemmini(new VL_DUT, GEMM_CONFIG_ALIAS));
    MxM *mxm = new MxM(new Gemmini(new VL_DUT, GEMM_CONFIG_ALIAS));

    uint32_t itersPre;
    uint32_t itersMul;  
    uint32_t itersFlush;
    uint32_t failures = 0;

    for (uint32_t i = 0; i < TRIALS; i++)
    {
        //MatUtils::loadZeros<Output_t>(D, DIM, DIM);
        MatUtils::loadRand<Output_t>(D1, DIM, DIM);

        MatUtils::loadRand<Input_t>(A1, DIM, STREAM_SIZE);
        MatUtils::loadRand<Input_t>(A2, DIM, STREAM_SIZE);
        MatUtils::loadRand<Input_t>(A3, DIM, STREAM_SIZE);

        MatUtils::loadRand<Input_t>(B1, STREAM_SIZE, DIM);
        MatUtils::loadRand<Input_t>(B2, STREAM_SIZE, DIM);
        MatUtils::loadRand<Input_t>(B3, STREAM_SIZE, DIM);

        MatUtils::matmul<Input_t,Output_t>(A1, B1, D1,    Psum1, DIM, STREAM_SIZE, STREAM_SIZE, DIM);  // Psum1 = A1B1 + D1
        MatUtils::matmul<Input_t,Output_t>(A2, B2, Psum1, Psum2, DIM, STREAM_SIZE, STREAM_SIZE, DIM);  // Psum2 = A2B2 + A1B1 + D1
        MatUtils::matmul<Input_t,Output_t>(A3, B3, Psum2, Cgold, DIM, STREAM_SIZE, STREAM_SIZE, DIM);  // Cgold = A3B3 + A2B2 + A1B1 + D1

        itersPre = mxm->preload(D1);
        itersMul = mxm->stream(A1, B1, STREAM_SIZE);
        itersMul = mxm->stream(A2, B2, STREAM_SIZE);
        itersMul = mxm->stream(A3, B3, STREAM_SIZE);
        itersFlush = mxm->flush(C);
        
        if (!MatUtils::compare<Output_t>(C, Cgold, DIM, DIM))
        {
            printf("Error: matmul mismatch\n");
            MatUtils::debugPrint<Output_t>(Cgold, C, DIM, DIM);
            failures++;
        }
    }

    mxm->gemmini->clearFaultList();
    delete mxm;
    return failures == 0;
}

#else

#define TRIALS 10

static bool test_case_1()
{
    /* Test with fixed preloaded B1 matrix:
        C = A1*B1 + D1
        C = A2*B1 + D2
        C = A3*B1 + D3 */

    printf("Running test case: %s (WS)\n", __FUNCTION__);

    //MxM *mxm = MxM::getInstance(new Gemmini(new VL_DUT, GEMM_CONFIG_ALIAS));
    MxM *mxm = new MxM(new Gemmini(new VL_DUT, GEMM_CONFIG_ALIAS));

    uint32_t itersPre;
    uint32_t itersMul;  
    uint32_t itersFlush;
    uint32_t failures = 0;

    for (uint32_t i = 0; i < TRIALS; i++)
    {
        MatUtils::loadRand<Input_t>(B1, DIM, DIM);
        itersPre = mxm->preload(B1);

        MatUtils::loadRand<Input_t>(A1, DIM, DIM);
        MatUtils::loadRand<Input_t>(A2, DIM, DIM);
        MatUtils::loadRand<Input_t>(A3, DIM, DIM);

        MatUtils::loadRand<Input_t>(D1, DIM, DIM);
        MatUtils::loadRand<Input_t>(D2, DIM, DIM);
        MatUtils::loadRand<Input_t>(D3, DIM, DIM);

        MatUtils::matmul<Input_t,Output_t>(A1, B1, D1, Cgold, DIM, DIM, DIM, DIM);
        itersMul = mxm->stream_bias(A1, D1, C, DIM);

        if (!MatUtils::compare<Output_t>(C, Cgold, DIM, DIM))
        {
            printf("Error: matmul mismatch (1)\n");
            MatUtils::debugPrint<Output_t>(Cgold, C, DIM, DIM);
            failures++;
        }

        MatUtils::matmul<Input_t,Output_t>(A2, B1, D2, Cgold, DIM, DIM, DIM, DIM);
        itersMul = mxm->stream_bias(A2, D2, C, DIM);

        if (!MatUtils::compare<Output_t>(C, Cgold, DIM, DIM))
        {
            printf("Error: matmul mismatch (2)\n");
            MatUtils::debugPrint<Output_t>(Cgold, C, DIM, DIM);
            failures++;
        }

        MatUtils::matmul<Input_t,Output_t>(A3, B1, D3, Cgold, DIM, DIM, DIM, DIM);
        itersMul = mxm->stream_bias(A3, D3, C, DIM);

        if (!MatUtils::compare<Output_t>(C, Cgold, DIM, DIM))
        {
            printf("Error: matmul mismatch (3)\n");
            MatUtils::debugPrint<Output_t>(Cgold, C, DIM, DIM);
            failures++;
        }
    }

    mxm->gemmini->clearFaultList();
    delete mxm;
    return failures == 0;
}
#endif


static bool test_case_2()
{
    printf("Running test case: %s\n", __FUNCTION__);

    //MxM *mxm = MxM::getInstance(new Gemmini(new VL_DUT, GEMM_CONFIG_ALIAS));
    MxM *mxm = new MxM(new Gemmini(new VL_DUT, GEMM_CONFIG_ALIAS));

    uint32_t itersPre;
    uint32_t itersMul;  
    uint32_t itersFlush;

    uint32_t failures = 0;

    if(simOpt.faulty) 
    {
        if(simOpt.faultModel == (int)FaultModel::FM_TRANSIENT)
            mxm->gemmini->addTransientFault(FaultModel::FM_TRANSIENT, 
            simOpt.targetGroup, 
            simOpt.peRow, 
            simOpt.peCol, 
            0, -1, false);
        
        else if(simOpt.faultModel == (int)FaultModel::FM_PERMANENT)
            mxm->gemmini->addPermanentFault(
                FaultModel::FM_PERMANENT, 
                simOpt.targetGroup, 
                simOpt.peRow, 
                simOpt.peCol, 0, 1, -1, false);
        else
        {
            printf("[Err]: invalid fault model\n");
            exit(0);
        }
    }

    MatUtils::loadRand<Input_t>(A1, DIM, DIM);
    MatUtils::loadRand<Input_t>(B1, DIM, DIM);
    MatUtils::loadRand<Output_t>(D1, DIM, DIM);

    MatUtils::matmul<Input_t,Output_t>(A1, B1, D1, Cgold, DIM, DIM, DIM, DIM);

#ifdef GEMM_OS
    itersPre = mxm->preload(D1);
    itersMul = mxm->stream(A1, B1, DIM);
    itersFlush = mxm->flush(C);
#else
    itersPre = mxm->preload(B1);
    itersMul = mxm->stream_bias(A1, D1, C, DIM);
#endif

    if (!MatUtils::compare<Output_t>(C, Cgold, DIM, DIM))
    {
        printf("Matmul mismatch due to FI:\n");
        MatUtils::debugPrint<Output_t>(Cgold, C, DIM, DIM);
        failures++;
    }

    mxm->gemmini->clearFaultList();
    delete mxm;
    return true; // FI makes it fail
}
