import torch
import math
import numpy as np
import time
import random 
import pandas as pd
import operator
from typing import Optional
from typing import Union
import matplotlib.pyplot as plt


C = {
    "red": "\033[91m",
    "green": "\033[92m",
    "yellow": "\033[93m",
    "blue": "\033[94m",
    "magenta": "\033[95m",
    "cyan": "\033[96m",
    "reset": "\033[0m",
}


# see all color indexes in https://www.ditig.com/256-colors-cheat-sheet#google_vignette
Co = {
    "fg": {i: f"\033[38;5;{i}m" for i in range(256)},  # Text color
    "bg": {i: f"\033[48;5;{i}m" for i in range(256)},  # Background color
}

R="\033[0m"  # Reset to default


EQ, NE, LT, LE, GT, GE = operator.eq, operator.ne, operator.lt, operator.le, operator.gt, operator.ge
ANY, NONE, ITVL = 'any', 'none', 'interval'


def filter_csv(in_fn: str, output_fn: str=None, filters: Optional[dict]=None, sep='\t'):
    df = pd.read_csv(in_fn, comment='#', sep=sep)

    if filters is None:
        #print(f"Returning filtered dataframe with {len(df)} rows")
        return df

    mask = pd.Series([True] * len(df))

    for col, val in filters.items():
        if isinstance(val, tuple): # if the val is a tuple, the first item in the tuple is the operation, the second is the value constraint
            op, constr = val
            if isinstance(constr, list): # case 1: if the value constraint is a list
                assert op in [ANY, NONE]
                microcond = df[col].isin(constr)
                if op == NONE:
                    microcond = ~microcond
                mask &= microcond

            elif isinstance(constr, tuple): # case 2: if the value contraint is a tuple - this is treated as an interval. df rows outside the itvl are filtered out
                assert op == ITVL
                mask &= (df[col] >= constr[0]) & (df[col] <= constr[1])

            else: # case 3: if the value contraint is a single value
                assert op in [EQ, NE, LT, LE, GT, GE]
                mask &= op(df[col], constr)
        else: # case 4: if the value is not a tuple, but a single value (e.g., 'a': 3) (for simpler syntax)
            mask &= df[col] == val

    filtered_df = df[mask]

    # dumps the filtered csv to other output
    if not output_fn is None:
        print(f"Writing filtered data ({len(filtered_df)} rows) to file: {output_fn}")
        filtered_df.to_csv(output_fn, sep='\t', index=False)

    #print(f"Returning filtered dataframe with {len(filtered_df)} rows")
    return filtered_df

    
def register_sig_handlers():
    import signal
    import sys

    def handle_sigint(signum, frame):
        #print("\n[!] Caught SIGINT (Ctrl+C). Running cleanup callback...")
        time.sleep(1)
        sys.exit(130)  # Exit code 130 = interrupted by SIGINT
    """
    def handle_sigterm(signum, frame):
        time.sleep(1)
        sys.exit(4242)  # Exit code 130 = interrupted by SIGINT

    def handle_sigquit(signum, frame):
        time.sleep(1)
        sys.exit(2424)  # Exit code 130 = interrupted by SIGINT
    """
    # Register the callback for SIGINT
    signal.signal(signal.SIGINT,  handle_sigint)
    #signal.signal(signal.SIGTERM, handle_sigterm)
    #signal.signal(signal.SIGQUIT, handle_sigquit)


class Timer:
    time_measure = 0

    def tic(self): self.time_measure = time.time()
    def toc(self): self.time_measure = time.time() - self.time_measure

    @property
    def diff_time(self): return self.time_measure

    @property
    def diff_time_str(self): return str(self)

    def __str__(self): return f"{1000*self.time_measure:.4f}\tms"
    def __repr__(self): return str(self)


def equal(lhs: torch.Tensor, rhs: torch.Tensor, threshold: Union[None, float]) -> bool:
    """ Compare based or not in a threshold, if the threshold is none then it is equal comparison    """
    if threshold != 0:
        return bool(
            torch.all(
                torch.le(
                    torch.abs(
                        torch.subtract(rhs, lhs)
                    ), threshold
                )
            )
        )
    else:
        return bool(torch.equal(rhs, lhs))


# returns a batch of input indexes in the valid dataset range
def random_indices(size, max):
    indices = []
    for i in range(size):
        indices.append(random.randint(0, max))
    return indices


def dump_tensor_heatmap(tensor, out_fn=None):
    #return

    # Choose a feature map to visualize (first channel)
    #fm_idx = 0  # Change this index to visualize other channels

    plt.figure(figsize=(10, 5))

    # if tensor is a PyTorch tensor
    #plt.imshow(tensor.cpu().numpy(), cmap='coolwarm')

    # if tensor is a numpy tensor
    plt.imshow(tensor, cmap='coolwarm')

    plt.colorbar()

    #title = f"Feature Map {ch} - Golden" if golden else f"Feature Map {ch} - Faulty"
    #plt.title(title)
    plt.title(out_fn)

    plt.axis("off")
    plt.show()
    
    if out_fn: plt.savefig(out_fn)
    plt.close()
  

def save_tensor(tensor, layer_id, input_id, ch, model="ResNet18", golden=True):
    #fn = f"debug_ofm/ResNet18/tensors/golden/{layer_id}-{input_id}-{ch}.g.ten" if golden else f"debug_ofm/ResNet18/tensors/faulty/{layer_id}-{input_id}-{ch}.f.ten"

    path = f"debug_ofm/{model}/tensors/golden" if golden else f"debug_ofm/{model}/tensors/faulty"
    fn = f"{path}/{layer_id}-{input_id}-{ch}.ten"    
    torch.save(tensor, fn)


def save_tensor_batch(tensor_batch, layer_id, batch_input_ids, model="ResNet18", golden=True):
    channels = tensor_batch[0].shape[0], 
    #channels = tensor_batch.shape[1] or...

    for i, ten in  enumerate(tensor_batch):
        for ch in range(channels):
            save_tensor(ten[ch].int_repr(), layer_id, batch_input_ids[i], ch, model=model, golden=golden)


def print_tensor_to_file (tensor: torch.Tensor, fn: str):
    # Open a file and write each element
    with open(fn, "w") as f:
        for row in tensor:
            for elem in row:
                f.write(f"{elem:.5f}\n")  # Format with 5 decimal places
            #f.write("\n")  # New line after each row


# sobel stuff:
def np_img_to_tensor(img):
    if len(img.shape) == 2:
        img = img[..., np.newaxis]
    img_tensor = torch.from_numpy(img)
    
    # for rgb images
    img_tensor = img_tensor.permute(2, 0, 1)
    img_tensor = torch.unsqueeze(img_tensor, 0)
    
    #input_scale = 1
    #input_zero_point = 0
    #img_tensor = torch.quantize_per_tensor(img_tensor, scale=input_scale, zero_point=input_zero_point, dtype=torch.quint8)

    return img_tensor


def tensor_to_np_img(img_tensor):
    img = img_tensor.cpu().permute(0, 2, 3, 1).numpy()
    return img[0, ...]  # get the first element since it's batch form


def show_img(torch_img):
    img_numpy = tensor_to_np_img(torch_img)
    plt.imshow(img_numpy, cmap='gray')
    plt.title("Tensor Image")
    plt.axis('off')
    plt.show()










