#ifndef CONTEXT__H
#define CONTEXT__H

#include <memory>
//#include "ClusterOperator.h"
#include "config.h"
#include "Opt.h"
#include "utils.h"

#if VCD
    #include <verilated_vcd_c.h>
#endif

using namespace std;

class Context
{
public:
    Context (VL_DUT *tile, const char *configId)
    {
        //clusterOperator = new ClusterOperator (tile, configId);
        dut = tile;
        cycleCount = 0;
    }

    Context (VL_DUT *tile , const char *configId, bool faulty): Context(tile, configId)
    {    
    #if VCD
        Verilated::traceEverOn(true);

        if (simOpt.dumpVcd)
        {
            char fn[MAX_FN_SIZE];
            Verilated::traceEverOn(true); // Verilator must compute traced signals

            sprintf (fn, "output/vcd/%.50s/%.50s%.50s.vcd", CONFIG_NAME, configId, faulty ? "-faulty" : "");

            vcdTrace = new VerilatedVcdC;
            tile->trace(vcdTrace, 99);
            vcdTrace->open(fn);
        }
    #endif
    }

    ~Context ()
    {
        printfinish();
    #if VCD
        if (simOpt.dumpVcd)
            vcdTrace->close();
    #endif

        //if (clusterOperator != nullptr)
            //delete clusterOperator;
    }
    
    uint32_t step();


#if 0  // Old stuff. not used anymore

    template<class T> void set(uint8_t cluster, uint32_t row, uint8_t col, T val);
    template<class T> void set(uint8_t cluster, uint32_t row, T val);
    template<class T> T get(uint8_t cluster, uint32_t row);

    bool saveContext (uint64_t u64Cycle);
    bool saveContext (uint64_t u64Cycle, uint8_t cluster);
    bool saveContext (const char *fn);
    bool saveContext (const char *fn, uint8_t cluster);
    
    bool restoreContext (uint64_t u64Cycle);
    bool restoreContext (uint64_t u64Cycle, uint8_t cluster);
    bool restoreContext (const char *fn);
    bool restoreContext (const char *fn, uint8_t cluster);

    bool loadContext (string fn);

    int compareContext (uint64_t u64Cycle);
    int compareContext (uint64_t u64Cycle, uint8_t cluster);
    int compareContext (const char *fn);
    int compareContext (const char *fn, uint8_t cluster);

    int compareContext (const Context *that);
    int compareContext (const Context *that, uint8_t cluster);

    template <class T, size_t rows, size_t cols> void loadRow(uint8_t cluster, uint8_t row, const T matrix[rows][cols]);
    template <class T, size_t rows, size_t cols> void loadCol(uint8_t cluster, uint8_t col, const T matrix[rows][cols]);

    void reset();
    void updateBitFlips();
    void updateBitFlips (uint32_t fromElement, uint32_t toElement);

    void resetCluster (uint8_t cluster, uint32_t fromElement, uint32_t toElement);
    void resetCluster (uint8_t cluster);

    void setCluster (uint8_t cluster, uint32_t fromElement, uint32_t toElement);
    void setCluster (uint8_t cluster);
    void injectFault (uint8_t cluster);

    void scanForValue (uint32_t value, uint64_t u64Cycle)
    {
        clusterOperator->scanForValue(value, u64Cycle);
    }

    void scanForValue (uint8_t cluster, uint32_t value, uint64_t u64Cycle)
    {
        clusterOperator->scanForValue(cluster, value, u64Cycle);
    }

    bool operator == (const Context *that)
    {
        return compareContext(that) == STATUS_GOLDEN;
    }

    bool operator != (const Context *that)
    {
        return !(*this == that);
    }
#endif

    uint32_t cycleCount;
    VL_DUT *dut;
    //ClusterOperator *clusterOperator = nullptr;

#if VCD
    VerilatedVcdC *vcdTrace;
#endif
};


/* 
    Simulates a cycle. Calls a falling edge followed by a rising edge.
    This is what effectively performs passes over the verilated design 
*/

uint32_t Context::step ()
{
#ifdef CLK // note, CLK is defined in config.h

    /* Falling edge */
    dut->CLK = 0; 
    dut->eval();

#if VCD
    if (simOpt.dumpVcd)
        vcdTrace->dump(static_cast<vluint64_t>(cycleCount * 2));
#endif

    /* Rising edge */
    dut->CLK = 1;
    dut->eval();

#if VCD
    if (simOpt.dumpVcd)
    {
        vcdTrace->dump(static_cast<vluint64_t>(cycleCount * 2 + 1));
        vcdTrace->flush();
    }
#endif

#else // no clock. e.g., purely combinatorial circuits
    dut->eval();
#endif
    return cycleCount++;
}





#if 0 // Old stuff. not used anymore

template<class T> 
void Context::set(uint8_t cluster, uint32_t row, uint8_t col, T val)
{
    clusterOperator->set<T>(cluster, row, col, val);
}

template<class T> 
void Context::set(uint8_t cluster, uint32_t row, T val)
{
    clusterOperator->set<T>(cluster, row, 0, val);
}

template<class T> 
T Context::get(uint8_t cluster, uint32_t row)
{
    return clusterOperator->get<T>(cluster, row);
}

