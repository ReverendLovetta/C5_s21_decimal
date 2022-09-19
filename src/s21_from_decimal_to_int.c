// Конвертация числа из типа децимал в тип инт
#include "s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  char d[1024];
  dec_to_string(&src, d);
  printf("stroka=%s\n", d);
  *dst = atoi(d);
  return 0;
}

int main() {
  char s21_result[BUF];
  char result[BUF];
  memset(result, '\0', BUF);
  memset(s21_result, '\0', BUF);
  int int_result = 3.14;
  int s21_int_result = 0;
  s21_decimal number = {0};
  number.bits[0] = 314;
  number.bits[1] = 0;
  number.bits[2] = 0;
  number.bits[3] = 0;
  zapis_stepeni_v_decimal(2, &number);
  s21_from_decimal_to_int(number, &s21_int_result);
  sprintf(result, "%d", int_result);
  sprintf(s21_result, "%d", s21_int_result);
  char res[] = "3.14";
  s21_decimal number2 = {0};
  number2 = char_to_decimal(res);
  bit_output(&number2);
}