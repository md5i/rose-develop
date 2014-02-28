#   define TSTEPS STEPSIZE
#   define N ARRAYSIZE
# define _PB_TSTEPS STEPSIZE
# define _PB_N ARRAYSIZE
/**
 * seidel-2d.c: This file is part of the PolyBench/C 3.2 test suite.
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
  int n = 64;
  int tsteps = 2;
/* Variable declaration/allocation. */
  double A[64][64];
  int t;
  int i;
  int j;
  
#pragma scop
{
    int c0;
    int c4;
    int c3;
    int c2;
    for (c0 = 0; c0 <= 15; c0++) {
      for (c2 = (2 > 4 * c0 + 1?2 : 4 * c0 + 1); c2 <= 4 * c0 + 66; c2++) {
        for (c3 = (((0 > (((c2 + -124) * 2 < 0?-(-(c2 + -124) / 2) : ((2 < 0?(-(c2 + -124) + - 2 - 1) / - 2 : (c2 + -124 + 2 - 1) / 2))))?0 : (((c2 + -124) * 2 < 0?-(-(c2 + -124) / 2) : ((2 < 0?(-(c2 + -124) + - 2 - 1) / - 2 : (c2 + -124 + 2 - 1) / 2)))))) > -4 * c0 + c2 + -65?((0 > (((c2 + -124) * 2 < 0?-(-(c2 + -124) / 2) : ((2 < 0?(-(c2 + -124) + - 2 - 1) / - 2 : (c2 + -124 + 2 - 1) / 2))))?0 : (((c2 + -124) * 2 < 0?-(-(c2 + -124) / 2) : ((2 < 0?(-(c2 + -124) + - 2 - 1) / - 2 : (c2 + -124 + 2 - 1) / 2)))))) : -4 * c0 + c2 + -65); c3 <= ((((1 < (((c2 + -2) * 2 < 0?((2 < 0?-((-(c2 + -2) + 2 + 1) / 2) : -((-(c2 + -2) + 2 - 1) / 2))) : (c2 + -2) / 2))?1 : (((c2 + -2) * 2 < 0?((2 < 0?-((-(c2 + -2) + 2 + 1) / 2) : -((-(c2 + -2) + 2 - 1) / 2))) : (c2 + -2) / 2)))) < -4 * c0 + c2 + -1?((1 < (((c2 + -2) * 2 < 0?((2 < 0?-((-(c2 + -2) + 2 + 1) / 2) : -((-(c2 + -2) + 2 - 1) / 2))) : (c2 + -2) / 2))?1 : (((c2 + -2) * 2 < 0?((2 < 0?-((-(c2 + -2) + 2 + 1) / 2) : -((-(c2 + -2) + 2 - 1) / 2))) : (c2 + -2) / 2)))) : -4 * c0 + c2 + -1)); c3++) {
          for (c4 = (((4 * c0 > c3 + 1?4 * c0 : c3 + 1)) > c2 + -1 * c3 + -62?((4 * c0 > c3 + 1?4 * c0 : c3 + 1)) : c2 + -1 * c3 + -62); c4 <= ((((4 * c0 + 3 < c3 + 62?4 * c0 + 3 : c3 + 62)) < c2 + -1 * c3 + -1?((4 * c0 + 3 < c3 + 62?4 * c0 + 3 : c3 + 62)) : c2 + -1 * c3 + -1)); c4++) {
            A[-1 * c3 + c4][c2 + -1 * c3 + -1 * c4] = (A[-1 * c3 + c4 - 1][c2 + -1 * c3 + -1 * c4 - 1] + A[-1 * c3 + c4 - 1][c2 + -1 * c3 + -1 * c4] + A[-1 * c3 + c4 - 1][c2 + -1 * c3 + -1 * c4 + 1] + A[-1 * c3 + c4][c2 + -1 * c3 + -1 * c4 - 1] + A[-1 * c3 + c4][c2 + -1 * c3 + -1 * c4] + A[-1 * c3 + c4][c2 + -1 * c3 + -1 * c4 + 1] + A[-1 * c3 + c4 + 1][c2 + -1 * c3 + -1 * c4 - 1] + A[-1 * c3 + c4 + 1][c2 + -1 * c3 + -1 * c4] + A[-1 * c3 + c4 + 1][c2 + -1 * c3 + -1 * c4 + 1]) / 9.0;
          }
        }
      }
    }
  }
  
#pragma endscop
  return 0;
}
