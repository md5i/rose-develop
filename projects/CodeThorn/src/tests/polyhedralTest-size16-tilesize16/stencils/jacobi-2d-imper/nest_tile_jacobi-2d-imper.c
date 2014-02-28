#   define TSTEPS STEPSIZE
#   define N ARRAYSIZE
# define _PB_TSTEPS STEPSIZE 
# define _PB_N ARRAYSIZE 

int main(int argc,char **argv)
{
/* Retrieve problem size. */
  int n = 16;
  int tsteps = 2;
/* Variable declaration/allocation. */
  double A[16][16];
  double B[16][16];
  int t;
  int i;
  int j;
  
#pragma scop
{
    int c4;
    int c0;
    int c2;
    int c3;
    for (c0 = 0; c0 <= 1; c0++) {
      for (c2 = (1 > 16 * c0 + -13?1 : 16 * c0 + -13); c2 <= 17; c2++) {
        if (c0 <= (((c2 + -1) * 16 < 0?((16 < 0?-((-(c2 + -1) + 16 + 1) / 16) : -((-(c2 + -1) + 16 - 1) / 16))) : (c2 + -1) / 16)) && c2 >= 15) {
          if ((c2 + 1) % 2 == 0) {
            for (c4 = (16 * c0 > c2 + -13?16 * c0 : c2 + -13); c4 <= ((c2 < 16 * c0 + 15?c2 : 16 * c0 + 15)); c4++) {
              A[-1 * c2 + c4 + 14][14] = B[-1 * c2 + c4 + 14][14];
            }
          }
        }
        for (c3 = (((0 > (((c2 + -14) * 2 < 0?-(-(c2 + -14) / 2) : ((2 < 0?(-(c2 + -14) + - 2 - 1) / - 2 : (c2 + -14 + 2 - 1) / 2))))?0 : (((c2 + -14) * 2 < 0?-(-(c2 + -14) / 2) : ((2 < 0?(-(c2 + -14) + - 2 - 1) / - 2 : (c2 + -14 + 2 - 1) / 2)))))) > 8 * c0 + -7?((0 > (((c2 + -14) * 2 < 0?-(-(c2 + -14) / 2) : ((2 < 0?(-(c2 + -14) + - 2 - 1) / - 2 : (c2 + -14 + 2 - 1) / 2))))?0 : (((c2 + -14) * 2 < 0?-(-(c2 + -14) / 2) : ((2 < 0?(-(c2 + -14) + - 2 - 1) / - 2 : (c2 + -14 + 2 - 1) / 2)))))) : 8 * c0 + -7); c3 <= ((1 < (((c2 + -2) * 2 < 0?((2 < 0?-((-(c2 + -2) + 2 + 1) / 2) : -((-(c2 + -2) + 2 - 1) / 2))) : (c2 + -2) / 2))?1 : (((c2 + -2) * 2 < 0?((2 < 0?-((-(c2 + -2) + 2 + 1) / 2) : -((-(c2 + -2) + 2 - 1) / 2))) : (c2 + -2) / 2)))); c3++) {
          if (c0 == 0) {
            B[1][c2 + -2 * c3] = 0.2 * (A[1][c2 + -2 * c3] + A[1][c2 + -2 * c3 - 1] + A[1][1 + (c2 + -2 * c3)] + A[1 + 1][c2 + -2 * c3] + A[1 - 1][c2 + -2 * c3]);
          }
          for (c4 = (16 * c0 > 2 * c3 + 2?16 * c0 : 2 * c3 + 2); c4 <= ((16 * c0 + 15 < 2 * c3 + 14?16 * c0 + 15 : 2 * c3 + 14)); c4++) {
            A[-2 * c3 + c4 + -1][c2 + -2 * c3 + -1] = B[-2 * c3 + c4 + -1][c2 + -2 * c3 + -1];
            B[-2 * c3 + c4][c2 + -2 * c3] = 0.2 * (A[-2 * c3 + c4][c2 + -2 * c3] + A[-2 * c3 + c4][c2 + -2 * c3 - 1] + A[-2 * c3 + c4][1 + (c2 + -2 * c3)] + A[1 + (-2 * c3 + c4)][c2 + -2 * c3] + A[-2 * c3 + c4 - 1][c2 + -2 * c3]);
          }
          if (c0 == c3) {
            A[14][-2 * c0 + c2 + -1] = B[14][-2 * c0 + c2 + -1];
          }
        }
        if (c2 <= 3) {
          if ((c2 + 1) % 2 == 0) {
            for (c4 = (16 * c0 > c2?16 * c0 : c2); c4 <= ((16 * c0 + 15 < c2 + 13?16 * c0 + 15 : c2 + 13)); c4++) {
              B[-1 * c2 + c4 + 1][1] = 0.2 * (A[-1 * c2 + c4 + 1][1] + A[-1 * c2 + c4 + 1][1 - 1] + A[-1 * c2 + c4 + 1][1 + 1] + A[1 + (-1 * c2 + c4 + 1)][1] + A[-1 * c2 + c4 + 1 - 1][1]);
            }
          }
        }
      }
    }
  }
  
#pragma endscop
  return 0;
}
