#include <torch/torch.h>
#include <iostream>
#include <vector>
#include <stdexcept>


/*
    Basic operations compiled Ahead-of-Time. 

    To use this, import this file such as in:

    aot_operations = cpp_extension.load(name='aot_operations',
    sources=['aot_operations.cpp'],  # List of source files
    verbose=True  # Prints detailed compilation output)

    Then use this, for example:
        A_tile = aot_operations.extract_tile(Abig, tile_a_rand_row, tile_a_rand_col, m, kA, DIM)
*/


torch::Dtype get_dtype_from_code(int dtype_code);
torch::Tensor sub_tile(torch::Tensor T, torch::Tensor x, int tile_row, int tile_col, int DIM);
torch::Tensor sum_tile(torch::Tensor T, torch::Tensor x, int tile_row, int tile_col, int DIM);
torch::Tensor extract_tile(const torch::Tensor& A, int tile_row, int tile_col, int m, int n, int DIM, int dtype_code);



/* this subtracts a tile x from the tensor T starting in the tile positions tile_row, tile_col */
torch::Tensor sub_tile(torch::Tensor T, torch::Tensor x, int tile_row, int tile_col, int DIM) {
    // Determine the start index in C
    int start_row = tile_row * DIM;
    int start_col = tile_col * DIM;

    bool quantized = T.is_quantized();
    torch::Tensor ret_tensor;

    if (quantized)
        ret_tensor = T.int_repr().clone().detach();
    else
        ret_tensor = T.clone().detach();

    // Calculate the effective size of the region that can be updated
    int max_row = std::min(DIM, static_cast<int>(ret_tensor.size(0)) - start_row);
    int max_col = std::min(DIM, static_cast<int>(ret_tensor.size(1)) - start_col);

    // Make sure the submatrix is within bounds
    if (max_row > 0 && max_col > 0) {

        // Slice the corresponding region of C
        auto C_submatrix = ret_tensor.index({torch::indexing::Slice(start_row, start_row + max_row),
                                    torch::indexing::Slice(start_col, start_col + max_col)});
        
        // Slice the corresponding region of C_tile
        auto C_tile_submatrix = x.index({torch::indexing::Slice(0, max_row),
                                              torch::indexing::Slice(0, max_col)});
        
        // Perform the subtraction operation on the submatrices
        C_submatrix.sub_(C_tile_submatrix);
    }

    // Reconstruct quantized tensor using _make_per_tensor_quantized_tensor
    if (quantized)
        return torch::_make_per_tensor_quantized_tensor(ret_tensor, T.q_scale(), T.q_zero_point());
    return ret_tensor;
}


/* this sums a tile x to the tensor T starting in the tile positions tile_row, tile_col */
torch::Tensor sum_tile(torch::Tensor T, torch::Tensor x, int tile_row, int tile_col, int DIM) {
    // Determine the start index in C
    int start_row = tile_row * DIM;
    int start_col = tile_col * DIM;

    bool quantized = T.is_quantized();
    torch::Tensor ret_tensor;

    if (quantized)
        ret_tensor = T.int_repr().clone().detach();
    else
        ret_tensor = T.clone().detach();

    // Calculate the effective size of the region that can be updated
    int max_row = std::min(DIM, static_cast<int>(ret_tensor.size(0)) - start_row);
    int max_col = std::min(DIM, static_cast<int>(ret_tensor.size(1)) - start_col);

    // Make sure the submatrix is within bounds
    if (max_row > 0 && max_col > 0) {

        // Slice the corresponding region of C
        auto C_submatrix = ret_tensor.index({torch::indexing::Slice(start_row, start_row + max_row),
                                    torch::indexing::Slice(start_col, start_col + max_col)});
        
        // Slice the corresponding region of C_tile
        auto C_tile_submatrix = x.index({torch::indexing::Slice(0, max_row),
                                              torch::indexing::Slice(0, max_col)});
        
        // Perform the subtraction operation on the submatrices
        C_submatrix.add_(C_tile_submatrix);
    }

    // Reconstruct quantized tensor using _make_per_tensor_quantized_tensor
    if (quantized)
        return torch::_make_per_tensor_quantized_tensor(ret_tensor, T.q_scale(), T.q_zero_point());
    return ret_tensor;
}


