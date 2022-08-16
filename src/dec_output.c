#include "./s21_decimal.h"

#define PERIOD_START 16
#define PERIOD_END 23

int mult_by_2(char *a, char *result);
int exp_string(char *result, int degree);
size_t max_lenght(char *num1, char *num2);
int char_to_int(char a);
int summ_two_string(char *num1, char *num2, char *result);
void revers(char *src, int size);
size_t period_calc(int a);
void dot_insert(char *result, size_t period);

int dec_output(s21_decimal *a, char *main_result) {
  size_t len = sizeof(int) * CHAR_BIT;
  size_t period = 1;
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
  if ((checkbit(a->bits[3], MAX_INT_SHIFT) == 1) &&
      (a->bits[0] != 0 || a->bits[1] != 0 || a->bits[2] != 0))
    result[strlen(result)] = '-';
  // Функция для добавляния точки в число
  dot_insert(result, period);
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

size_t max_lenght(char *num1, char *num2) {
  return (strlen(num1) >= strlen(num2)) ? strlen(num1) : strlen(num2);
}

int char_to_int(char a) { return (a <= '9' && a >= '0') ? a - '0' : 0; }

int summ_two_string(char *num1, char *num2, char *result) {
  int res = 0;
  size_t i = 0;
  int carry = 0;
  for (; i < max_lenght(num1, num2); i++) {
    if ((res = char_to_int(num1[i]) + char_to_int(num2[i]) + carry) > 9) {
      carry = (res - res % 10) / 10;
    }
    result[i] = res % 10 + 48;
    if (res < 10) carry = 0;
  }
  if (carry > 0) result[i] = carry + 48;
  return EXIT_SUCCESS;
}

void revers(char *src, int size) {
  int count = size;
  for (int i = 0; i < size / 2; i++) {
    char buff = src[i];
    src[i] = src[--count];
    src[count] = buff;
  }
}

size_t period_calc(int a) {
  size_t base2_result = 0;
  for (int i = PERIOD_START; i <= PERIOD_END; i++) {
    if (checkbit(a, i) == 1) {
      base2_result = pow(2, i - 16) + base2_result;
    }
  }
  return pow(10, base2_result);
}

void dot_insert(char *result, size_t period) {
  char temp[BUF];
  memset(temp, '\0', BUF);
  int j = 0, i = 0;
  size_t k = strlen(result);
  if (period == 1) {
    return;
  }
  while (period > 1) {
    if (result[j] == '\0')
      temp[i] = '0';
    else
      temp[i] = result[j];
    i++;
    j++;
    k--;
    period /= 10;
  }
  temp[i] = '.';
  i++;
  while (k > 0) {
    temp[i] = result[j];
    i++;
    j++;
    k--;
  }
  memset(result, '\0', BUF);
  strcpy(result, temp);
}
