#include <iostream>
#include <vector>
#include <time.h>
#include "headers/MxM.h"

using namespace std;

static bool test_case_1();
static bool test_case_2();
static bool test_case_3();
static bool test_case_4();
static bool test_performance();



/* Standard inputs the same size as the Gemmini grid */
Input_t A[DIM][DIM],  B[DIM][DIM];
Input_t A1[DIM][DIM], B1[DIM][DIM];
Input_t A2[DIM][DIM], B2[DIM][DIM];
Output_t A1B1[DIM][DIM], A2B2[DIM][DIM];

Output_t D[DIM][DIM];
Output_t Cgold[DIM][DIM]; // the golden matrix computed in sw for verification. SDCs are flagged when C != Cgold

/* Gemmini will store its outputs in the C matrix (for non-tiled MxM) */
Output_t C[DIM][DIM]; // the C output computed by the systolic array


int main (int argc, char** argv) 
{
    printf ("Testing with Gemmini %s\n", GEMM_CONFIG_ALIAS);

    simOpt = parseOptions (argc, argv);

#define TEST_CASES 4

    bool (*test_cases[])(void) = {test_case_1, test_case_2, test_case_3, test_case_4};

    bool passed[TEST_CASES] = {0, 0, 0, 0};
    uint32_t count_passed = 0;

    for(uint32_t i = 0; i < TEST_CASES; i++)
    {
        passed[i] = test_cases[i]();
        count_passed += passed[i];
    }

    for(uint32_t i = 0; i < TEST_CASES; i++)
    {
        if(passed[i])
            printf("Test %u: %sPassed\n", i, GREEN); 
        else
            printf("Test %u: %sFailed\n", i, RED);
        printf(RESET);
    }

    printf("Passed tests: %u\n", count_passed);

    return 0;
}


#ifdef GEMM_OS

static bool test_case_1()
{
    printf("Running test case: %s\n", __FUNCTION__);

    //MxM *mxm = MxM::getInstance(new Gemmini(new VL_DUT, GEMM_CONFIG_ALIAS));
    MxM *mxm = new MxM(new Gemmini(new VL_DUT, GEMM_CONFIG_ALIAS));
    //mxm->gemmini->addFaultToList(FaultModel::FM_TRANSIENT, IDX_io_in_a, simOpt.peRow, simOpt.peCol, 0, false);
    
    uint32_t itersPre;
    uint32_t itersMul;  
    uint32_t itersFlush;

    uint32_t failures = 0;

#define II 200

    for (uint32_t i = 0; i < II; i++)
    {
        MatUtils::loadRand<Input_t,DIM,DIM>(A);
        MatUtils::loadRand<Input_t,DIM,DIM>(B);
        MatUtils::loadRand<Output_t,DIM,DIM>(D);
        //bzero(D, sizeof(Input_t)*DIM*DIM);

        MatUtils::loadRand<Input_t,DIM,DIM>(A1);
        MatUtils::loadRand<Input_t,DIM,DIM>(B1);
        MatUtils::loadRand<Input_t,DIM,DIM>(A2);
        MatUtils::loadRand<Input_t,DIM,DIM>(B2);

        MatUtils::matmul<Input_t,Output_t,DIM,DIM,DIM>(A, B, D, Cgold);
        MatUtils::matmul<Input_t,Output_t,DIM,DIM,DIM>(A1, B1, A1B1);
        MatUtils::matmul<Input_t,Output_t,DIM,DIM,DIM>(A2, B2, A2B2); 

        MatUtils::accumulate<Output_t,DIM,DIM>(Cgold, A1B1);
        MatUtils::accumulate<Output_t,DIM,DIM>(Cgold, A2B2);

        itersPre = mxm->preload(D);
        itersMul = mxm->stream(A, B);
        itersMul = mxm->stream(A1, B1);
        itersMul = mxm->stream(A2, B2);
        itersFlush = mxm->flush(C);

        if (!MatUtils::compare<Output_t,DIM,DIM>(C, Cgold))
        {
            printf("Error: matmul mismatch\n");
            MatUtils::debugPrint<Output_t,DIM,DIM>(Cgold,C);
            failures++;
        }
    }

#if 0
    if(failures == 0)
        printf("(%s) MxM passed (%u tests)\n", __FUNCTION__, II);
    else
        printf("(%s) MxM failed with %u mismatches\n", __FUNCTION__, failures);
#endif

    mxm->gemmini->clearFaultList();
    delete mxm;
    return failures == 0;
}