// Function to extract a random DIMxDIM tile from a matrix A, with zero padding if needed
torch::Tensor extract_tile(const torch::Tensor& A, int tile_row, int tile_col, int m, int n, int DIM, int dtype_code) {
    // Determine the starting row and column of the selected tile
    int start_row = tile_row * DIM;
    int start_col = tile_col * DIM;

    // i'm receiving m and n as parameters as we already computed them in python
    //m = static_cast<int>(A.size(0));
    //n = static_cast<int>(A.size(1));

    // Calculate the effective size of the region that can be copied from A
    int max_row = std::min(DIM, m - start_row); // max rows that can be copied
    int max_col = std::min(DIM, n - start_col); // max cols that can be copied

    //printf ("-> Start row/col = %d %d  Max row/col %d %d\n", start_row, start_col, max_row, max_col);

    // Create an empty tensor for the tile with zero padding (DIM x DIM)
    torch::Tensor tile = torch::zeros({DIM, DIM}, get_dtype_from_code(dtype_code)); 
    //torch::Tensor tile = torch::zeros({DIM, DIM}, torch::kInt8);

    // Check if the tile intersects A at all (optimization guard)
    if (max_row > 0 && max_col > 0) {
        // Slice the region from A to be copied
        torch::Tensor submatrix = A.index({torch::indexing::Slice(start_row, start_row + max_row),
                                           torch::indexing::Slice(start_col, start_col + max_col)});
        
        // Copy the valid part of the submatrix into the top-left corner of tile
        tile.index_put_({torch::indexing::Slice(0, max_row), torch::indexing::Slice(0, max_col)}, submatrix);
    }
    //else
        //std::cout<<"[Error]\n"; // never happens

    return tile;
}


at::Tensor concat_quantized_tensors(const std::vector<at::Tensor>& tensors) {
    if (tensors.empty()) throw std::invalid_argument("Tensor list is empty");

    auto first = tensors[0];
    auto qtype = first.scalar_type();
    auto scale = first.q_scale();
    auto zero_point = first.q_zero_point();
    auto device = first.device();

    for (const auto& t : tensors) {
        if (!t.is_quantized()) throw std::invalid_argument("All tensors must be quantized");
        if (t.scalar_type() != qtype || t.q_scale() != scale || t.q_zero_point() != zero_point)
            throw std::invalid_argument("All tensors must have same dtype, scale, and zero_point");
        for (size_t dim = 1; dim < t.dim(); ++dim) {
            if (t.size(dim) != first.size(dim))
                throw std::invalid_argument("All tensors must match in shape except dim=0");
        }
    }

    int64_t total_size = 0;
    for (const auto& t : tensors) total_size += t.size(0);

    std::vector<int64_t> new_shape;
    new_shape.push_back(total_size);
    new_shape.insert(new_shape.end(), first.sizes().begin() + 1, first.sizes().end());

    at::Tensor merged_int = torch::empty(
        new_shape,
        torch::TensorOptions().dtype(first.int_repr().dtype()).device(device)
    );

    int64_t offset = 0;
    for (const auto& t : tensors) {
        auto int_data = t.int_repr();
        int64_t n = int_data.size(0);
        merged_int.slice(0, offset, offset + n).copy_(int_data);
        offset += n;
    }

    return at::_make_per_tensor_quantized_tensor(merged_int, scale, zero_point);
}



