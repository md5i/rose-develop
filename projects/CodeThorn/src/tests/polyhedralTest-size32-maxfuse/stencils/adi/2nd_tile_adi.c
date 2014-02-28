#   define TSTEPS STEPSIZE
#   define N ARRAYSIZE
# define _PB_TSTEPS STEPSIZE
# define _PB_N ARRAYSIZE
/**
 * adi.c: This file is part of the PolyBench/C 3.2 test suite.
 *
 *
 * Contact: Louis-Noel Pouchet <pouchet@cse.ohio-state.edu>
 * Web address: http://polybench.sourceforge.net
 */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

int main(int argc,char **argv)
{
/* Retrieve problem size. */
  int n = 32;
  int tsteps = 2;
/* Variable declaration/allocation. */
  double X[32][32];
  double A[32][32];
  double B[32][32];
  int t;
  int i1;
  int i2;
  
#pragma scop
{
    int c0;
    int c2;
    int c8;
    int c15;
    for (c0 = 0; c0 <= 1; c0++) {
      
#pragma omp parallel for private(c15, c8)
      for (c2 = 0; c2 <= 3; c2++) {
        for (c8 = 1; c8 <= 31; c8++) {
          
#pragma ivdep
          
#pragma vector always
          
#pragma simd
{
            int c1;
            int c0;
#pragma omp parallel for private(c1)
            for (c0 = 4 * c2; c0 <= 4 * c2 + 3; c0++) {
#pragma ivdep
#pragma vector always
#pragma simd
              for (c1 = 2 * c0; c1 <= 2 * c0 + 1; c1++) {
                B[c1][c8] = B[c1][c8] - A[c1][c8] * A[c1][c8] / B[c1][c8 - 1];
              }
            }
          }
        }
        for (c8 = 1; c8 <= 31; c8++) {
          
#pragma ivdep
          
#pragma vector always
          
#pragma simd
{
            int c1;
            int c0;
#pragma omp parallel for private(c1)
            for (c0 = 4 * c2; c0 <= 4 * c2 + 3; c0++) {
#pragma ivdep
#pragma vector always
#pragma simd
              for (c1 = 2 * c0; c1 <= 2 * c0 + 1; c1++) {
                X[c1][c8] = X[c1][c8] - X[c1][c8 - 1] * A[c1][c8] / B[c1][c8 - 1];
              }
            }
          }
        }
        for (c8 = 0; c8 <= 29; c8++) {
          
#pragma ivdep
          
#pragma vector always
          
#pragma simd
{
            int c0;
            int c1;
#pragma omp parallel for private(c1)
            for (c0 = 4 * c2; c0 <= 4 * c2 + 3; c0++) {
#pragma ivdep
#pragma vector always
#pragma simd
              for (c1 = 2 * c0; c1 <= 2 * c0 + 1; c1++) {
                X[c1][32 - c8 - 2] = (X[c1][32 - 2 - c8] - X[c1][32 - 2 - c8 - 1] * A[c1][32 - c8 - 3]) / B[c1][32 - 3 - c8];
              }
            }
          }
        }
      }
      
#pragma omp parallel for private(c15)
      for (c2 = 0; c2 <= 3; c2++) {
        
#pragma ivdep
        
#pragma vector always
        
#pragma simd
{
          int c1;
          int c0;
#pragma omp parallel for private(c1)
          for (c0 = 4 * c2; c0 <= 4 * c2 + 3; c0++) {
#pragma ivdep
#pragma vector always
#pragma simd
            for (c1 = 2 * c0; c1 <= 2 * c0 + 1; c1++) {
              X[c1][32 - 1] = X[c1][32 - 1] / B[c1][32 - 1];
            }
          }
        }
      }
      
#pragma omp parallel for private(c15, c8)
      for (c2 = 0; c2 <= 3; c2++) {
        for (c8 = 1; c8 <= 31; c8++) {
          
#pragma ivdep
          
#pragma vector always
          
#pragma simd
{
            int c0;
            int c1;
#pragma omp parallel for private(c1)
            for (c0 = 4 * c2; c0 <= 4 * c2 + 3; c0++) {
#pragma ivdep
#pragma vector always
#pragma simd
              for (c1 = 2 * c0; c1 <= 2 * c0 + 1; c1++) {
                B[c8][c1] = B[c8][c1] - A[c8][c1] * A[c8][c1] / B[c8 - 1][c1];
              }
            }
          }
        }
        for (c8 = 1; c8 <= 31; c8++) {
          
#pragma ivdep
          
#pragma vector always
          
#pragma simd
{
            int c0;
            int c1;
#pragma omp parallel for private(c1)
            for (c0 = 4 * c2; c0 <= 4 * c2 + 3; c0++) {
#pragma ivdep
#pragma vector always
#pragma simd
              for (c1 = 2 * c0; c1 <= 2 * c0 + 1; c1++) {
                X[c8][c1] = X[c8][c1] - X[c8 - 1][c1] * A[c8][c1] / B[c8 - 1][c1];
              }
            }
          }
        }
        for (c8 = 0; c8 <= 29; c8++) {
          
#pragma ivdep
          
#pragma vector always
          
#pragma simd
{
            int c0;
            int c1;
#pragma omp parallel for private(c1)
            for (c0 = 4 * c2; c0 <= 4 * c2 + 3; c0++) {
#pragma ivdep
#pragma vector always
#pragma simd
              for (c1 = 2 * c0; c1 <= 2 * c0 + 1; c1++) {
                X[32 - 2 - c8][c1] = (X[32 - 2 - c8][c1] - X[32 - c8 - 3][c1] * A[32 - 3 - c8][c1]) / B[32 - 2 - c8][c1];
              }
            }
          }
        }
      }
      
#pragma omp parallel for private(c15)
      for (c2 = 0; c2 <= 3; c2++) {
        
#pragma ivdep
        
#pragma vector always
        
#pragma simd
{
          int c1;
          int c0;
#pragma omp parallel for private(c1)
          for (c0 = 4 * c2; c0 <= 4 * c2 + 3; c0++) {
#pragma ivdep
#pragma vector always
#pragma simd
            for (c1 = 2 * c0; c1 <= 2 * c0 + 1; c1++) {
              X[32 - 1][c1] = X[32 - 1][c1] / B[32 - 1][c1];
            }
          }
        }
      }
    }
  }
  
#pragma endscop
  return 0;
}