void Context::injectFault (uint8_t cluster)
{
    WrapperGl::glnbits = 0;  // zerar esta global em wrapper.h antes de alocar os regs.
 
    clusterOperator->allocCluster(cluster); 
    uint32_t rdRegisterClusterTargetLine = 0;

    uint64_t randomBit = rand()%WrapperGl::glnbits;   // Gera um bit aleatório entre 0 e o total de bits em registerCluster
    
    for (uint32_t j = 0 ; j < clusterOperator->clusterSize ; j++)   // Procura índice do elemento em registerCluster correspondente ao bit sorteado.
    {
        if (randomBit >= clusterOperator->cLoader->registerCluster[j]->start && randomBit <= clusterOperator->cLoader->registerCluster[j]->end)
        {
            rdRegisterClusterTargetLine = j;
            break;
        }
    }

    //printf ("Fault injection in %s at cycle %lu\n", STRUCTURE_ALIAS[cluster], u64FaulCycle);
    clusterOperator->injectFault (rdRegisterClusterTargetLine);    
    clusterOperator->freeCluster ();
}


template <class T, size_t M, size_t N>
void Context::loadRow(uint8_t cluster, uint8_t row, const T matrix[M][N])
{
    clusterOperator->loadRow<T, M, N>(cluster, row, matrix);
}

template <class T, size_t M, size_t N>
void Context::loadCol(uint8_t cluster, uint8_t col, const T matrix[M][N])
{
    clusterOperator->loadCol<T, M, N>(cluster, col, matrix);
}

bool Context::saveContext (uint64_t u64Cycle)
{
    return clusterOperator->saveRegistersContext(u64Cycle);
}

bool Context::saveContext (uint64_t u64Cycle, uint8_t cluster)
{
    return clusterOperator->saveRegistersContext(u64Cycle, cluster);
}

bool Context::saveContext (const char *fn)
{
    return clusterOperator->saveRegistersContext(fn);
}

bool Context::saveContext (const char *fn, uint8_t cluster)
{
    return clusterOperator->saveRegistersContext(fn, cluster);
}

bool Context::restoreContext (uint64_t u64Cycle)
{
    return clusterOperator->restoreRegistersContext(u64Cycle);
}

bool Context::restoreContext (uint64_t u64Cycle, uint8_t cluster)
{
    return clusterOperator->restoreRegistersContext(u64Cycle, cluster);
}
bool Context::restoreContext (const char *fn)
{
    return clusterOperator->restoreRegistersContext(fn);
}

bool Context::restoreContext (const char *fn, uint8_t cluster)
{
    return clusterOperator->restoreRegistersContext(fn, cluster);
}

bool Context::loadContext (string fn)
{
    return clusterOperator->restoreRegistersContext(fn.c_str());
}

int Context::compareContext (uint64_t u64Cycle)
{
    return clusterOperator->compareRegistersContext(u64Cycle);
}

int Context::compareContext (uint64_t u64Cycle, uint8_t cluster)
{
    return clusterOperator->compareRegistersContext(u64Cycle, cluster);
}

int Context::compareContext (const char *fn)
{
    return clusterOperator->compareRegistersContext(fn);
}

int Context::compareContext (const char *fn, uint8_t cluster)
{
    return clusterOperator->compareRegistersContext(fn, cluster);
}

int Context::compareContext (const Context *that)
{
    return clusterOperator->compareRegistersContext(that->clusterOperator);
}

int Context::compareContext (const Context *that, uint8_t cluster)
{
    return clusterOperator->compareRegistersContext(that->clusterOperator, cluster);
}


/* 
    Incrementa a qtd. de bit flips desde o último ciclo (incrementando WrapperGl::totalBitFlips 
    
    Atenção: Como o método updateBitFlips é executado todo ciclo, não é razoável alocar o cluster a cada ciclo. Por isto,
    para usar esta função, deve-se alocar o  cluster antes de iniciar a execução, e executar, e desalocar quando a execução termina.
*/

void Context::updateBitFlips()
{
    clusterOperator->updateBitFlips();
}

void Context::updateBitFlips (uint32_t fromElement, uint32_t toElement)  // atualiza bit flips somente em um itvl. específico de registradores
{
    clusterOperator->updateBitFlips  (fromElement, toElement);
}

/*
    Para todos os métodos abaixo: não deve-se alocar os cluster externamente. O cLoader->registerCluster[] deve estar vazio antes de chamar estes métodos
*/

/* Reseta todos os registradores (não deve-se alocar nenhum cluster antes de usar este método) */
void Context::reset()
{
    clusterOperator->resetRegisters();
}

/* 
    Métodos abaixo preenchem um cluster (ou parte dele [from, to]) com padrões de '0' ou '1'.
*/

void Context::resetCluster (uint8_t cluster)  // Reseta cluster específico 
{
    clusterOperator->resetCluster (cluster);
}

/* Preenche todos os registradores de cluster com 111...1 */
void Context::setCluster (uint8_t cluster)
{
    clusterOperator->setCluster(cluster);
}

/* Reseta os elementos entre 'fromElement' e 'toElement' de cluster específico */
void Context::resetCluster (uint8_t cluster, uint32_t fromElement, uint32_t toElement)
{   
    clusterOperator->resetCluster (cluster, fromElement, toElement);
}

void Context::setCluster (uint8_t cluster, uint32_t fromElement, uint32_t toElement)
{
    clusterOperator->setCluster(cluster, fromElement, toElement);
}
#endif

#endif  // CONTEXT__H