#else //WS

static bool test_case_1()
{
    printf("Running test case: %s\n", __FUNCTION__);

    //MxM *mxm = MxM::getInstance(new Gemmini(new VL_DUT, GEMM_CONFIG_ALIAS));
    MxM *mxm = new MxM(new Gemmini(new VL_DUT, GEMM_CONFIG_ALIAS));
    //mxm->gemmini->addFaultToList(FaultModel::FM_TRANSIENT, IDX_io_in_a, simOpt.peRow, simOpt.peCol, 0, false);
    
    uint32_t itersPre;
    uint32_t itersMul;  
    uint32_t itersFlush;

    uint32_t failures = 0;

#define II 5
#define JJ II

    for (uint32_t i = 0; i < II; i++)
    {
        MatUtils::loadRand<Input_t,DIM,DIM>(B);
        itersPre = mxm->preload(B);

        for (uint32_t j = 0; j < JJ; j++)
        {    
            MatUtils::loadRand<Input_t,DIM,DIM>(A);
            MatUtils::loadRand<Output_t,DIM,DIM>(D);

            MatUtils::matmul<Input_t,Output_t,DIM,DIM,DIM>(A, B, D, Cgold);  
            itersMul = mxm->stream_bias(A, D, C);
            //itersMul = mxm->stream(A, C);
            
            if (!MatUtils::compare<Output_t,DIM,DIM>(C, Cgold))
            {
                printf("Error: matmul mismatch\n");
                MatUtils::debugPrint<Output_t,DIM,DIM>(Cgold,C);
                failures++;
            }
        }
    }

#if 0
    if(failures == 0)
        printf("(%s) MxM passed (%u tests)\n", __FUNCTION__, II*JJ);
    else
        printf("(%s) MxM failed with %u mismatches\n", __FUNCTION__, failures);
#endif
    mxm->gemmini->clearFaultList();
    delete mxm;
    return failures == 0;
}
#endif


#ifdef GEMM_OS

static bool test_case_2()
{
    printf("Running test case: %s\n", __FUNCTION__);
    MxM *mxm = new MxM(new Gemmini(new VL_DUT, GEMM_CONFIG_ALIAS));

    uint32_t itersPre;
    uint32_t itersMul;  
    uint32_t itersFlush;

    MatUtils::loadRand<Input_t,DIM,DIM>(A);
    MatUtils::loadRand<Input_t,DIM,DIM>(B);
    MatUtils::loadRand<Input_t,DIM,DIM>(D);

    MatUtils::matmul<Input_t,Output_t,DIM,DIM,DIM>(A, B, D, Cgold);
    //MatUtils::matmul<Input_t,Output_t,DIM,DIM,DIM>(A, B, Cgold);

    itersPre = mxm->preload(D);
    itersMul = mxm->stream(A, B);
    itersFlush = mxm->flush(C);

    if (!MatUtils::compare<Output_t,DIM,DIM>(C, Cgold))
    {
        printf("Error: matmul mismatch\n");
        MatUtils::debugPrint<Output_t,DIM,DIM>(Cgold,C);
        return false;
    }
    else
        return true;
}

#else // WS

static bool test_case_2()
{
    return true;
}
#endif

#ifdef GEMM_OS