#if 0
torch::Tensor add_tile_to_quantized(torch::Tensor T, torch::Tensor x, int tile_row, int tile_col, int DIM);
torch::Tensor sub_tile_from_quantized(torch::Tensor T, torch::Tensor x, int tile_row, int tile_col, int DIM);
torch::Tensor replace_row(torch::Tensor gold_tile, torch::Tensor fault_tile, int row){
torch::Tensor extract_tile(const torch::Tensor& A, int tile_row, int tile_col, int m, int n, int DIM, int dtype_code);
void sum_tile(torch::Tensor& C, const torch::Tensor& C_tile, int tile_row, int tile_col, int DIM);
void sub_tile(torch::Tensor& C, const torch::Tensor& C_tile, int tile_row, int tile_col, int DIM);
torch::Dtype get_dtype_from_code(int dtype_code);
#endif


/* this data types must be passed from python to extract_tile() */
torch::Dtype get_dtype_from_code(int dtype_code) {
    switch (dtype_code) {
        case 1: return torch::kInt8;
        case 2: return torch::kUInt8;
        case 3: return torch::kInt16;
        case 4: return torch::kInt32;
        case 5: return torch::kInt64;
        case 6: return torch::kFloat32;
        case 7: return torch::kFloat64;
        case 8: return torch::kDouble;
        default: throw std::invalid_argument("Unsupported data type code");
    }
}


/* returns a new tile 'new_tile' equal to gold_tile, but with new_tile[row] = fault_tile[row] */
torch::Tensor replace_row(torch::Tensor gold_tile, torch::Tensor fault_tile, int row){
    using namespace torch::indexing;

    // Check dimensions
    //TORCH_CHECK(gold_tile.sizes() == fault_tile.sizes(), "Tensors must have the same dimensions");
    //TORCH_CHECK(gold_tile.size(0) == DIM && gold_tile.size(1) == DIM, "Tensors must be square of dimension DIM");

    // Create a new tensor (clone to avoid modifying gold_tile)
    torch::Tensor new_tile = gold_tile.clone().detach();

    // Replace the specified row
    new_tile.index_put_({Slice(row, row + 1), Slice()}, fault_tile.index({Slice(row, row + 1), Slice()}));

    return new_tile;
}


#if 0 // other version
torch::Tensor replace_row(torch::Tensor gold_tile, torch::Tensor fault_tile, int row, int DIM) {
    // Check dimensions
    TORCH_CHECK(gold_tile.sizes() == fault_tile.sizes(), "Tensors must have the same dimensions");
    TORCH_CHECK(gold_tile.size(0) == DIM && gold_tile.size(1) == DIM, "Tensors must be square of dimension DIM");


    // torch::Tensor torch::Tensor::slice(int64_t dim, int64_t start, int64_t end, int64_t step = 1) const;
    // dim: The dimension along which to slice: 0 for rows, 1 for columns (like NumPy or PyTorch indexing)
    // Replace the specified row

    // copies the rows in the interval [row, row+1) - e.g., gold_tile.slice(0, start_row, end_row) -> end_row is exclusive
    gold_tile.slice(0, row, row + 1) = fault_tile.slice(0, row, row + 1);
    
    return gold_tile;
}

/* Examples using indexing:

    using namespace torch::indexing;  // Enable Slice and None shortcuts

    torch::Tensor tensor = torch::arange(1, 17).reshape({4, 4});
    std::cout << "Original Tensor:\n" << tensor << "\n";

    // Row slice (rows 1 to 2)
    torch::Tensor row_slice = tensor.index({Slice(1, 3), Slice()});
    std::cout << "Rows 1 to 2:\n" << row_slice << "\n";

    // Column slice (columns 1 to 2)
    torch::Tensor col_slice = tensor.index({Slice(), Slice(1, 3)});
    std::cout << "Columns 1 to 2:\n" << col_slice << "\n";

    // Slicing with steps (every other row)
    torch::Tensor step_slice = tensor.index({Slice(0, None, 2), Slice()});
    std::cout << "Every other row:\n" << step_slice << "\n"; */
#endif


torch::Tensor build_qt_tensor(torch::Tensor T) {  // used for debug only
    torch::Tensor ret_tensor = T.int_repr().clone().detach();
    return torch::_make_per_tensor_quantized_tensor(ret_tensor, T.q_scale(), T.q_zero_point());
}


#if 0 // debug only
torch::Tensor mm_opt(torch::Tensor& tensor1, const torch::Tensor& tensor2) 
{
#if 0
    // Check if CUDA is available and move tensors to GPU if possible
    if (torch::cuda::is_available()) 
    {
        tensor1 = tensor1.to(torch::kCUDA);
        tensor2 = tensor2.to(torch::kCUDA);
    }
    // Ensure the tensors have compatible sizes for element-wise multiplication
    if (tensor1.sizes() != tensor2.sizes()) {
        throw std::invalid_argument("Tensor sizes must match for element-wise multiplication.");
    }
#endif

    // Perform in-place multiplication to reduce memory usage
    //tensor1.mul_(tensor2);  // In-place element-wise multiplication
    //return tensor1;  // Return the modified tensor1 as result
    return torch::mm(tensor1, tensor2);
#if 0
    // Move result back to CPU if on CUDA
    if (tensor1.is_cuda()) {
        tensor1 = tensor1.to(torch::kCPU);
    }
#endif
}
#endif



// Register the function with PyTorch
PYBIND11_MODULE(TORCH_EXTENSION_NAME, m) {
    m.def("extract_tile", &extract_tile, "Custom C++ function extract_tile");
    m.def("sub_tile",     &sub_tile,     "Custom C++ function sub_tile");
    m.def("sum_tile",     &sum_tile,     "Custom C++ function sum_tile");


    m.def("replace_row",     &replace_row,     "Custom C++ function sum_tile");
    m.def("build_qt_tensor", &build_qt_tensor, "Custom C++ function sum_tile"); // debug only
    m.def("concat_quantized_tensors", &concat_quantized_tensors, "Custom C++ function sum_tile"); 


    //m.def("mm_opt",       &mm_opt,         "Custom C++ function sum_tile");
}

