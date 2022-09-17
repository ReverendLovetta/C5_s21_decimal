#include "./s21_decimal.h"

#define PERIOD_START 16
#define PERIOD_END 23

int exp_string(char *result, int degree);
long double period_calc(int a);

int dec_to_string(s21_decimal *a, char *main_result) {
  size_t len = sizeof(int) * CHAR_BIT;
  long double period = 1;
  char result[BUF], mid_result[BUF];
  memset(result, '\0', BUF);
  memset(mid_result, '\0', BUF);
  memset(main_result, '\0', BUF);
  period = period_calc(a->bits[3]);
  result[0] = '0';
  mid_result[0] = '0';
  int degree = -1;
  for (int i = 0; i < 3; i++) {
    for (size_t j = 0; j < len; j++) {
      memset(mid_result, '\0', BUF);
      degree++;
      if (checkbit(a->bits[i], j) == 1) {
        exp_string(mid_result, degree);
        summ_two_string(result, mid_result, result);
      }
    }
  }
  char period_string[BUF];
  memset(period_string, '\0', BUF);
  sprintf(period_string, "%0.LF", period);
  size_t result_length = strlen(result), period_length = strlen(period_string);
  while (result_length < period_length) {
    result[result_length] = '0';
    result_length++;
  }
  if ((checkbit(a->bits[3], MAX_INT_SHIFT) == 1) &&
      (a->bits[0] != 0 || a->bits[1] != 0 || a->bits[2] != 0))
    result[strlen(result)] = '-';
  // Функция для добавляния точки в число
  dot_insert(result, period_length);
  revers(result, strlen(result));
  strcpy(main_result, result);
  return EXIT_SUCCESS;
}

int mult_by_2(char *a, char *result) {
  int carry = 0;
  int interm = 0;
  size_t i = 0;
  for (; i < strlen(a); i++) {
    if ((interm = ((a[i] - '0') * 2 + carry)) > 9) {
      carry = (interm - interm % 10) / 10;
    }
    result[i] = interm % 10 + 48;
    if (interm < 10) carry = 0;
  }
  if (carry > 0) result[i] = carry + 48;
  return EXIT_SUCCESS;
}

int exp_string(char *result, int degree) {
  result[0] = '2';
  if (degree == 0)
    result[0] = '1';
  else if (degree == 1) {
    result[0] = '2';
  } else
    for (int i = 0; i < (degree - 1); i++) {
      mult_by_2(result, result);
    }
  return EXIT_SUCCESS;
}

long double period_calc(int a) {
  long double base2_result = 0;
  for (int i = PERIOD_START; i <= PERIOD_END; i++) {
    if (checkbit(a, i) == 1) {
      base2_result = pow(2, i - 16) + base2_result;
    }
  }
  return pow(10, base2_result);
}
