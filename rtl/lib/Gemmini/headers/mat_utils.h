#ifndef MAT_UTILS__H
#define MAT_UTILS__H

#include "config.h"
#include "utils.h" // DIM

namespace MatUtils
{

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

template <class T, size_t M, size_t N>
static void paddRowsWithZeros(T out[M][N], const T in[M][M]) 
{
    size_t start = 0;

    bzero (out, sizeof(T)*M*N);

    for (size_t i = 0; i < M; i++) 
    {
        for (size_t j = 0; j < M; j++)
            out[i][start+j] = in[i][j];
        start++;
    }
}


template <class T, size_t M, size_t N>
static void paddRowsWithZerosTransp(T out[M][N], const T in[M][M]) 
{
    size_t start = 0;

    bzero (out, sizeof(T)*M*N);

    for (size_t i = 0; i < M; i++) 
    {
        for (size_t j = 0; j < M; j++)
            out[i][start+j] = in[j][i];
        start++;
    }
}


template <class T, size_t M, size_t N>
static bool compare(T a[M][N], T b[M][N]) 
{
    for (size_t i = 0; i < M; i++) 
        for (size_t j = 0; j < N; j++) 
            if (a[i][j] != b[i][j])
                return false;
    return true;
}


template <class T, size_t M, size_t N>
static void accumulate(T a[M][N], const T b[M][N]) 
{
    for (size_t i = 0; i < M; i++) 
        for (size_t j = 0; j < N; j++) 
            a[i][j] += b[i][j];
}


template <class T, size_t M, size_t N>
static void print(const T in[M][N])
{
    for (size_t i = 0; i < M; i++) 
    {
        for (size_t j = 0; j < N; j++) 
            printf ("%d ", in[i][j]);
        printf("\n");
    }
    printf("\n");
}


template <class T, size_t M, size_t N>
static void debugPrint(const T gold[M][N], const T a[M][N])
{
    for (size_t i = 0; i < M; i++) 
    {
        for (size_t j = 0; j < N; j++) 
            ffprintf (stdout, gold[i][j]);

        printf (" | ");

        for (size_t j = 0; j < N; j++) 
        {
            printf ("%s", a[i][j] != gold[i][j] ? RED : RESET2); 
            ffprintf (stdout, a[i][j]);
            printf ("%s", RESET2); 
        }
        printf("\n");
    }
    cout << endl;
}


int random_int(int min, int max)
{
    return min + rand() % (max - min + 1); // [10, 15] -> 10 + rand()%6
}


template <class T, size_t M, size_t N>
static void loadRand(T a[M][N])
{
    for (size_t i = 0; i < M; i++) 
        for (size_t j = 0; j < N; j++) 
            a[i][j] = random_int(-128, 127);
            //a[i][j] = random_int(1, 4);

}

template <class T, size_t M, size_t N>
static void loadOnes(T a[M][N])
{
    for (size_t i = 0; i < M; i++) 
        for (size_t j = 0; j < N; j++) 
            a[i][j] = 1; 
}


template <class T1, class T2, size_t M, size_t N, size_t K>
static void matmul(const T1 A[M][N], const T1 B[M][N], T2 C[M][N]) 
{
    for (size_t r = 0; r < M; r++)
        for (size_t c = 0; c < K; c++) 
        {
            C[r][c] = 0;
            for (size_t k = 0; k < N; k++)
                C[r][c] += A[r][k]*B[k][c];
        }
}


template <class T1, class T2, size_t M, size_t N, size_t K>
static void matmul(T1 A[M][N], T1 B[N][K], T2 D[M][K], T2 C[M][K]) 
{
    for (size_t r = 0; r < M; r++)
        for (size_t c = 0; c < K; c++) 
        {
            C[r][c] = D[r][c];
            for (size_t k = 0; k < N; k++)
                C[r][c] += A[r][k]*B[k][c];
        }
}


static float compute_avg(float *vec, size_t len)
{
    float sum = 0;

    for(size_t i = 0; i < len; i++)
        sum += vec[i];

    return sum/len;
}


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


};

#endif
