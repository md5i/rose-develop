#   define N ARRAYSIZE
# define _PB_N ARRAYSIZE
/**
 * gemver.c: This file is part of the PolyBench/C 3.2 test suite.
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
  int n = 16;
/* Variable declaration/allocation. */
  double alpha;
  double beta;
  double A[16][16];
  double u1[16];
  double v1[16];
  double u2[16];
  double v2[16];
  double w[16];
  double x[16];
  double y[16];
  double z[16];
  int i;
  int j;
  
#pragma scop
{
    int c4;
    int c2;
    int c1;
    
#pragma omp parallel for private(c2, c4)
    for (c1 = 0; c1 <= 1; c1++) {
      for (c2 = 0; c2 <= 15; c2++) {
        
#pragma ivdep
        
#pragma vector always
        
#pragma simd
{
          int c5;
          if (c1 <= 1) {
            for (c5 = 13 * c1; c5 <= ((15 < 13 * c1 + 12?15 : 13 * c1 + 12)); c5++) {
              A[c2][c5] = A[c2][c5] + u1[c2] * v1[c5] + u2[c2] * v2[c5];
              x[c5] = x[c5] + beta * A[c2][c5] * y[c2];
            }
          }
        }
      }
    }
    
#pragma omp parallel for private(c4)
    for (c1 = 0; c1 <= 1; c1++) {
      
#pragma ivdep
      
#pragma vector always
      
#pragma simd
{
        int c0;
        int c2;
        if (c1 <= 1) {
#pragma omp parallel for private(c2)
          for (c0 = ((13 * c1 + -10) * 11 < 0?-(-(13 * c1 + -10) / 11) : ((11 < 0?(-(13 * c1 + -10) + - 11 - 1) / - 11 : (13 * c1 + -10 + 11 - 1) / 11))); c0 <= ((1 < (((13 * c1 + 12) * 11 < 0?((11 < 0?-((-(13 * c1 + 12) + 11 + 1) / 11) : -((-(13 * c1 + 12) + 11 - 1) / 11))) : (13 * c1 + 12) / 11))?1 : (((13 * c1 + 12) * 11 < 0?((11 < 0?-((-(13 * c1 + 12) + 11 + 1) / 11) : -((-(13 * c1 + 12) + 11 - 1) / 11))) : (13 * c1 + 12) / 11)))); c0++) {
            for (c2 = (11 * c0 > 13 * c1?11 * c0 : 13 * c1); c2 <= ((((15 < 11 * c0 + 10?15 : 11 * c0 + 10)) < 13 * c1 + 12?((15 < 11 * c0 + 10?15 : 11 * c0 + 10)) : 13 * c1 + 12)); c2++) {
              x[c2] = x[c2] + z[c2];
            }
          }
        }
      }
    }
    
#pragma omp parallel for private(c2, c4)
    for (c1 = 0; c1 <= 1; c1++) {
      for (c2 = 0; c2 <= 15; c2++) {
        
#pragma ivdep
        
#pragma vector always
        
#pragma simd
{
          int c0;
          int c3;
          if (c1 <= 1) {
#pragma omp parallel for private(c3)
            for (c0 = ((13 * c1 + -10) * 11 < 0?-(-(13 * c1 + -10) / 11) : ((11 < 0?(-(13 * c1 + -10) + - 11 - 1) / - 11 : (13 * c1 + -10 + 11 - 1) / 11))); c0 <= ((1 < (((13 * c1 + 12) * 11 < 0?((11 < 0?-((-(13 * c1 + 12) + 11 + 1) / 11) : -((-(13 * c1 + 12) + 11 - 1) / 11))) : (13 * c1 + 12) / 11))?1 : (((13 * c1 + 12) * 11 < 0?((11 < 0?-((-(13 * c1 + 12) + 11 + 1) / 11) : -((-(13 * c1 + 12) + 11 - 1) / 11))) : (13 * c1 + 12) / 11)))); c0++) {
              for (c3 = (11 * c0 > 13 * c1?11 * c0 : 13 * c1); c3 <= ((((15 < 11 * c0 + 10?15 : 11 * c0 + 10)) < 13 * c1 + 12?((15 < 11 * c0 + 10?15 : 11 * c0 + 10)) : 13 * c1 + 12)); c3++) {
                w[c3] = w[c3] + alpha * A[c3][c2] * x[c2];
              }
            }
          }
        }
      }
    }
  }
  
#pragma endscop
  return 0;
}
