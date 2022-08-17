#include "./s21_decimal.h"

int add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int exit_code = 0;
  if (checkbit(value_1.bits[3], MAX_INT_SHIFT) == 1 &&
      checkbit(value_2.bits[3], MAX_INT_SHIFT) == 1) {
    printf("Функция для сложения двух децимал\n");
  } else if (checkbit(value_1.bits[3], MAX_INT_SHIFT) == 0 &&
             checkbit(value_2.bits[3], MAX_INT_SHIFT) == 0) {
    add(value_1, value_2, result);
  } else {
    printf("Функции вычитания большего числа из меньшего\n");
  }
  for (int i = 0; i < 4; i++) {
    result->bits[i] = value_1.bits[i];
  }
  return exit_code;
}

// Если число float, то проверить последний знак. Если 0, то порядок надо
// умножить на 10

int add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  printf("Come in\n");
  int carry = 0;
  int temp = 0;
  int counter = 0;
  for (int i = 0; i < 1; i++) {
    for (int j = 0; j <= MAX_INT_SHIFT; j++) {
      temp = checkbit(value_1.bits[i], j) + checkbit(value_2.bits[i], j);
      printf("ITERATION %d ", counter);
      counter++;
      if (temp == 0) {
        printf("temp = 0: \n");
        if (carry == 1) {
          result->bits[i] |= (int)pow(2, j);
          carry = 0;
        }
      } else if (temp == 1) {
        printf("temp = 1: \n");
        if (carry == 1)
          continue;
        else
          result->bits[i] |= (int)pow(2, j);
      } else if (temp > 1) {
        printf("temp > 1: \n");
        if (carry == 1)
          result->bits[i] |= (int)pow(2, j);
        else
          carry = 1;
      }
    }
  }
  return (carry == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
