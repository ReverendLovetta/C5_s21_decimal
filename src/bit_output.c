#include "./s21_decimal.h"

int bit_output(s21_decimal *a) {
  size_t len = sizeof(int) * CHAR_BIT;
  for (int j = 0; j < 4; j++) {
    printf("bits%d\t", j);
    for (int k = 31; k >= 0; k--) {
      if (k < 10)
        printf("%-2d ", k);
      else
        printf("%-3d", k);
    }
    printf("\n\t");
    for (size_t i = len; i > 0; i--) {
      if (checkbit(a->bits[j], i - 1) == 1)
        printf("\x1b[31m%-2d\x1b[0m ", checkbit(a->bits[j], i - 1));
      else
        printf("%-2d ", checkbit(a->bits[j], i - 1));
    }
    printf("\n\n");
  }
  return 0;
}
