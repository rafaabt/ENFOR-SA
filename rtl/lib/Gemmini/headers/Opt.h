#ifndef OPT__H
#define OPT__H

#include <getopt.h>
#include "FaultList.h"


typedef struct _SimOptions SimOptions;

#if 0 // SWIG has issues with these types
struct _SimOptions
{
    int32_t saveCycle   = -1;
    int32_t loadCycle   = -1;
    int32_t debugCycle  = -1;
    int32_t maxCycles   = 1;
    int32_t cpItvl      = -1;
    uint32_t trials     = 1;
    uint8_t targetGroup = 0;
    int8_t peRow        = -1;
    int8_t peCol        = -1;
    string input        = "\0";
    string dutAlias     = "\0";
    bool faulty  = false;
    bool dumpVcd = false;
};
#else // using only int types (SWIG)
struct _SimOptions
{
    int saveCycle   = -1;
    int loadCycle   = -1;
    int debugCycle  = -1;
    int maxCycles   = 1;
    int cpItvl      = -1;
    int trials      = 1;
    int targetGroup = 0;
    int targetBit   = 0;  // the targetBit and polarity for permantnt faults are read from the fault list, so it does not require an argument to be passed to set these for now.
    int polarity    = 0;
    int peRow       = 0;
    int peCol       = 0;
    int faultModel  = 0; // TODO: new. add this to the Python's option parser
    std::string input    = "\0";
    std::string dutAlias = "\0";
    bool faulty  = false;
    bool dumpVcd = false;
};
#endif

typedef struct _SimOptions SimOptions;

SimOptions simOpt;

static struct option long_options[] = 
{
    { "help",   no_argument,       0, 'h' }, // e.g., --help or -h
    { "fault",  required_argument, 0, 'f' }, // the possible fault models (FM_NO_FAULT for fault-free runs)
    { "save",   required_argument, 0, 's' }, // the cycle to save the DUTs context
    { "load",   required_argument, 0, 'l' }, // the cycle to restore the DUTs context from
    { "maxcy",  required_argument, 0, 'm' }, // the maximum number of cycles to simulate
    { "debug",  required_argument, 0, 'd' }, // a debug cycle form any debug purpose
    { "target", required_argument, 0, 'g' }, // the target fault group for fault injection
    { "input",  required_argument, 0, 'i' }, // an input file to restore the DUTs context from
    { "trials", required_argument, 0, 't' }, // the nunber of trials/fault injections in the faulty mode
    { "perow",  required_argument, 0, 'r' }, // the target PE row for fault injection
    { "pecol",  required_argument, 0, 'c' }, // the target PE col for fault injection
    { "vcd",    no_argument,       0, 'v' }, // dump the vcd trace
    { "dut",    required_argument, 0, 'u' }, // the alias for the design (if running multiple instances in parallel, pass a unique alias for each instance)
    { "cpi",    required_argument, 0, 'p' },  // checkpointing interval
    {0, 0, 0, 0 }
};


SimOptions parseOptions (int argc, char** argv);
void usage();

SimOptions parseOptions (int argc, char **argv)
{
    SimOptions opt;

    int nextOpt, long_index = 0;

    while ((nextOpt = getopt_long(argc, argv, "hs:l:f:m:d:t:i:r:g:r:c:vu:p:", long_options, &long_index )) != -1) 
    {
        switch (nextOpt) 
        {
            case 'h':
                usage();
                exit(0);

             case 's': 
                opt.saveCycle = atoi(optarg); 
                //printf("Context will be saved in cycle %lu\n", opt.saveCycle);
                break;

            case 'l': 
                opt.loadCycle = atoi(optarg); 
                //printf("Context will loaded from cycle %lu\n", opt.loadCycle);
                break;

            case 'f': 
                opt.faultModel = atoi(optarg);
                //printf("The fault model is %d\n", opt.faultModel);
                break;

            case 'm': 
                opt.maxCycles = atoi(optarg); 
                //printf("Max simulation cycles %lu\n", opt.maxCycles);
                break;

            case 'd': 
                opt.debugCycle = atoi(optarg); 
                //printf("Debug at cycle %lu\n", opt.debugCycle);
                break;

            case 'g': 
                opt.targetGroup = atoi(optarg); 
                //printf("The target group is %u\n", opt.targetGroup);
                break;

            case 'i':
                opt.input = optarg;
                //printf("The input starting context file is %s\n", opt.input.c_str());
                break;
            
            case 't': 
                opt.trials = atoi(optarg); 
                //printf("Trials: %d\n", opt.trials);
                break;
            
            case 'r': 
                opt.peRow = atoi(optarg); 
                //printf("The targert PE row is %d\n", opt.peRow);
                break;

            case 'c': 
                opt.peCol = atoi(optarg); 
                //printf("he targert PE col is %d\n", opt.peCol);
                break;

            case 'v':
                opt.dumpVcd = true;
            #if !VCD
                printf("Invalid option (-v): To use this option, call verilator with the '--trace' flag and define VCD 1 in conifg.h\n");
            #endif
                //printf("dumping vcd on\n");
                break;
            
            case 'u':
                opt.dutAlias = optarg;
                //printf("The DUT alias is %s\n", opt.dutAlias.c_str());
                break;
            case 'p':
                opt.cpItvl = atoi(optarg);
                //printf("The checkpoint itvl is %d\n", opt.cpItvl);
                break;
            default: 
                usage(); 
                exit(0);
        }
    }

    opt.faulty = static_cast<FaultModel>(opt.faultModel) != FaultModel::FM_NO_FAULT;
    return opt;
}


void usage()
{
    cout << "Usage: " << endl; // TODO
} 


#endif