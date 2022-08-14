#include "./s21_decimal.h"

float float_bit_output(float *a, float mantissa, int *exponent,
                       s21_decimal *dst, int *counter_step) {
  size_t len = sizeof(float) * CHAR_BIT;
  int n = *((int *)a);
  s21_decimal tmp_dec = {0};
  for (int k = 31; k >= 0; k--) {
    if (k < 10)
      printf("%-2d ", k);
    else
      printf("%-3d", k);
  }
  printf("\n");
  int nomer_bita = -8;
  int stolbik_32_bit = 0;
  for (size_t i = len; i > 0; i--, nomer_bita++) {
    if (i >= 23 && i <= 30 && checkbit(n, i) == 1) {
      *exponent += pow(2, i - 23);
    }
    if (i <= 24) {
      if (checkbit(n, i - 1) == 1) {
        float tmp = 1;
        if (i <= 23) {
          mantissa += tmp / pow(2, 24 - i);
          tmp_dec.bits[stolbik_32_bit] |= 1 << (i - 1);
        }
      }
    }
    if (checkbit(n, i - 1) == 1)
      printf("\x1b[31m%-2d\x1b[0m ", checkbit(n, i - 1));
    else
      printf("%-2d ", checkbit(n, i - 1));
  }
  if (*exponent - 127 >= 23) {
    perezapis_decimal(&tmp_dec, dst, exponent);
  } else {
    *counter_step = 0;
    mantissa = 0;
    *exponent = 0;
    perezapis_decimal_exp_menshe_23(a, mantissa, exponent, dst, counter_step);
  }
  printf("\n");
  bit_output(dst);
  char d1[1024] = "";
  dec_output(dst, d1);
  printf("stroka=%s\n", d1);
  printf("exponent=%d\n", *exponent);
  printf("masntissa=%.28f\n", mantissa);
  return mantissa;
}