static bool test_case_3() // OS only - this only tests preloads + flush only
{
    printf("Running test case: %s\n", __FUNCTION__);

    MxM *mxm = new MxM(new Gemmini(new VL_DUT, GEMM_CONFIG_ALIAS));

    uint32_t itersPre;
    uint32_t itersFlush;
    uint32_t failures = 0;

#define TRIALS 10

    for(int i = 0; i < TRIALS; i++)
    {
        MatUtils::loadRand<Input_t,DIM,DIM>(D);
        itersPre = mxm->preload(D);
        
        //printf("The D matrix:\n");
        //MatUtils::print<Input_t,DIM,DIM>(D);

        itersFlush = mxm->flush(C);
        //itersFlush = mxm->flush(C);

        if (!MatUtils::compare<Output_t,DIM,DIM>(D, C))
        {
            printf("Error: matmul mismatch\n");
            MatUtils::debugPrint<Output_t,DIM,DIM>(D, C);
            failures++;
        }
    }

    printf("Trials: %u  -  failures: %u\n", TRIALS, failures);
    return failures == 0;
}

#else // WS

static bool test_case_3() // OS only
{
    return true;
}

#endif

#ifdef GEMM_OS
static bool test_case_4()
{
    printf("Running test case: %s\n", __FUNCTION__);
    
    srand(time(NULL));

    MxM *mxm = new MxM(new Gemmini(new VL_DUT, GEMM_CONFIG_ALIAS));

    if(simOpt.faulty) 
    {
        if(simOpt.faultModel == (int)FaultModel::FM_TRANSIENT)
            mxm->gemmini->addFaultToList(FaultModel::FM_TRANSIENT, simOpt.targetGroup, simOpt.peRow, simOpt.peCol, 0, -1, false);  // IDX_io_in_a IDX_io_in_b IDX_io_out_c IDX_valid IDX_propagate
        
        else if(simOpt.faultModel == (int)FaultModel::FM_PERMANENT)
            mxm->gemmini->addFaultToList(FaultModel::FM_PERMANENT, IDX_io_in_b, simOpt.peRow, simOpt.peCol, 0, -1, 1, false);
        
        else
        {
            printf("[Err]: invalid fault model\n");
            exit(0);
        }
    }

    // disable this to test hdfit models
    //mxm->gemmini->addFaultToList(FaultModel::FM_TRANSIENT, IDX_io_in_a, simOpt.peRow, simOpt.peCol, 0, false); // IDX_io_out_c IDX_io_in_b

    uint32_t itersPre;
    uint32_t itersMul;  
    uint32_t itersFlush;

    for (int i = 0; i < 1; i++)
    {
        MatUtils::loadRand<Input_t,DIM,DIM>(A);
        MatUtils::loadRand<Input_t,DIM,DIM>(B);
        MatUtils::loadRand<Input_t,DIM,DIM>(D);

        MatUtils::matmul<Input_t,Output_t,DIM,DIM,DIM>(A, B, D, Cgold);
        //MatUtils::matmul<Input_t,Output_t,DIM,DIM,DIM>(A, B, Cgold);

        //MatUtils::print<Input_t,DIM,DIM>(A);
        //MatUtils::print<Input_t,DIM,DIM>(B);

        itersPre = mxm->preload(D);
        itersMul = mxm->stream(A, B);
        itersFlush = mxm->flush(C);

        if (!MatUtils::compare<Output_t,DIM,DIM>(C, Cgold))
        {
            printf("Error: matmul mismatch\n");
            MatUtils::debugPrint<Output_t,DIM,DIM>(Cgold,C);
            delete mxm;
            return false;
        }
    }
    delete mxm;
    return true;
}

#else
static bool test_case_4()
{
    MxM *mxm = new MxM(new Gemmini(new VL_DUT, GEMM_CONFIG_ALIAS));

    if(simOpt.faulty)
    {
        if(simOpt.faultModel == (int)FaultModel::FM_TRANSIENT)
            mxm->gemmini->addFaultToList(FaultModel::FM_TRANSIENT, simOpt.targetGroup, simOpt.peRow, simOpt.peCol, 0, -1, false);
        
        else if(simOpt.faultModel == (int)FaultModel::FM_PERMANENT)
            mxm->gemmini->addFaultToList(FaultModel::FM_PERMANENT, simOpt.targetGroup, simOpt.peRow, simOpt.peCol, 0, -1, false);

        else
        {
            printf("[Err]: invalid fault model\n");
            exit(0);
        }
    }

    uint32_t itersPre;
    uint32_t itersMul;  
    uint32_t itersFlush;

    MatUtils::loadRand<Input_t,DIM,DIM>(A);
    MatUtils::loadRand<Input_t,DIM,DIM>(B);
    MatUtils::loadRand<Input_t,DIM,DIM>(D);

    MatUtils::matmul<Input_t,Output_t,DIM,DIM,DIM>(A, B, D, Cgold);
    //MatUtils::matmul<Input_t,Output_t,DIM,DIM,DIM>(A, B, Cgold);

    itersPre = mxm->preload(B);
    itersMul = mxm->stream_bias(A, D, C);

    if (!MatUtils::compare<Output_t,DIM,DIM>(C, Cgold))
    {
        printf("Error: matmul mismatch\n");
        MatUtils::debugPrint<Output_t,DIM,DIM>(Cgold,C);
        return false;
    }
    else
        return true;
}
#endif


