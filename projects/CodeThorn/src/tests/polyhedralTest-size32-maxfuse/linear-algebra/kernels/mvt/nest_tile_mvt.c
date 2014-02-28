#   define N ARRAYSIZE
# define _PB_N ARRAYSIZE
/**
 * mvt.c: This file is part of the PolyBench/C 3.2 test suite.
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
/* Variable declaration/allocation. */
  double A[32][32];
  double x1[32];
  double x2[32];
  double y_1[32];
  double y_2[32];
  int i;
  int j;
  
#pragma scop
{
    int c2;
    int c3;
    int c4;
    int c1;
#pragma omp parallel for private(c4, c3, c2)
    for (c1 = 0; c1 <= 15; c1++) {
      for (c2 = 0; c2 <= 7; c2++) {
        for (c3 = 4 * c2; c3 <= 4 * c2 + 3; c3++) {
#pragma ivdep
#pragma vector always
#pragma simd
          for (c4 = 2 * c1; c4 <= 2 * c1 + 1; c4++) {
            x1[c4] = x1[c4] + A[c4][c3] * y_1[c3];
            x2[c4] = x2[c4] + A[c3][c4] * y_2[c3];
          }
        }
      }
    }
  }
  
#pragma endscop
  return 0;
}
