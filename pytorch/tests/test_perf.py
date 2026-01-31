#
# Gemmini *host* performance tests
#
import sys
import os
import time
import torch
import statistics
import torch.nn.functional as F
from tabulate import tabulate

# add the root path to to sys.path
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), "..")))

import src.gemmini.gemmini_config as conf
import src.gemmini.gemmini_interface as gemmini_interface


#
# gemmini: the (global) main (and only) Gemmini handler. Access to Gemmini can only be done through this interface
#
gemmini: gemmini_interface.Gemmini=None

MIN_INT, MAX_INT = -128, 127
INPUT_TYPE  = conf.GEMM_INPUT_DTYPE
OUTPUT_TYPE = conf.GEMM_OUTPUT_DTYPE


def perf_measure_resnet50_first_layer():
    # ResNet50: shape of the first conv layer
    #shape_layer = (torch.Size([64, 147]), torch.Size([147, 12544]))

    print("Estimating ResNet50 (first) layer times...")
    W = torch.randint(MIN_INT, MAX_INT, torch.Size([64, 147]),    dtype=torch.int)
    I = torch.randint(MIN_INT, MAX_INT, torch.Size([147, 12544]), dtype=torch.int)
    bias = torch.randint(MIN_INT, MAX_INT, torch.Size([64, 12544]), dtype=torch.int)

    if conf.GEMM_MODE == conf.MODE_WS:
        Wt = W.t().contiguous() # very important: all tensors sent to Gemmini must be contiguous
        It = I.t().contiguous() # tranpose operations may result in non-contiguous tensors!!!
        biast =  bias.t().contiguous()

    time_samples = []
    nsamples = 1

    for _ in range(nsamples):
        start = time.time()
        
        # OS mode
        if conf.GEMM_MODE == conf.MODE_OS:
            O = gemmini.tiled_matmul(A=W, B=I, D=bias)  # computes W*I + bias (which is what we want)

        # WS mode
        else: # In WS, we have to make the *weight* stationary, so we must feed the weights to the B pins in Gemmini, so we compute as follows:
            Ot = gemmini.tiled_matmul(A=It, B=Wt, D=biast) # computes Ot = It*Wt + biast => (It*Wt + biast)t = (It*Wt)t + (biast)t = W*I + bias (which is what we want)
            O = Ot.t()       

        time_samples.append(time.time() - start)

    mean_compute_time = statistics.mean(time_samples)

    O_ref = torch.mm(W, I)

    if bias != None: 
        O_ref += bias

    print(f"Results match: {torch.equal(O, O_ref)}")
    print(f"{CONFIG_KEY}: mean compute time: {mean_compute_time}\n")


def measure_verilated_tick_time():
    print("Estimating tick times...")
    M = 1000*1000
    SIM_CYCLES = 1*M

    start = time.time()
    gemmini.device.tick_test_perf(SIM_CYCLES)
    delta_time = (time.time() - start)
    usec_per_cyc = M*delta_time/SIM_CYCLES
    print(f"Time taken: {delta_time}\t\u03BCs per cycle:\t{usec_per_cyc}")


def measure_matmul_rtl_performance():
    if conf.GEMM_MODE != conf.MODE_OS:
        return
    
    print("Estimating matmul times...")
    M = 1000*1000

    cycles_preload, cycles_compute, cycles_flush = 0, 0, 0

    delta_time_samp_preload = []
    delta_time_samp_compute = []
    delta_time_samp_flush = []

    A = torch.randint(MIN_INT, MAX_INT, (conf.DIM, conf.DIM), dtype=INPUT_TYPE)
    B = torch.randint(MIN_INT, MAX_INT, (conf.DIM, conf.DIM), dtype=INPUT_TYPE)
    D = torch.randint(MIN_INT, MAX_INT, (conf.DIM, conf.DIM), dtype=OUTPUT_TYPE)
    C = torch.randint(MIN_INT, MAX_INT, (conf.DIM, conf.DIM), dtype=OUTPUT_TYPE)

    SAMPLES=100
    
    start_full_time = time.time()

    for s in range(SAMPLES):        
        start_p = time.time()
        cycles_preload += gemmini.preload(D)
        delta_time_samp_preload.append((time.time() - start_p))
        
        start_c = time.time()
        cycles_compute += gemmini.stream(A, B)
        delta_time_samp_compute.append((time.time() - start_c))
        
        start_f = time.time()
        cycles_flush += gemmini.flush_gemm(C, False) 
        delta_time_samp_flush.append((time.time() - start_f))

    delta_full_time = (time.time() - start_full_time)

    avg_time_preload = statistics.mean(delta_time_samp_preload)*M
    avg_time_compute = statistics.mean(delta_time_samp_compute)*M
    avg_time_flush   = statistics.mean(delta_time_samp_flush)*M

    table = [["Preload (mean)", avg_time_preload], 
             ["Compute (mean)", avg_time_compute], 
             ["Flush (mean)",   avg_time_flush]]

    print(tabulate(table, headers=["SA phase", "Time (us)"]))
    print(f"Time total (s): {delta_full_time}")
    print()


if __name__ == '__main__':
    # sweeps through all configs keys
    for CONFIG_KEY in conf.CONFIG_PARAMS.keys():
        print(f"Testing with config: {CONFIG_KEY}")
        
        mode = conf.CONFIG_PARAMS[CONFIG_KEY]["mode"]

        if mode == conf.MODE_OS:
            gemmini = gemmini_interface.GemminiOS(CONFIG_KEY)

        elif mode == conf.MODE_WS:
            gemmini = gemmini_interface.GemminiWS(CONFIG_KEY)
        
        else:
            raise("Invalid Gemmini mode")

        perf_measure_resnet50_first_layer()
        measure_matmul_rtl_performance()
        measure_verilated_tick_time()

        gemmini.finish()
