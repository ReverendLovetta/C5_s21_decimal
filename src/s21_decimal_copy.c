#include "./s21_decimal.h"

int s21_decimal_copy(s21_decimal src, s21_decimal *dest) {
  for (int i = 0; i < 4; i++) {
    dest->bits[i] = src.bits[i];
  }
  return EXIT_SUCCESS;
}
