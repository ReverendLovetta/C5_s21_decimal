#include "./s21_decimal.h"

void zapis_stepeni_v_decimal(int a, s21_decimal *dst) {
  if (a <= 28 && a >= 0) {
    for (int i = 21; i >= 16; i--) {
      if (a - pow(2, i - 16) >= 0) {
        a = a - pow(2, i - 16);
        dst->bits[3] |= 1 << i;
      }
    }
  }
}
