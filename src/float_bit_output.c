#include "./s21_decimal.h"

void float_bit_output(float *a) {
  size_t len = sizeof(float) * CHAR_BIT;
  // printf("%li\n", sizeof(float));
  int n = *((int *)a);
  printf("%d\n", n);
  for (int k = 31; k >= 0; k--) {
    if (k < 10)
      printf("%-2d ", k);
    else
      printf("%-3d", k);
  }
  printf("\n");
  for (size_t i = len; i > 0; i--) {
    if (checkbit(n, i - 1) == 1)
      printf("\x1b[31m%-2d\x1b[0m ", checkbit(n, i - 1));
    else
      printf("%-2d ", checkbit(n, i - 1));
  }
  printf("\n");
}
