#ifndef MAT_UTILS__H
#define MAT_UTILS__H

#include "config.h"
#include "utils.h" // DIM

typedef int8_t elem_t;
static const elem_t elem_t_max = 127;
static const elem_t elem_t_min = -128;
typedef int32_t acc_t;
typedef int64_t full_t;

typedef float acc_scale_t;
typedef uint32_t acc_scale_t_bits;


#ifdef __cplusplus
#define SAME_TYPE(x) decltype(x)
#else
#define SAME_TYPE(x) typeof(x)
#endif

#define ROUND_NEAR_EVEN(x) \
    ({ const SAME_TYPE(x) x_ = (x); \
         const long long i = x_; \
         const long long next = x_ < 0 ? x_ - 1 : x_ + 1; \
         SAME_TYPE(x) rem = x_ - i; \
         rem = rem < 0 ? -rem : rem; \
         SAME_TYPE(x) result = rem < 0.5 ? i : (rem > 0.5 ? next : ( \
                     i % 2 == 0 ? i : next)); \
         result; })

#define ACC_SCALE(x, scale) \
    ({float y = ROUND_NEAR_EVEN((x) * (scale)); y > INT8_MAX ? INT8_MAX : (y < INT8_MIN ? INT8_MIN : (acc_t)y);})

// Rounding right shift equation: https://riscv.github.io/documents/riscv-v-spec/#_vector_fixed_point_rounding_mode_register_vxrm
#define ROUNDING_RIGHT_SHIFT(x, shift) \
    ((shift) > 0 ? (((x) >> (shift)) + \
        (((shift) == 0 ? 0 : (((x) >> ((shift)-1)) & 1)) & \
             ((((shift) <= 1 ? 0 : ((x) & ((1 << ((shift)-1)) - 1))) != 0) | (((x) >> (shift)) & 1)))) : ((x) << (-(shift))))


namespace MatUtils
{
template <class InType, class OutType>
static void matscale(InType full[DIM][DIM], OutType out[DIM][DIM], acc_scale_t scale) 
{
    for (size_t r = 0; r < DIM; r++)
        for (size_t c = 0; c < DIM; c++) 
        {
            // Bitshift and round element
            full_t scaled = ACC_SCALE(full[r][c], scale);

            // Saturate and cast element
            #ifndef ELEM_T_IS_FLOAT
                InType elem = scaled > elem_t_max ? elem_t_max : (scaled < elem_t_min ? elem_t_min : scaled);
                out[r][c] = elem;
            #else
                out[r][c] = scaled; // TODO should we also saturate when using floats?
            #endif
        }
}

template <class T, size_t M, size_t N>
static void matshift(T full[M][N], T out[M][N], int shift)   // matshift(IData full[DIM][DIM], IData out[DIM][DIM], int shift)
{
    for (size_t r = 0; r < M; r++)
    {
        for (size_t c = 0; c < N; c++) 
        {
            // Bitshift and round element
            T shifted = ROUNDING_RIGHT_SHIFT(full[r][c], shift);

        // Saturate and cast element
        #ifndef ELEM_T_IS_FLOAT
            T elem = shifted > elem_t_max ? elem_t_max : (shifted < elem_t_min ? elem_t_min : shifted);
            out[r][c] = elem;
        #else
            out[r][c] = shifted; // TODO should we also saturate when using floats?
        #endif
        }
    }
}


template <class T, size_t M, size_t N>
static void scale(T a[M][N], float scale)
{
    for (size_t i = 0; i < M; i++) 
        for (size_t j = 0; j < N; j++) 
            a[i][j] =  a[i][j]*scale;
}

/*
paddRowsWithZeros: 

Receives an input matrix, e.g.,:

1  2  3  4
5  6  7  8
9  10 11 12
13 14 15 16

Returns a padded matrix with zeros, e.g.,:

1  2  3  4  0  0  0
0  5  6  7  8  0  0 
0  0  9  10 11 12 0
0  0  0  13 14 15 16

Example for DIM4:

Setting the Mesh input:
    for(uint8_t r = 0; r < DIM; r++)
    {
        *mesh->ptr_mesh_in_a[r] = inputA[r][it];
        *mesh->ptr_mesh_in_b[r] = inputB[r][it];
    }

it 0:
    ptr_mesh_in_a[0] = 1
    ptr_mesh_in_a[1] = 0
    ptr_mesh_in_a[2] = 0
    ptr_mesh_in_a[3] = 0

it 1:
    ptr_mesh_in_a[0] = 2
    ptr_mesh_in_a[1] = 5
    ptr_mesh_in_a[2] = 0
    ptr_mesh_in_a[3] = 0

it 2:
    ptr_mesh_in_a[0] = 3
    ptr_mesh_in_a[1] = 6
    ptr_mesh_in_a[2] = 9
    ptr_mesh_in_a[3] = 0

...


This is used to simulate a systolic shiffted inputs by reading one col at time

1
2 5
3 6 9
4 7 10 13


if (it < PDIM)
    for(uint8_t r = 0; r < DIM; r++)
    {
        *mesh->ptr_mesh_in_a[r] = inputA[r][it];
        *mesh->ptr_mesh_in_d[r] = inputD[r][it];
    }

*/


template <class T>
void transpose(const T *in, T *out, uint16_t rows, uint16_t cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            out[j * rows + i] = in[i * cols + j];
        }
    }
}


