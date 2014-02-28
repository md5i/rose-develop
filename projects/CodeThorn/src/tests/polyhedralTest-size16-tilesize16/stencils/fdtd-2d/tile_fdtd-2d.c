/**
 * fdtd-2d.c: This file is part of the PolyBench/C 3.2 test suite.
 *
 *
 * Contact: Louis-Noel Pouchet <pouchet@cse.ohio-state.edu>
 * Web address: http://polybench.sourceforge.net
 */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#   define TMAX STEPSIZE
#   define NX ARRAYSIZE
#   define NY ARRAYSIZE
# define _PB_TMAX STEPSIZE 
# define _PB_NX ARRAYSIZE
# define _PB_NY ARRAYSIZE

int main(int argc,char **argv)
{
/* Retrieve problem size. */
  int tmax = 2;
  int nx = 16;
  int ny = 16;
/* Variable declaration/allocation. */
  double ex[16][16];
  double ey[16][16];
  double hz[16][16];
  double _fict_[2];
  int t;
  int i;
  int j;
  
#pragma scop
{
    int c1;
    int c2;
    int c0;
{
      int c5;
      int c4;
      for (c4 = 1; c4 <= 2; c4++) {
        ex[0][c4] = ex[0][c4] - 0.5 * (hz[0][c4] - hz[0][c4 - 1]);
        ey[1][c4 + - 1] = ey[1][c4 + - 1] - 0.5 * (hz[1][c4 + - 1] - hz[1 - 1][c4 + - 1]);
        ey[0][c4 + - 1] = _fict_[0];
        hz[0][c4 + - 1] = hz[0][c4 + - 1] - 0.7 * (ex[0][c4 + - 1 + 1] - ex[0][c4 + - 1] + ey[0 + 1][c4 + - 1] - ey[0][c4 + - 1]);
      }
      for (c4 = 3; c4 <= 7; c4++) {
        for (c5 = 1; c5 <= c4 + -2; c5++) {
          ex[c4 + -1 * c5 + - 1][c5] = ex[c4 + -1 * c5 + - 1][c5] - 0.5 * (hz[c4 + -1 * c5 + - 1][c5] - hz[c4 + -1 * c5 + - 1][c5 - 1]);
          ey[c4 + -1 * c5][c5 + - 1] = ey[c4 + -1 * c5][c5 + - 1] - 0.5 * (hz[c4 + -1 * c5][c5 + - 1] - hz[c4 + -1 * c5 - 1][c5 + - 1]);
          hz[- 1 * 0 + (c4 + -1 * c5) + - 1][- 1 * 0 + c5 + - 1] = hz[- 1 * 0 + (c4 + -1 * c5) + - 1][- 1 * 0 + c5 + - 1] - 0.7 * (ex[- 1 * 0 + (c4 + -1 * c5) + - 1][- 1 * 0 + c5 + - 1 + 1] - ex[- 1 * 0 + (c4 + -1 * c5) + - 1][- 1 * 0 + c5 + - 1] + ey[- 1 * 0 + (c4 + -1 * c5) + - 1 + 1][- 1 * 0 + c5 + - 1] - ey[- 1 * 0 + (c4 + -1 * c5) + - 1][- 1 * 0 + c5 + - 1]);
        }
        ex[0][c4] = ex[0][c4] - 0.5 * (hz[0][c4] - hz[0][c4 - 1]);
        ey[1][c4 + - 1] = ey[1][c4 + - 1] - 0.5 * (hz[1][c4 + - 1] - hz[1 - 1][c4 + - 1]);
        ey[0][c4 + - 1] = _fict_[0];
        hz[0][c4 + - 1] = hz[0][c4 + - 1] - 0.7 * (ex[0][c4 + - 1 + 1] - ex[0][c4 + - 1] + ey[0 + 1][c4 + - 1] - ey[0][c4 + - 1]);
      }
      for (c5 = 1; c5 <= 6; c5++) {
        ex[-1 * c5 + 8 + - 1][c5] = ex[-1 * c5 + 8 + - 1][c5] - 0.5 * (hz[-1 * c5 + 8 + - 1][c5] - hz[-1 * c5 + 8 + - 1][c5 - 1]);
        ey[-1 * c5 + 8][c5 + - 1] = ey[-1 * c5 + 8][c5 + - 1] - 0.5 * (hz[-1 * c5 + 8][c5 + - 1] - hz[-1 * c5 + 8 - 1][c5 + - 1]);
        hz[- 1 * 0 + (-1 * c5 + 8) + - 1][- 1 * 0 + c5 + - 1] = hz[- 1 * 0 + (-1 * c5 + 8) + - 1][- 1 * 0 + c5 + - 1] - 0.7 * (ex[- 1 * 0 + (-1 * c5 + 8) + - 1][- 1 * 0 + c5 + - 1 + 1] - ex[- 1 * 0 + (-1 * c5 + 8) + - 1][- 1 * 0 + c5 + - 1] + ey[- 1 * 0 + (-1 * c5 + 8) + - 1 + 1][- 1 * 0 + c5 + - 1] - ey[- 1 * 0 + (-1 * c5 + 8) + - 1][- 1 * 0 + c5 + - 1]);
      }
      ex[0][8] = ex[0][8] - 0.5 * (hz[0][8] - hz[0][8 - 1]);
      ey[1][8 + - 1] = ey[1][8 + - 1] - 0.5 * (hz[1][8 + - 1] - hz[1 - 1][8 + - 1]);
      ey[0][8 + - 1] = _fict_[0];
      hz[0][8 + - 1] = hz[0][8 + - 1] - 0.7 * (ex[0][8 + - 1 + 1] - ex[0][8 + - 1] + ey[0 + 1][8 + - 1] - ey[0][8 + - 1]);
      ey[0][15] = _fict_[0];
      for (c5 = 1; c5 <= 7; c5++) {
        ex[-1 * c5 + 9 + - 1][c5] = ex[-1 * c5 + 9 + - 1][c5] - 0.5 * (hz[-1 * c5 + 9 + - 1][c5] - hz[-1 * c5 + 9 + - 1][c5 - 1]);
        ey[-1 * c5 + 9][c5 + - 1] = ey[-1 * c5 + 9][c5 + - 1] - 0.5 * (hz[-1 * c5 + 9][c5 + - 1] - hz[-1 * c5 + 9 - 1][c5 + - 1]);
        hz[- 1 * 0 + (-1 * c5 + 9) + - 1][- 1 * 0 + c5 + - 1] = hz[- 1 * 0 + (-1 * c5 + 9) + - 1][- 1 * 0 + c5 + - 1] - 0.7 * (ex[- 1 * 0 + (-1 * c5 + 9) + - 1][- 1 * 0 + c5 + - 1 + 1] - ex[- 1 * 0 + (-1 * c5 + 9) + - 1][- 1 * 0 + c5 + - 1] + ey[- 1 * 0 + (-1 * c5 + 9) + - 1 + 1][- 1 * 0 + c5 + - 1] - ey[- 1 * 0 + (-1 * c5 + 9) + - 1][- 1 * 0 + c5 + - 1]);
      }
      ex[0][9] = ex[0][9] - 0.5 * (hz[0][9] - hz[0][9 - 1]);
      ey[1][9 + - 1] = ey[1][9 + - 1] - 0.5 * (hz[1][9 + - 1] - hz[1 - 1][9 + - 1]);
      ey[0][9 + - 1] = _fict_[0];
      hz[0][9 + - 1] = hz[0][9 + - 1] - 0.7 * (ex[0][9 + - 1 + 1] - ex[0][9 + - 1] + ey[0 + 1][9 + - 1] - ey[0][9 + - 1]);
      ex[15][1] = ex[15][1] - 0.5 * (hz[15][1] - hz[15][1 - 1]);
      for (c5 = 1; c5 <= 8; c5++) {
        ex[-1 * c5 + 10 + - 1][c5] = ex[-1 * c5 + 10 + - 1][c5] - 0.5 * (hz[-1 * c5 + 10 + - 1][c5] - hz[-1 * c5 + 10 + - 1][c5 - 1]);
        ey[-1 * c5 + 10][c5 + - 1] = ey[-1 * c5 + 10][c5 + - 1] - 0.5 * (hz[-1 * c5 + 10][c5 + - 1] - hz[-1 * c5 + 10 - 1][c5 + - 1]);
        hz[- 1 * 0 + (-1 * c5 + 10) + - 1][- 1 * 0 + c5 + - 1] = hz[- 1 * 0 + (-1 * c5 + 10) + - 1][- 1 * 0 + c5 + - 1] - 0.7 * (ex[- 1 * 0 + (-1 * c5 + 10) + - 1][- 1 * 0 + c5 + - 1 + 1] - ex[- 1 * 0 + (-1 * c5 + 10) + - 1][- 1 * 0 + c5 + - 1] + ey[- 1 * 0 + (-1 * c5 + 10) + - 1 + 1][- 1 * 0 + c5 + - 1] - ey[- 1 * 0 + (-1 * c5 + 10) + - 1][- 1 * 0 + c5 + - 1]);
      }
      ey[1][15] = ey[1][15] - 0.5 * (hz[1][15] - hz[1 - 1][15]);
      ex[0][10] = ex[0][10] - 0.5 * (hz[0][10] - hz[0][10 - 1]);
      ey[1][10 + - 1] = ey[1][10 + - 1] - 0.5 * (hz[1][10 + - 1] - hz[1 - 1][10 + - 1]);
      ey[0][10 + - 1] = _fict_[0];
      hz[0][10 + - 1] = hz[0][10 + - 1] - 0.7 * (ex[0][10 + - 1 + 1] - ex[0][10 + - 1] + ey[0 + 1][10 + - 1] - ey[0][10 + - 1]);
      for (c4 = 11; c4 <= 15; c4++) {
        for (c5 = 1; c5 <= c4 + -10; c5++) {
          ex[c4 + -1 * c5 + - 1][c5] = ex[c4 + -1 * c5 + - 1][c5] - 0.5 * (hz[c4 + -1 * c5 + - 1][c5] - hz[c4 + -1 * c5 + - 1][c5 - 1]);
          ey[c4 + -1 * c5][c5 + - 1] = ey[c4 + -1 * c5][c5 + - 1] - 0.5 * (hz[c4 + -1 * c5][c5 + - 1] - hz[c4 + -1 * c5 - 1][c5 + - 1]);
          hz[- 1 * 0 + (c4 + -1 * c5) + - 1][- 1 * 0 + c5 + - 1] = hz[- 1 * 0 + (c4 + -1 * c5) + - 1][- 1 * 0 + c5 + - 1] - 0.7 * (ex[- 1 * 0 + (c4 + -1 * c5) + - 1][- 1 * 0 + c5 + - 1 + 1] - ex[- 1 * 0 + (c4 + -1 * c5) + - 1][- 1 * 0 + c5 + - 1] + ey[- 1 * 0 + (c4 + -1 * c5) + - 1 + 1][- 1 * 0 + c5 + - 1] - ey[- 1 * 0 + (c4 + -1 * c5) + - 1][- 1 * 0 + c5 + - 1]);
        }
        ex[15][c4 + -9] = ex[15][c4 + -9] - 0.5 * (hz[15][c4 + -9] - hz[15][c4 + -9 - 1]);
        ex[9 + - 1][c4 + -9] = ex[9 + - 1][c4 + -9] - 0.5 * (hz[9 + - 1][c4 + -9] - hz[9 + - 1][c4 + -9 - 1]);
        ey[9][c4 + -9 + - 1] = ey[9][c4 + -9 + - 1] - 0.5 * (hz[9][c4 + -9 + - 1] - hz[9 - 1][c4 + -9 + - 1]);
        hz[- 1 * 0 + 9 + - 1][- 1 * 0 + (c4 + -9) + - 1] = hz[- 1 * 0 + 9 + - 1][- 1 * 0 + (c4 + -9) + - 1] - 0.7 * (ex[- 1 * 0 + 9 + - 1][- 1 * 0 + (c4 + -9) + - 1 + 1] - ex[- 1 * 0 + 9 + - 1][- 1 * 0 + (c4 + -9) + - 1] + ey[- 1 * 0 + 9 + - 1 + 1][- 1 * 0 + (c4 + -9) + - 1] - ey[- 1 * 0 + 9 + - 1][- 1 * 0 + (c4 + -9) + - 1]);
        for (c5 = c4 + -8; c5 <= 9; c5++) {
          ex[c4 + -1 * c5 + - 1][c5] = ex[c4 + -1 * c5 + - 1][c5] - 0.5 * (hz[c4 + -1 * c5 + - 1][c5] - hz[c4 + -1 * c5 + - 1][c5 - 1]);
          ey[c4 + -1 * c5][c5 + - 1] = ey[c4 + -1 * c5][c5 + - 1] - 0.5 * (hz[c4 + -1 * c5][c5 + - 1] - hz[c4 + -1 * c5 - 1][c5 + - 1]);
          hz[- 1 * 0 + (c4 + -1 * c5) + - 1][- 1 * 0 + c5 + - 1] = hz[- 1 * 0 + (c4 + -1 * c5) + - 1][- 1 * 0 + c5 + - 1] - 0.7 * (ex[- 1 * 0 + (c4 + -1 * c5) + - 1][- 1 * 0 + c5 + - 1 + 1] - ex[- 1 * 0 + (c4 + -1 * c5) + - 1][- 1 * 0 + c5 + - 1] + ey[- 1 * 0 + (c4 + -1 * c5) + - 1 + 1][- 1 * 0 + c5 + - 1] - ey[- 1 * 0 + (c4 + -1 * c5) + - 1][- 1 * 0 + c5 + - 1]);
        }
        if (c4 == 11) {
          ey[2][15] = ey[2][15] - 0.5 * (hz[2][15] - hz[2 - 1][15]);
        }
        if (c4 >= 12) {
          ey[c4 + -9][15] = ey[c4 + -9][15] - 0.5 * (hz[c4 + -9][15] - hz[c4 + -9 - 1][15]);
          ex[c4 + -10 + - 1][10] = ex[c4 + -10 + - 1][10] - 0.5 * (hz[c4 + -10 + - 1][10] - hz[c4 + -10 + - 1][10 - 1]);
          ey[c4 + -10][10 + - 1] = ey[c4 + -10][10 + - 1] - 0.5 * (hz[c4 + -10][10 + - 1] - hz[c4 + -10 - 1][10 + - 1]);
          hz[- 1 * 0 + (c4 + -10) + - 1][- 1 * 0 + 10 + - 1] = hz[- 1 * 0 + (c4 + -10) + - 1][- 1 * 0 + 10 + - 1] - 0.7 * (ex[- 1 * 0 + (c4 + -10) + - 1][- 1 * 0 + 10 + - 1 + 1] - ex[- 1 * 0 + (c4 + -10) + - 1][- 1 * 0 + 10 + - 1] + ey[- 1 * 0 + (c4 + -10) + - 1 + 1][- 1 * 0 + 10 + - 1] - ey[- 1 * 0 + (c4 + -10) + - 1][- 1 * 0 + 10 + - 1]);
        }
        for (c5 = 11; c5 <= c4 + -2; c5++) {
          ex[c4 + -1 * c5 + - 1][c5] = ex[c4 + -1 * c5 + - 1][c5] - 0.5 * (hz[c4 + -1 * c5 + - 1][c5] - hz[c4 + -1 * c5 + - 1][c5 - 1]);
          ey[c4 + -1 * c5][c5 + - 1] = ey[c4 + -1 * c5][c5 + - 1] - 0.5 * (hz[c4 + -1 * c5][c5 + - 1] - hz[c4 + -1 * c5 - 1][c5 + - 1]);
          hz[- 1 * 0 + (c4 + -1 * c5) + - 1][- 1 * 0 + c5 + - 1] = hz[- 1 * 0 + (c4 + -1 * c5) + - 1][- 1 * 0 + c5 + - 1] - 0.7 * (ex[- 1 * 0 + (c4 + -1 * c5) + - 1][- 1 * 0 + c5 + - 1 + 1] - ex[- 1 * 0 + (c4 + -1 * c5) + - 1][- 1 * 0 + c5 + - 1] + ey[- 1 * 0 + (c4 + -1 * c5) + - 1 + 1][- 1 * 0 + c5 + - 1] - ey[- 1 * 0 + (c4 + -1 * c5) + - 1][- 1 * 0 + c5 + - 1]);
        }
        ex[0][c4] = ex[0][c4] - 0.5 * (hz[0][c4] - hz[0][c4 - 1]);
        ey[1][c4 + - 1] = ey[1][c4 + - 1] - 0.5 * (hz[1][c4 + - 1] - hz[1 - 1][c4 + - 1]);
        ey[0][c4 + - 1] = _fict_[0];
        hz[0][c4 + - 1] = hz[0][c4 + - 1] - 0.7 * (ex[0][c4 + - 1 + 1] - ex[0][c4 + - 1] + ey[0 + 1][c4 + - 1] - ey[0][c4 + - 1]);
      }
      for (c4 = 16; c4 <= 24; c4++) {
        for (c5 = c4 + -15; c5 <= ((9 < c4 + -10?9 : c4 + -10)); c5++) {
          ex[c4 + -1 * c5 + - 1][c5] = ex[c4 + -1 * c5 + - 1][c5] - 0.5 * (hz[c4 + -1 * c5 + - 1][c5] - hz[c4 + -1 * c5 + - 1][c5 - 1]);
          ey[c4 + -1 * c5][c5 + - 1] = ey[c4 + -1 * c5][c5 + - 1] - 0.5 * (hz[c4 + -1 * c5][c5 + - 1] - hz[c4 + -1 * c5 - 1][c5 + - 1]);
          hz[- 1 * 0 + (c4 + -1 * c5) + - 1][- 1 * 0 + c5 + - 1] = hz[- 1 * 0 + (c4 + -1 * c5) + - 1][- 1 * 0 + c5 + - 1] - 0.7 * (ex[- 1 * 0 + (c4 + -1 * c5) + - 1][- 1 * 0 + c5 + - 1 + 1] - ex[- 1 * 0 + (c4 + -1 * c5) + - 1][- 1 * 0 + c5 + - 1] + ey[- 1 * 0 + (c4 + -1 * c5) + - 1 + 1][- 1 * 0 + c5 + - 1] - ey[- 1 * 0 + (c4 + -1 * c5) + - 1][- 1 * 0 + c5 + - 1]);
        }
        if (c4 == 19) {
          ey[10][15] = ey[10][15] - 0.5 * (hz[10][15] - hz[10 - 1][15]);
          ex[15][10] = ex[15][10] - 0.5 * (hz[15][10] - hz[15][10 - 1]);
          ex[9 + - 1][10] = ex[9 + - 1][10] - 0.5 * (hz[9 + - 1][10] - hz[9 + - 1][10 - 1]);
          ey[9][10 + - 1] = ey[9][10 + - 1] - 0.5 * (hz[9][10 + - 1] - hz[9 - 1][10 + - 1]);
          hz[- 1 * 0 + 9 + - 1][- 1 * 0 + 10 + - 1] = hz[- 1 * 0 + 9 + - 1][- 1 * 0 + 10 + - 1] - 0.7 * (ex[- 1 * 0 + 9 + - 1][- 1 * 0 + 10 + - 1 + 1] - ex[- 1 * 0 + 9 + - 1][- 1 * 0 + 10 + - 1] + ey[- 1 * 0 + 9 + - 1 + 1][- 1 * 0 + 10 + - 1] - ey[- 1 * 0 + 9 + - 1][- 1 * 0 + 10 + - 1]);
        }
        if (c4 <= 18) {
          ex[15][c4 + -9] = ex[15][c4 + -9] - 0.5 * (hz[15][c4 + -9] - hz[15][c4 + -9 - 1]);
          ex[9 + - 1][c4 + -9] = ex[9 + - 1][c4 + -9] - 0.5 * (hz[9 + - 1][c4 + -9] - hz[9 + - 1][c4 + -9 - 1]);
          ey[9][c4 + -9 + - 1] = ey[9][c4 + -9 + - 1] - 0.5 * (hz[9][c4 + -9 + - 1] - hz[9 - 1][c4 + -9 + - 1]);
          hz[- 1 * 0 + 9 + - 1][- 1 * 0 + (c4 + -9) + - 1] = hz[- 1 * 0 + 9 + - 1][- 1 * 0 + (c4 + -9) + - 1] - 0.7 * (ex[- 1 * 0 + 9 + - 1][- 1 * 0 + (c4 + -9) + - 1 + 1] - ex[- 1 * 0 + 9 + - 1][- 1 * 0 + (c4 + -9) + - 1] + ey[- 1 * 0 + 9 + - 1 + 1][- 1 * 0 + (c4 + -9) + - 1] - ey[- 1 * 0 + 9 + - 1][- 1 * 0 + (c4 + -9) + - 1]);
        }
        for (c5 = c4 + -8; c5 <= 9; c5++) {
          ex[c4 + -1 * c5 + - 1][c5] = ex[c4 + -1 * c5 + - 1][c5] - 0.5 * (hz[c4 + -1 * c5 + - 1][c5] - hz[c4 + -1 * c5 + - 1][c5 - 1]);
          ey[c4 + -1 * c5][c5 + - 1] = ey[c4 + -1 * c5][c5 + - 1] - 0.5 * (hz[c4 + -1 * c5][c5 + - 1] - hz[c4 + -1 * c5 - 1][c5 + - 1]);
          hz[- 1 * 0 + (c4 + -1 * c5) + - 1][- 1 * 0 + c5 + - 1] = hz[- 1 * 0 + (c4 + -1 * c5) + - 1][- 1 * 0 + c5 + - 1] - 0.7 * (ex[- 1 * 0 + (c4 + -1 * c5) + - 1][- 1 * 0 + c5 + - 1 + 1] - ex[- 1 * 0 + (c4 + -1 * c5) + - 1][- 1 * 0 + c5 + - 1] + ey[- 1 * 0 + (c4 + -1 * c5) + - 1 + 1][- 1 * 0 + c5 + - 1] - ey[- 1 * 0 + (c4 + -1 * c5) + - 1][- 1 * 0 + c5 + - 1]);
        }
        if (c4 >= 20) {
          ey[c4 + -9][15] = ey[c4 + -9][15] - 0.5 * (hz[c4 + -9][15] - hz[c4 + -9 - 1][15]);
          ex[c4 + -10 + - 1][10] = ex[c4 + -10 + - 1][10] - 0.5 * (hz[c4 + -10 + - 1][10] - hz[c4 + -10 + - 1][10 - 1]);
          ey[c4 + -10][10 + - 1] = ey[c4 + -10][10 + - 1] - 0.5 * (hz[c4 + -10][10 + - 1] - hz[c4 + -10 - 1][10 + - 1]);
          hz[- 1 * 0 + (c4 + -10) + - 1][- 1 * 0 + 10 + - 1] = hz[- 1 * 0 + (c4 + -10) + - 1][- 1 * 0 + 10 + - 1] - 0.7 * (ex[- 1 * 0 + (c4 + -10) + - 1][- 1 * 0 + 10 + - 1 + 1] - ex[- 1 * 0 + (c4 + -10) + - 1][- 1 * 0 + 10 + - 1] + ey[- 1 * 0 + (c4 + -10) + - 1 + 1][- 1 * 0 + 10 + - 1] - ey[- 1 * 0 + (c4 + -10) + - 1][- 1 * 0 + 10 + - 1]);
        }
        for (c5 = 11; c5 <= c4 + -10; c5++) {
          ex[c4 + -1 * c5 + - 1][c5] = ex[c4 + -1 * c5 + - 1][c5] - 0.5 * (hz[c4 + -1 * c5 + - 1][c5] - hz[c4 + -1 * c5 + - 1][c5 - 1]);
          ey[c4 + -1 * c5][c5 + - 1] = ey[c4 + -1 * c5][c5 + - 1] - 0.5 * (hz[c4 + -1 * c5][c5 + - 1] - hz[c4 + -1 * c5 - 1][c5 + - 1]);
          hz[- 1 * 0 + (c4 + -1 * c5) + - 1][- 1 * 0 + c5 + - 1] = hz[- 1 * 0 + (c4 + -1 * c5) + - 1][- 1 * 0 + c5 + - 1] - 0.7 * (ex[- 1 * 0 + (c4 + -1 * c5) + - 1][- 1 * 0 + c5 + - 1 + 1] - ex[- 1 * 0 + (c4 + -1 * c5) + - 1][- 1 * 0 + c5 + - 1] + ey[- 1 * 0 + (c4 + -1 * c5) + - 1 + 1][- 1 * 0 + c5 + - 1] - ey[- 1 * 0 + (c4 + -1 * c5) + - 1][- 1 * 0 + c5 + - 1]);
        }
        if (c4 >= 20) {
          ex[15][c4 + -9] = ex[15][c4 + -9] - 0.5 * (hz[15][c4 + -9] - hz[15][c4 + -9 - 1]);
          ex[9 + - 1][c4 + -9] = ex[9 + - 1][c4 + -9] - 0.5 * (hz[9 + - 1][c4 + -9] - hz[9 + - 1][c4 + -9 - 1]);
          ey[9][c4 + -9 + - 1] = ey[9][c4 + -9 + - 1] - 0.5 * (hz[9][c4 + -9 + - 1] - hz[9 - 1][c4 + -9 + - 1]);
          hz[- 1 * 0 + 9 + - 1][- 1 * 0 + (c4 + -9) + - 1] = hz[- 1 * 0 + 9 + - 1][- 1 * 0 + (c4 + -9) + - 1] - 0.7 * (ex[- 1 * 0 + 9 + - 1][- 1 * 0 + (c4 + -9) + - 1 + 1] - ex[- 1 * 0 + 9 + - 1][- 1 * 0 + (c4 + -9) + - 1] + ey[- 1 * 0 + 9 + - 1 + 1][- 1 * 0 + (c4 + -9) + - 1] - ey[- 1 * 0 + 9 + - 1][- 1 * 0 + (c4 + -9) + - 1]);
        }
        if (c4 <= 18) {
          ey[c4 + -9][15] = ey[c4 + -9][15] - 0.5 * (hz[c4 + -9][15] - hz[c4 + -9 - 1][15]);
          ex[c4 + -10 + - 1][10] = ex[c4 + -10 + - 1][10] - 0.5 * (hz[c4 + -10 + - 1][10] - hz[c4 + -10 + - 1][10 - 1]);
          ey[c4 + -10][10 + - 1] = ey[c4 + -10][10 + - 1] - 0.5 * (hz[c4 + -10][10 + - 1] - hz[c4 + -10 - 1][10 + - 1]);
          hz[- 1 * 0 + (c4 + -10) + - 1][- 1 * 0 + 10 + - 1] = hz[- 1 * 0 + (c4 + -10) + - 1][- 1 * 0 + 10 + - 1] - 0.7 * (ex[- 1 * 0 + (c4 + -10) + - 1][- 1 * 0 + 10 + - 1 + 1] - ex[- 1 * 0 + (c4 + -10) + - 1][- 1 * 0 + 10 + - 1] + ey[- 1 * 0 + (c4 + -10) + - 1 + 1][- 1 * 0 + 10 + - 1] - ey[- 1 * 0 + (c4 + -10) + - 1][- 1 * 0 + 10 + - 1]);
        }
        for (c5 = (11 > c4 + -8?11 : c4 + -8); c5 <= ((15 < c4 + -2?15 : c4 + -2)); c5++) {
          ex[c4 + -1 * c5 + - 1][c5] = ex[c4 + -1 * c5 + - 1][c5] - 0.5 * (hz[c4 + -1 * c5 + - 1][c5] - hz[c4 + -1 * c5 + - 1][c5 - 1]);
          ey[c4 + -1 * c5][c5 + - 1] = ey[c4 + -1 * c5][c5 + - 1] - 0.5 * (hz[c4 + -1 * c5][c5 + - 1] - hz[c4 + -1 * c5 - 1][c5 + - 1]);
          hz[- 1 * 0 + (c4 + -1 * c5) + - 1][- 1 * 0 + c5 + - 1] = hz[- 1 * 0 + (c4 + -1 * c5) + - 1][- 1 * 0 + c5 + - 1] - 0.7 * (ex[- 1 * 0 + (c4 + -1 * c5) + - 1][- 1 * 0 + c5 + - 1 + 1] - ex[- 1 * 0 + (c4 + -1 * c5) + - 1][- 1 * 0 + c5 + - 1] + ey[- 1 * 0 + (c4 + -1 * c5) + - 1 + 1][- 1 * 0 + c5 + - 1] - ey[- 1 * 0 + (c4 + -1 * c5) + - 1][- 1 * 0 + c5 + - 1]);
        }
      }
      for (c4 = 25; c4 <= 30; c4++) {
        for (c5 = c4 + -15; c5 <= 15; c5++) {
          ex[c4 + -1 * c5 + - 1][c5] = ex[c4 + -1 * c5 + - 1][c5] - 0.5 * (hz[c4 + -1 * c5 + - 1][c5] - hz[c4 + -1 * c5 + - 1][c5 - 1]);
          ey[c4 + -1 * c5][c5 + - 1] = ey[c4 + -1 * c5][c5 + - 1] - 0.5 * (hz[c4 + -1 * c5][c5 + - 1] - hz[c4 + -1 * c5 - 1][c5 + - 1]);
          hz[- 1 * 0 + (c4 + -1 * c5) + - 1][- 1 * 0 + c5 + - 1] = hz[- 1 * 0 + (c4 + -1 * c5) + - 1][- 1 * 0 + c5 + - 1] - 0.7 * (ex[- 1 * 0 + (c4 + -1 * c5) + - 1][- 1 * 0 + c5 + - 1 + 1] - ex[- 1 * 0 + (c4 + -1 * c5) + - 1][- 1 * 0 + c5 + - 1] + ey[- 1 * 0 + (c4 + -1 * c5) + - 1 + 1][- 1 * 0 + c5 + - 1] - ey[- 1 * 0 + (c4 + -1 * c5) + - 1][- 1 * 0 + c5 + - 1]);
        }
      }
      ey[0][0] = _fict_[1];
      ex[0][2 + - 1] = ex[0][2 + - 1] - 0.5 * (hz[0][2 + - 1] - hz[0][2 + - 1 - 1]);
      ey[0][2 + - 1] = _fict_[1];
      ey[2 + - 1][0] = ey[2 + - 1][0] - 0.5 * (hz[2 + - 1][0] - hz[2 + - 1 - 1][0]);
      ex[0][3 + - 1] = ex[0][3 + - 1] - 0.5 * (hz[0][3 + - 1] - hz[0][3 + - 1 - 1]);
      ey[0][3 + - 1] = _fict_[1];
      for (c4 = 4; c4 <= 16; c4++) {
        ey[c4 + -1 + - 1][0] = ey[c4 + -1 + - 1][0] - 0.5 * (hz[c4 + -1 + - 1][0] - hz[c4 + -1 + - 1 - 1][0]);
        for (c5 = 2; c5 <= c4 + -2; c5++) {
          ey[c4 + -1 * c5 + - 1][c5 + - 1] = ey[c4 + -1 * c5 + - 1][c5 + - 1] - 0.5 * (hz[c4 + -1 * c5 + - 1][c5 + - 1] - hz[c4 + -1 * c5 + - 1 - 1][c5 + - 1]);
          ex[c4 + -1 * c5 + - 1][c5 + - 1] = ex[c4 + -1 * c5 + - 1][c5 + - 1] - 0.5 * (hz[c4 + -1 * c5 + - 1][c5 + - 1] - hz[c4 + -1 * c5 + - 1][c5 + - 1 - 1]);
          hz[- 1 * 1 + (c4 + -1 * c5) + - 1][- 1 * 1 + c5 + - 1] = hz[- 1 * 1 + (c4 + -1 * c5) + - 1][- 1 * 1 + c5 + - 1] - 0.7 * (ex[- 1 * 1 + (c4 + -1 * c5) + - 1][- 1 * 1 + c5 + - 1 + 1] - ex[- 1 * 1 + (c4 + -1 * c5) + - 1][- 1 * 1 + c5 + - 1] + ey[- 1 * 1 + (c4 + -1 * c5) + - 1 + 1][- 1 * 1 + c5 + - 1] - ey[- 1 * 1 + (c4 + -1 * c5) + - 1][- 1 * 1 + c5 + - 1]);
        }
        ex[0][c4 + - 1] = ex[0][c4 + - 1] - 0.5 * (hz[0][c4 + - 1] - hz[0][c4 + - 1 - 1]);
        ey[0][c4 + - 1] = _fict_[1];
      }
      ey[16 + - 1][0] = ey[16 + - 1][0] - 0.5 * (hz[16 + - 1][0] - hz[16 + - 1 - 1][0]);
      for (c5 = 2; c5 <= 15; c5++) {
        ey[-1 * c5 + 17 + - 1][c5 + - 1] = ey[-1 * c5 + 17 + - 1][c5 + - 1] - 0.5 * (hz[-1 * c5 + 17 + - 1][c5 + - 1] - hz[-1 * c5 + 17 + - 1 - 1][c5 + - 1]);
        ex[-1 * c5 + 17 + - 1][c5 + - 1] = ex[-1 * c5 + 17 + - 1][c5 + - 1] - 0.5 * (hz[-1 * c5 + 17 + - 1][c5 + - 1] - hz[-1 * c5 + 17 + - 1][c5 + - 1 - 1]);
        hz[- 1 * 1 + (-1 * c5 + 17) + - 1][- 1 * 1 + c5 + - 1] = hz[- 1 * 1 + (-1 * c5 + 17) + - 1][- 1 * 1 + c5 + - 1] - 0.7 * (ex[- 1 * 1 + (-1 * c5 + 17) + - 1][- 1 * 1 + c5 + - 1 + 1] - ex[- 1 * 1 + (-1 * c5 + 17) + - 1][- 1 * 1 + c5 + - 1] + ey[- 1 * 1 + (-1 * c5 + 17) + - 1 + 1][- 1 * 1 + c5 + - 1] - ey[- 1 * 1 + (-1 * c5 + 17) + - 1][- 1 * 1 + c5 + - 1]);
      }
      for (c4 = 18; c4 <= 32; c4++) {
        for (c5 = c4 + -16; c5 <= 16; c5++) {
          ey[c4 + -1 * c5 + - 1][c5 + - 1] = ey[c4 + -1 * c5 + - 1][c5 + - 1] - 0.5 * (hz[c4 + -1 * c5 + - 1][c5 + - 1] - hz[c4 + -1 * c5 + - 1 - 1][c5 + - 1]);
          ex[c4 + -1 * c5 + - 1][c5 + - 1] = ex[c4 + -1 * c5 + - 1][c5 + - 1] - 0.5 * (hz[c4 + -1 * c5 + - 1][c5 + - 1] - hz[c4 + -1 * c5 + - 1][c5 + - 1 - 1]);
          hz[- 1 * 1 + (c4 + -1 * c5) + - 1][- 1 * 1 + c5 + - 1] = hz[- 1 * 1 + (c4 + -1 * c5) + - 1][- 1 * 1 + c5 + - 1] - 0.7 * (ex[- 1 * 1 + (c4 + -1 * c5) + - 1][- 1 * 1 + c5 + - 1 + 1] - ex[- 1 * 1 + (c4 + -1 * c5) + - 1][- 1 * 1 + c5 + - 1] + ey[- 1 * 1 + (c4 + -1 * c5) + - 1 + 1][- 1 * 1 + c5 + - 1] - ey[- 1 * 1 + (c4 + -1 * c5) + - 1][- 1 * 1 + c5 + - 1]);
        }
      }
    }
  }
  
#pragma endscop
  return 0;
}
