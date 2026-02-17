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
from collections import defaultdict

import matplotlib.pyplot as plt
from matplotlib.ticker import MultipleLocator

# add the root path to to sys.path
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), "..")))

import src.gemmini.gemmini_config as conf
import src.gemmini.gemmini_interface as gemmini_interface


MIN_INT, MAX_INT = -128, 127
INPUT_TYPE  = conf.GEMM_INPUT_DTYPE
OUTPUT_TYPE = conf.GEMM_OUTPUT_DTYPE

# x and y are lists
def plot_one(
    x,  y, 
    x_label="Stream size", 
    y_label="Time", 
    legend="Legend",
    title="Mean stream time", 
    save_path="."):
    
    # Plot: one curve per h
    plt.figure(figsize=(7, 5))

    plt.xticks(fontsize=16)#, rotation=45
    plt.yticks(fontsize=16)#, rotation=45

    plt.plot(x, y, marker='o') #, label="label")
    plt.gca().xaxis.set_major_locator(MultipleLocator(1))

    plt.xticks(x)   # Force tick locations
    plt.grid(True)

    plt.ylabel(y_label, fontsize=18)
    plt.xlabel(x_label, fontsize=18)
    
    plt.title(f"{title}", fontsize=18)
    
    plt.legend([legend], fontsize=14)
    plt.tight_layout()
    plt.show()


def test_streamed_matmul(gemmini):
    if conf.GEMM_MODE != conf.MODE_OS:
        return

    stream_time = defaultdict()
    samples = 40000

    for stream_size in range(conf.DIM, 3*conf.DIM+1):        

        s = []

        A = torch.randint(MIN_INT, MAX_INT, torch.Size([conf.DIM, stream_size]), dtype=torch.int)
        B = torch.randint(MIN_INT, MAX_INT, torch.Size([stream_size, conf.DIM]), dtype=torch.int)
        C_gold = torch.mm(A, B)

        for _ in range(samples):
            start = time.time()
            C = gemmini.matmul(A, B)
            end = time.time()
            s.append(end-start)
        
            assert(torch.equal(C_gold, C))

        stream_time[stream_size] = statistics.mean(s)

    plot_one(
        x=list(stream_time.keys()), 
        y=list(stream_time.values()),
        legend = "Mean stream time (s)"
    )

    print(f"(test_streamed_matmul) Tensors match: {torch.equal(C_gold, C)}")


def test_tiled_matmul(gemmini):
    stream_size = conf.DIM + 4

    w_r, w_c = 64, 147
    i_r, i_c = w_c, 12544
    b_r, b_c = w_r, i_c

    W = torch.randint(MIN_INT, MAX_INT, torch.Size([w_r, w_c]), dtype=torch.int)
    I = torch.randint(MIN_INT, MAX_INT, torch.Size([i_r, i_c]), dtype=torch.int)
    bias = torch.randint(MIN_INT, MAX_INT, torch.Size([b_r, b_c]), dtype=torch.int)

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
            O = gemmini.tiled_matmul(A=W, B=I, D=bias, stream_size=stream_size)  # computes W*I + bias (which is what we want)

        # WS mode
        else: # In WS, we have to make the *weight* stationary, so we must feed the weights to the B pins in Gemmini, so we compute as follows:
            Ot = gemmini.tiled_matmul(A=It, B=Wt, D=biast) # computes Ot = It*Wt + biast => (It*Wt + biast)t = (It*Wt)t + (biast)t = W*I + bias (which is what we want)
            O = Ot.t()       

        time_samples.append(time.time() - start)

    mean_compute_time = statistics.mean(time_samples)

    O_ref = torch.mm(W, I)

    if bias != None: 
        O_ref += bias

    print(f"(test_tiled_matmul) Results match: {torch.equal(O, O_ref)}")


if __name__ == '__main__':
    # sweeps through all configs keys
    tested_configs = [
        "OSDIM4",
        "OSDIM8",
        "OSDIM16",
        "OSDIM32",
        "OSDIM64",
        "WSDIM4",
        "WSDIM8"
    ]

    for CONFIG_KEY in tested_configs:
        print(f"Testing with config: {CONFIG_KEY}")
        
        mode = conf.CONFIG_PARAMS[CONFIG_KEY]["mode"]

        if mode == conf.MODE_OS:
            gemmini = gemmini_interface.GemminiOS(CONFIG_KEY)

        elif mode == conf.MODE_WS:
            gemmini = gemmini_interface.GemminiWS(CONFIG_KEY)
        
        else:
            raise("Invalid Gemmini mode")

        test_streamed_matmul(gemmini)
        test_tiled_matmul(gemmini)

        gemmini.finish()