#ifdef GEMM_OS
static bool test_performance()
{   
    printf("Running test case: %s\n", __FUNCTION__);
    struct timespec start, end;

    struct timespec start_block, end_block;


    //MxM *mxm = MxM::getInstance(new Gemmini(new VL_DUT, GEMM_CONFIG_ALIAS));
    MxM *mxm = new MxM(new Gemmini(new VL_DUT, GEMM_CONFIG_ALIAS));
    //mxm->gemmini->addFaultToList(FaultModel::FM_TRANSIENT, IDX_io_in_a, simOpt.peRow, simOpt.peCol, 0, false);
    
    uint32_t itersPre = 0;
    uint32_t itersMul = 0;  
    uint32_t itersFlush = 0;

    uint32_t failures = 0;

#define SAMPLES 100

    float avg_time_preload[SAMPLES];
    float avg_time_compute[SAMPLES];
    float avg_time_flush[SAMPLES];

    uint32_t buff_sz = 0;

    double elapsed;

    // simulate tiled matmuls. here, A,B and D would be tiles from large matrices. C would be a tile output

    clock_gettime(CLOCK_MONOTONIC, &start);

    for (size_t s = 0; s < SAMPLES; s++)
    {
        /* Preload */
        clock_gettime(CLOCK_MONOTONIC, &start_block);
        itersPre += mxm->preload(D);
        clock_gettime(CLOCK_MONOTONIC, &end_block);

        elapsed = (end_block.tv_sec - start_block.tv_sec)* 1000000LL + (end_block.tv_nsec - start_block.tv_nsec) / 1000;
        avg_time_preload[buff_sz] = elapsed;
        
        /* Compute */
        clock_gettime(CLOCK_MONOTONIC, &start_block);
        itersMul += mxm->stream(A, B);
        clock_gettime(CLOCK_MONOTONIC, &end_block);

        elapsed = (end_block.tv_sec - start_block.tv_sec)* 1000000LL + (end_block.tv_nsec - start_block.tv_nsec) / 1000;
        avg_time_compute[buff_sz] = elapsed;
        
        /* Flush */
        clock_gettime(CLOCK_MONOTONIC, &start_block);
        itersFlush += mxm->flush(C);
        clock_gettime(CLOCK_MONOTONIC, &end_block);

        elapsed = (end_block.tv_sec - start_block.tv_sec)* 1000000LL + (end_block.tv_nsec - start_block.tv_nsec) / 1000;
        avg_time_flush[buff_sz] = elapsed;

        buff_sz++;
    }

    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

    // the time was measured in us
    float avg_preload = MatUtils::compute_avg(avg_time_preload, buff_sz);
    float avg_compute = MatUtils::compute_avg(avg_time_compute, buff_sz);
    float avg_flush   = MatUtils::compute_avg(avg_time_flush,   buff_sz);

    //printf("Finished after %u\t%u\t%u iterations (%.10f seconds)\n", itersPre, itersMul, itersFlush, elapsed);

    //printf("Finished with %d iteratons\n", buff_sz);

    printf("time pre/comp/flush (us): %f\t%f\t%f\n", avg_preload, avg_compute, avg_flush);
    printf("Total elapsed time (ms): %f\n", 1000*elapsed);
    return 1;
}


#endif // #ifdef GEMM_OS