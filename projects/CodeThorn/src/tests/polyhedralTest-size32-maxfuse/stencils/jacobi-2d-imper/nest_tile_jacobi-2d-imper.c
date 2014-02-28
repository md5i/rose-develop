#   define TSTEPS STEPSIZE
#   define N ARRAYSIZE
# define _PB_TSTEPS STEPSIZE 
# define _PB_N ARRAYSIZE 

int main(int argc,char **argv)
{
/* Retrieve problem size. */
  int n = 32;
  int tsteps = 2;
/* Variable declaration/allocation. */
  double A[32][32];
  double B[32][32];
  int t;
  int i;
  int j;
  
#pragma scop
{
    int c2;
    int c4;
    int c0;
    int c3;
    for (c0 = 0; c0 <= 8; c0++) {
      for (c2 = (1 > 4 * c0 + -29?1 : 4 * c0 + -29); c2 <= ((33 < 2 * c0 + 32?33 : 2 * c0 + 32)); c2++) {
        if (c0 <= (((c2 + -1) * 4 < 0?((4 < 0?-((-(c2 + -1) + 4 + 1) / 4) : -((-(c2 + -1) + 4 - 1) / 4))) : (c2 + -1) / 4)) && c2 >= 31) {
          if ((c2 + 1) % 2 == 0) {
            for (c4 = (4 * c0 > c2 + -29?4 * c0 : c2 + -29); c4 <= ((c2 < 4 * c0 + 3?c2 : 4 * c0 + 3)); c4++) {
              A[-1 * c2 + c4 + 30][30] = B[-1 * c2 + c4 + 30][30];
            }
          }
        }
        for (c3 = (((0 > (((c2 + -30) * 2 < 0?-(-(c2 + -30) / 2) : ((2 < 0?(-(c2 + -30) + - 2 - 1) / - 2 : (c2 + -30 + 2 - 1) / 2))))?0 : (((c2 + -30) * 2 < 0?-(-(c2 + -30) / 2) : ((2 < 0?(-(c2 + -30) + - 2 - 1) / - 2 : (c2 + -30 + 2 - 1) / 2)))))) > 2 * c0 + -15?((0 > (((c2 + -30) * 2 < 0?-(-(c2 + -30) / 2) : ((2 < 0?(-(c2 + -30) + - 2 - 1) / - 2 : (c2 + -30 + 2 - 1) / 2))))?0 : (((c2 + -30) * 2 < 0?-(-(c2 + -30) / 2) : ((2 < 0?(-(c2 + -30) + - 2 - 1) / - 2 : (c2 + -30 + 2 - 1) / 2)))))) : 2 * c0 + -15); c3 <= ((((1 < (((c2 + -2) * 2 < 0?((2 < 0?-((-(c2 + -2) + 2 + 1) / 2) : -((-(c2 + -2) + 2 - 1) / 2))) : (c2 + -2) / 2))?1 : (((c2 + -2) * 2 < 0?((2 < 0?-((-(c2 + -2) + 2 + 1) / 2) : -((-(c2 + -2) + 2 - 1) / 2))) : (c2 + -2) / 2)))) < 2 * c0?((1 < (((c2 + -2) * 2 < 0?((2 < 0?-((-(c2 + -2) + 2 + 1) / 2) : -((-(c2 + -2) + 2 - 1) / 2))) : (c2 + -2) / 2))?1 : (((c2 + -2) * 2 < 0?((2 < 0?-((-(c2 + -2) + 2 + 1) / 2) : -((-(c2 + -2) + 2 - 1) / 2))) : (c2 + -2) / 2)))) : 2 * c0)); c3++) {
          if (c0 == 0 && c3 == 0) {
            B[1][c2] = 0.2 * (A[1][c2] + A[1][c2 - 1] + A[1][1 + c2] + A[1 + 1][c2] + A[1 - 1][c2]);
          }
          for (c4 = (4 * c0 > 2 * c3 + 2?4 * c0 : 2 * c3 + 2); c4 <= ((4 * c0 + 3 < 2 * c3 + 30?4 * c0 + 3 : 2 * c3 + 30)); c4++) {
            A[-2 * c3 + c4 + -1][c2 + -2 * c3 + -1] = B[-2 * c3 + c4 + -1][c2 + -2 * c3 + -1];
            B[-2 * c3 + c4][c2 + -2 * c3] = 0.2 * (A[-2 * c3 + c4][c2 + -2 * c3] + A[-2 * c3 + c4][c2 + -2 * c3 - 1] + A[-2 * c3 + c4][1 + (c2 + -2 * c3)] + A[1 + (-2 * c3 + c4)][c2 + -2 * c3] + A[-2 * c3 + c4 - 1][c2 + -2 * c3]);
          }
          if (c0 == c3 + 7) {
            A[30][-2 * c0 + c2 + 13] = B[30][-2 * c0 + c2 + 13];
          }
        }
        if (c0 >= (((c2 + -1) * 4 < 0?-(-(c2 + -1) / 4) : ((4 < 0?(-(c2 + -1) + - 4 - 1) / - 4 : (c2 + -1 + 4 - 1) / 4)))) && c2 <= 3) {
          if ((c2 + 1) % 2 == 0) {
            for (c4 = (4 * c0 > c2?4 * c0 : c2); c4 <= ((4 * c0 + 3 < c2 + 29?4 * c0 + 3 : c2 + 29)); c4++) {
              B[-1 * c2 + c4 + 1][1] = 0.2 * (A[-1 * c2 + c4 + 1][1] + A[-1 * c2 + c4 + 1][1 - 1] + A[-1 * c2 + c4 + 1][1 + 1] + A[1 + (-1 * c2 + c4 + 1)][1] + A[-1 * c2 + c4 + 1 - 1][1]);
            }
          }
        }
        if (c0 == 0 && c2 >= 3) {
          B[1][c2 + -2] = 0.2 * (A[1][c2 + -2] + A[1][c2 + -2 - 1] + A[1][1 + (c2 + -2)] + A[1 + 1][c2 + -2] + A[1 - 1][c2 + -2]);
        }
      }
    }
  }
  
#pragma endscop
  return 0;
}