template <class T>
void paddRowsWithZeros(T *out, const T *in, uint16_t in_cols)
{
    uint16_t out_cols = 2*in_cols - 1;

    for (size_t i = 0; i < DIM * out_cols; i++)
        out[i] = 0;

    for (size_t i = 0; i < DIM; i++)
    {
        for (size_t j = 0; j < in_cols; j++)
        {
            out[i * out_cols + j + i] = in[i * in_cols + j];
        }
    }
}


template <class T>
void paddRowsWithZerosTransp(T *out, const T *in, uint16_t in_cols)
{
    uint16_t out_cols = 2*in_cols - 1;

    for (size_t i = 0; i < DIM * out_cols; i++)
        out[i] = 0;

    for (size_t i = 0; i < DIM; i++)
    {
        for (size_t j = 0; j < in_cols; j++)
            out[i * out_cols + j + i] = in[j * DIM + i];
    }
}


template <class T>
static bool compare(T *a, T *b, uint16_t rows, uint16_t cols) 
{
    T* pa = a;
    T* pb = b;

    for (size_t k = 0; k < rows*cols; k++)
        if (*pa++ != *pb++)
            return false;

    return true;
}


template <class T>
static void accumulate(T *a, const T *b, uint16_t a_rows, uint16_t b_cols) 
{
    for (size_t i = 0; i < a_rows; i++) 
        for (size_t j = 0; j < b_cols; j++) 
            a[i*b_cols + j] += b[i*b_cols + j];
}


template <class T>
static void print(const T *in, uint16_t rows, uint16_t cols)
{
    for (size_t i = 0; i < rows; i++) 
    {
        for (size_t j = 0; j < cols; j++) 
            printf ("%d ", in[i*cols +j]);
        printf("\n");
    }
    printf("\n");
}


template <class T>
static void debugPrint(const T *gold, const T *a, uint16_t rows, uint16_t cols)
{
    for (size_t i = 0; i < rows; i++) 
    {
        for (size_t j = 0; j < cols; j++) 
            ffprintf (stdout, gold[i*cols + j]);

        printf (" | ");

        for (size_t j = 0; j < cols; j++) 
        {
            printf ("%s", a[i*cols + j] != gold[i*cols + j] ? RED : RESET); 
            ffprintf (stdout, a[i*cols + j]);
            printf ("%s", RESET); 
        }
        printf("\n");
    }
    cout << endl;
}


int random_int(int min, int max)
{
    return min + rand() % (max - min + 1);
}


template <class T>
static void loadRand(T *a, uint16_t rows, uint16_t cols)
{
    for (size_t i = 0; i < rows; i++) 
        for (size_t j = 0; j < cols; j++) 
            a[i*cols + j] = random_int(elem_t_min, elem_t_max);
}


template <class T>
static void loadZeros(T *a, uint16_t rows, uint16_t cols)
{
    for (size_t i = 0; i < rows; i++) 
        for (size_t j = 0; j < cols; j++) 
            a[i*cols + j] = 0;
}


template <class T>
static void loadOnes(T *a, uint16_t rows, uint16_t cols)
{
    for (size_t i = 0; i < rows; i++) 
        for (size_t j = 0; j < cols; j++) 
            a[i*cols + j] = i+j+1;
}

template <class TypeIn, class TypeOut>
static void matmul(const TypeIn *A, const TypeIn *B, TypeOut *C, uint16_t a_rows, uint16_t a_cols, uint16_t b_rows, uint16_t b_cols) 
{
    // Optional safety check (good practice)
    // assert(a_cols == b_rows);
    for (size_t r = 0; r < a_rows; r++)
    {
        for (size_t c = 0; c < b_cols; c++)
        {
            TypeOut acc = 0;

            for (size_t k = 0; k < a_cols; k++)  // <-- FIXED
            {
                acc += (TypeOut)A[r * a_cols + k] *
                       (TypeOut)B[k * b_cols + c];
            }

            C[r * b_cols + c] = acc;
        }
    }
}


template <class TypeIn, class TypeOut>
static void matmul(const TypeIn *A, const TypeIn *B, TypeIn *D, TypeOut *C, uint16_t a_rows, uint16_t a_cols, uint16_t b_rows, uint16_t b_cols) 
{
    // Optional safety check (good practice)
    // assert(a_cols == b_rows);

    for (size_t r = 0; r < a_rows; r++)
    {
        for (size_t c = 0; c < b_cols; c++)
        {
            TypeOut acc = D[r * b_cols + c];

            for (size_t k = 0; k < a_cols; k++)  // <-- FIXED
            {
                acc += (TypeOut)A[r * a_cols + k] *
                       (TypeOut)B[k * b_cols + c];
            }

            C[r * b_cols + c] = acc;
        }
    }
}


static float compute_avg(float *vec, size_t len)
{
    float sum = 0;

    for(size_t i = 0; i < len; i++)
        sum += vec[i];

    return sum/len;
}


};

#endif
