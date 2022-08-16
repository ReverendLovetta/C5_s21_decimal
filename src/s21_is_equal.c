#include "s21_decimal.h"

int s21_is_equal(s21_decimal src, s21_decimal dst) {
  int status = 0;
  char d[1024] = "";
  dec_output(&src, d);
  char d1[1024] = "";
  dec_output(&dst, d1);
  if (src.bits[0] == 0 && src.bits[1] == 0 && src.bits[2] == 0 &&
      dst.bits[0] == 0 && dst.bits[1] == 0 && dst.bits[2] == 0) {
    status = 1;
  } else {
    if (strcmp(d, d1) == 0) {
      status = 1;
    }
  }
  return status;
}