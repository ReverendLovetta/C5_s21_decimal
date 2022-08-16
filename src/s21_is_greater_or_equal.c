#include "s21_decimal.h"

int s21_is_greater_or_equal(s21_decimal src, s21_decimal dst) {
  int status = 0;
  if (s21_is_greater(src, dst) == 1 || s21_is_equal(src, dst) == 1) {
    status = 1;
  }
  return status;
}