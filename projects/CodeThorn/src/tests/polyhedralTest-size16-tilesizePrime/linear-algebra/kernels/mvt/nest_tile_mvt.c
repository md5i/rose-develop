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
  int n = 16;
/* Variable declaration/allocation. */
  double A[16][16];
  double x1[16];
  double x2[16];
  double y_1[16];
  double y_2[16];
  int i;
  int j;
  
#pragma scop
{
    int c3;
    int c1;
    int c4;
    int c2;
#pragma omp parallel for private(c2, c4, c3)
    for (c1 = 0; c1 <= 3; c1++) {
      for (c2 = 0; c2 <= 2; c2++) {
        for (c3 = 7 * c2; c3 <= ((15 < 7 * c2 + 6?15 : 7 * c2 + 6)); c3++) {
#pragma ivdep
#pragma vector always
#pragma simd
          for (c4 = 5 * c1; c4 <= ((15 < 5 * c1 + 4?15 : 5 * c1 + 4)); c4++) {
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
