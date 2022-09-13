// Конвертация числа из типа децимал в тип инт
#include "s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  char d[1024];
  dec_output(&src, d);
  *dst = atoi(d);
  return 0;
}
