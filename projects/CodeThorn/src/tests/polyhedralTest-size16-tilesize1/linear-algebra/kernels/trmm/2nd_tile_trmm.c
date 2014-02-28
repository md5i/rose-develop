#   define NI ARRAYSIZE
# define _PB_NI ARRAYSIZE
/**
 * trmm.c: This file is part of the PolyBench/C 3.2 test suite.
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
  int ni = 16;
/* Variable declaration/allocation. */
  double alpha;
  double A[16][16];
  double B[16][16];
  int i;
  int j;
  int k;
  
#pragma scop
{
    int c1;
    int c2;
    int c0;
    for (c0 = 1; c0 <= 15; c0++) {
      for (c1 = 0; c1 <= c0 + 29; c1++) {
        
#pragma omp parallel for
{
          int c3;
          if (c0 >= 1 && c1 >= 0 && c1 <= c0 + 29) {
            for (c3 = (((c1 * 2 < 0?-(-c1 / 2) : ((2 < 0?(-c1 + - 2 - 1) / - 2 : (c1 + 2 - 1) / 2)))) > c1 + -15?((c1 * 2 < 0?-(-c1 / 2) : ((2 < 0?(-c1 + - 2 - 1) / - 2 : (c1 + 2 - 1) / 2)))) : c1 + -15); c3 <= (((((c1 + c0 + -1) * 2 < 0?((2 < 0?-((-(c1 + c0 + -1) + 2 + 1) / 2) : -((-(c1 + c0 + -1) + 2 - 1) / 2))) : (c1 + c0 + -1) / 2)) < c1?(((c1 + c0 + -1) * 2 < 0?((2 < 0?-((-(c1 + c0 + -1) + 2 + 1) / 2) : -((-(c1 + c0 + -1) + 2 - 1) / 2))) : (c1 + c0 + -1) / 2)) : c1)); c3++) {
              B[c0][c1 + - 1 * c3] += alpha * A[c0][- 1 * c1 + 2 * c3] * B[c1 + - 1 * c3][- 1 * c1 + 2 * c3];
            }
          }
        }
      }
    }
  }
  
#pragma endscop
  return 0;
}
