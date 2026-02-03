import torch.utils.cpp_extension as cpp_extension
import random
from src.gemmini import gemmini_config as conf

# The ahead-of-time extension to handle tensor operations
aot_operations = cpp_extension.load(name='aot_operations', sources=['src/conv/cpp/aot_operations.cpp'], verbose=False)

# Data type definitions used in the function 'aot_operations.extract_tile'. Must follow the values in 'aot_operations.get_dtype_from_code'
DType_kInt8    = 1
DType_kUInt8   = 2
DType_kInt16   = 3
DType_kInt32   = 4
DType_kInt64   = 5
DType_kFloat32 = 6
DType_kFloat64 = 7
DType_kDouble  = 8


# functions xxx_from_quantized work on quantized tensors. T is quantized, x is not!!
def sub_tile(T, x, tile_row, tile_col, tile_dim):
    return aot_operations.sub_tile(T, x, tile_row, tile_col, tile_dim)


def sum_tile(T, x, tile_row, tile_col, tile_dim):
    return aot_operations.sum_tile(T, x, tile_row, tile_col, tile_dim)


# extracts a tile from 'tensor' from the position [row][col]. the tile is of the same dimension as the systolic array (tile_dim). this is done as a C++ extension for better performance
def extract_tile(tensor, row, col, tile_dim): 
    return aot_operations.extract_tile(tensor, row, col, tensor.shape[0], tensor.shape[1], tile_dim, DType_kInt32).to(conf.GEMM_INPUT_DTYPE) # tensor.dtype


def extract_fp_tile(tensor, row, col, tile_dim): 
    return aot_operations.extract_tile(tensor, row, col, tensor.shape[0], tensor.shape[1], tile_dim, DType_kFloat32)


# returns a new tensor equal to tensor_1, but with tensor_1[row] = tensor_2[row]
def replace_row(tensor_1, tensor_2, row): 
    return aot_operations.replace_row(tensor_1, tensor_2, row) # tensor.dtype


def cat_tensors(tensor_list):
    return aot_operations.concat_quantized_tensors(tensor_list)

# returns a random tile position (considering tiles of size "tile_dim") in a tensor of shape [nrows][ncols]
def get_random_tile_position (nrows, ncols, tile_dim):
    num_tile_rows = (nrows + tile_dim - 1) // tile_dim  # ceil(m / DIM)
    num_tile_cols = (ncols + tile_dim - 1) // tile_dim

    tile_rand_row = random.randint(0, num_tile_rows - 1)
    tile_rand_col = random.randint(0, num_tile_cols - 1)

    return tile_rand_row, tile_rand_col


# return a random extracted tile from tensor
def extract_random_tile(tensor, tile_dim):
    m, n = tensor.shape
    # Calculate the number of tiles in rows and columns
    n_tile_rows = (m + tile_dim - 1) // tile_dim  # ceil(m / tile_dim)
    n_tile_cols = (n + tile_dim - 1) // tile_dim  # ceil(n / tile_dim)
    rand_row = random.randint(0, n_tile_rows - 1)
    rand_col = random.randint(0, n_tile_cols - 1)
    return extract_tile(tensor, rand_row, rand_col), rand_row, rand_col


# extracts a random tile from the position [row, a random column]
def extract_random_col_tile(tensor, row, tile_dim):
    n = tensor.shape[1]
    n_tile_cols = (n + tile_dim - 1) // tile_dim
    rand_col = random.randint(0, n_tile_cols - 1)
    return extract_tile(tensor, row, rand_col), row, rand_col


# extracts a random tile from the position [a random row, col]
def extract_random_row_tile(tensor, col, tile_dim):
    m = tensor.shape[0]
    n_tile_rows = (m + tile_dim - 1) // tile_dim  
    rand_row = random.randint(0, n_tile_rows - 1)
    return extract_tile(tensor, rand_row, col), rand_row, col
