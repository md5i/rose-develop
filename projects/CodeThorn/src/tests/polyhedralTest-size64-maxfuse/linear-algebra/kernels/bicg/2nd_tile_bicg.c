#   define NX ARRAYSIZE
#   define NY ARRAYSIZE
# define _PB_NX ARRAYSIZE
# define _PB_NY ARRAYSIZE
/**
 * bicg.c: This file is part of the PolyBench/C 3.2 test suite.
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
  int nx = 64;
  int ny = 64;
  double A[64][64];
  double s[64];
  double q[64];
  double p[64];
  double r[64];
  int i;
  int j;
  
#pragma scop
{
    int c2;
    int c1;
    int c4;
    
#pragma omp parallel for private(c4)
    for (c1 = 0; c1 <= 7; c1++) {
      
#pragma ivdep
      
#pragma vector always
      
#pragma simd
{
        int c0;
        int c2;
#pragma omp parallel for private(c2)
        for (c0 = 4 * c1; c0 <= 4 * c1 + 3; c0++) {
          for (c2 = 2 * c0; c2 <= 2 * c0 + 1; c2++) {
            q[c2] = 0;
          }
        }
      }
    }
    
#pragma omp parallel for private(c4, c2)
    for (c1 = 0; c1 <= 7; c1++) {
      for (c2 = 0; c2 <= 63; c2++) {
        
#pragma ivdep
        
#pragma vector always
        
#pragma simd
{
          int c0;
          int c3;
#pragma omp parallel for private(c3)
          for (c0 = 4 * c1; c0 <= 4 * c1 + 3; c0++) {
            for (c3 = 2 * c0; c3 <= 2 * c0 + 1; c3++) {
              q[c3] = q[c3] + A[c3][c2] * p[c2];
            }
          }
        }
      }
    }
    
#pragma omp parallel for private(c4)
    for (c1 = 0; c1 <= 7; c1++) {
      
#pragma ivdep
      
#pragma vector always
      
#pragma simd
{
        int c0;
        int c2;
#pragma omp parallel for private(c2)
        for (c0 = 4 * c1; c0 <= 4 * c1 + 3; c0++) {
          for (c2 = 2 * c0; c2 <= 2 * c0 + 1; c2++) {
            s[c2] = 0;
          }
        }
      }
    }
    
#pragma omp parallel for private(c4, c2)
    for (c1 = 0; c1 <= 7; c1++) {
      for (c2 = 0; c2 <= 63; c2++) {
        
#pragma ivdep
        
#pragma vector always
        
#pragma simd
{
          int c0;
          int c3;
#pragma omp parallel for private(c3)
          for (c0 = 4 * c1; c0 <= 4 * c1 + 3; c0++) {
            for (c3 = 2 * c0; c3 <= 2 * c0 + 1; c3++) {
              s[c3] = s[c3] + r[c2] * A[c2][c3];
            }
          }
        }
      }
    }
  }
  
#pragma endscop
  return 0;
}
