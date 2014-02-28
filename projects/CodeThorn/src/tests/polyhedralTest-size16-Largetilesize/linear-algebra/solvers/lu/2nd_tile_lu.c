#   define N ARRAYSIZE
# define _PB_N ARRAYSIZE
/**
 * lu.c: This file is part of the PolyBench/C 3.2 test suite.
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
  int i;
  int j;
  int k;
  
#pragma scop
{
    int c0;
    int c3;
    int c2;
{
      int c6;
      int c5;
      int c1;
#pragma omp parallel for private(c5, c6)
      for (c1 = 1; c1 <= 15; c1++) {
        for (c5 = 1; c5 <= ((15 < c1 + 1?15 : c1 + 1)); c5++) {
          if (c5 >= 2) {
            for (c6 = c5; c6 <= (((((-1 * c1 + 2 * c5 + 15) * 2 < 0?((2 < 0?-((-(-1 * c1 + 2 * c5 + 15) + 2 + 1) / 2) : -((-(-1 * c1 + 2 * c5 + 15) + 2 - 1) / 2))) : (-1 * c1 + 2 * c5 + 15) / 2)) < (((-1 * c1 + 15 * c5 + 13) * 14 < 0?((14 < 0?-((-(-1 * c1 + 15 * c5 + 13) + 14 + 1) / 14) : -((-(-1 * c1 + 15 * c5 + 13) + 14 - 1) / 14))) : (-1 * c1 + 15 * c5 + 13) / 14))?(((-1 * c1 + 2 * c5 + 15) * 2 < 0?((2 < 0?-((-(-1 * c1 + 2 * c5 + 15) + 2 + 1) / 2) : -((-(-1 * c1 + 2 * c5 + 15) + 2 - 1) / 2))) : (-1 * c1 + 2 * c5 + 15) / 2)) : (((-1 * c1 + 15 * c5 + 13) * 14 < 0?((14 < 0?-((-(-1 * c1 + 15 * c5 + 13) + 14 + 1) / 14) : -((-(-1 * c1 + 15 * c5 + 13) + 14 - 1) / 14))) : (-1 * c1 + 15 * c5 + 13) / 14)))); c6++) {
              A[c6][c1] = A[c6][c1] - A[c6][c5 + -2] * A[c5 + -2][c1];
            }
          }
          if (c5 == 1) {
            A[1 + - 1][c1] = A[1 + - 1][c1] / A[1 + - 1][1 + - 1];
            A[1][c1] = A[1][c1] - A[1][1 + - 1] * A[1 + - 1][c1];
          }
          if (c1 == 15 && c5 == 15) {
            A[15 + - 1][15] = A[15 + - 1][15] / A[15 + - 1][15 + - 1];
            A[15][15] = A[15][15] - A[15][15 + - 1] * A[15 + - 1][15];
          }
          if (c1 >= c5 && c5 >= 2 && c5 <= 14) {
            A[c5 + - 1][c1] = A[c5 + - 1][c1] / A[c5 + - 1][c5 + - 1];
            A[c5][c1] = A[c5][c1] - A[c5][c5 + - 1] * A[c5 + - 1][c1];
            A[c5 + 1][c1] = A[c5 + 1][c1] - A[c5 + 1][c5 + -2] * A[c5 + -2][c1];
          }
          if (c5 >= 2) {
            for (c6 = c5 + 2; c6 <= 15; c6++) {
              A[c6][c1] = A[c6][c1] - A[c6][c5 + -2] * A[c5 + -2][c1];
            }
          }
        }
      }
    }
  }
  
#pragma endscop
  return 0;
}
