/*
Функция для сдложения двух децимал. Принимает 2 числа децимал, которые надо
сложить и указатель для записи результата. Сложение осуществляется в случае,
если оба числа положительные и если оба числа отрицательные. Для сложения
положительного и отрицательного числа используется функция вычитания
*/

#include "./s21_decimal.h"

// Собственно, само сложение
int add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result,
        int sign);

// Приведение числа с точкой к целому значению. Функция дорисовывает недостающие
// нули
char *aligner(char *dec, char *temp_dec, int diff);

// Определение разницы между двумя числами и возврат разницы
int shift_diff(int shift1, int shift2);

// Определение максимальной дробной части
size_t max_shift(int shift1, int shift2);
// Common s21_mul
int size_check(char *dec);

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int exit_code = 0;
  // Если оба числа отрицательные
  if (checkbit(value_1.bits[3], MAX_INT_SHIFT) == 1 &&
      checkbit(value_2.bits[3], MAX_INT_SHIFT) == 1) {
    // Сначала привести отрицательные числа к положительному
    s21_negate(value_1, &value_1);
    s21_negate(value_2, &value_2);
    exit_code = add(value_1, value_2, result, NEGATIVE);
    // Умножить результат на -1
    s21_negate(*result, result);

    // Если оба числа положительные
  } else if (checkbit(value_1.bits[3], MAX_INT_SHIFT) == 0 &&
             checkbit(value_2.bits[3], MAX_INT_SHIFT) == 0) {
    exit_code = add(value_1, value_2, result, POSITIVE);

    // Вычитание, если одно число положительное, другое отрицательное
  } else {
    printf("Функции вычитания большего числа из меньшего\n");
  }
  return exit_code;
}

int add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result,
        int sign) {
  int add_result = 0;
  char dec1[BUF] = {'\0'};
  char dec2[BUF] = {'\0'};
  dec_to_string(&value_1, dec1);
  dec_to_string(&value_2, dec2);
  // Считаем количество символов после точки у двух чисел
  int shift1 = digits_aft_dot(dec1) - 1;
  int shift2 = digits_aft_dot(dec2) - 1;
  char temp_dec1[BUF] = {'\0'};
  char temp_dec2[BUF] = {'\0'};
  // Выравниваем дробную часть у двух чисел, добавляя недостающие нули и убирая
  // точку
  aligner(dec1, temp_dec1, shift_diff(shift1, shift2));
  aligner(dec2, temp_dec2, shift_diff(shift2, shift1));

  // Переворот строк задом наперёд
  revers(temp_dec1, (int)strlen(temp_dec1));
  revers(temp_dec2, (int)strlen(temp_dec2));
  char res[BUF] = {'\0'};
  // Складываем две строки
  summ_two_string(temp_dec1, temp_dec2, res);
  // Добавляем точку
  dot_insert(res, max_shift(shift1, shift2));
  revers(res, (int)strlen(res));
  // Округляем значение и присваиваем код возврата
  char temp[BUF] = {'\0'};
  // strcpy(temp, "792283069363.9437672339112924639");
  strcpy(temp, res);
  add_result = bank_round(temp, sign);

  memset(res, '\0', BUF);
  strcpy(res, temp);
  // Переворачиваем строку для удаления лишних нулей, если есть дробная часть
  if (max_shift(shift1, shift2) != 0) {
    revers(res, (int)strlen(res));
    zero_cutter(res);
    // Возвращаем строку в нормальный порядок
    revers(res, (int)strlen(res));
  }

  *result = char_to_decimal(res);

  char in_add_res[BUF] = {'\0'};
  dec_to_string(result, in_add_res);
  return add_result;
}

int shift_diff(int shift1, int shift2) {
  if (shift1 < 0) shift1 = 0;
  if (shift2 < 0) shift2 = 0;
  return (shift1 >= shift2) ? 0 : shift2 - shift1;
}

char *aligner(char *dec, char *temp_dec, int shift) {
  int length = (int)strlen(dec);
  // Copy dec to temp_dec without dot
  for (int i = 0, j = 0; i < length; i++) {
    if (dec[i] != '.') {
      temp_dec[j] = dec[i];
      j++;
    }
  }
  // Fill temp_dec with zeroes at the end
  for (int i = 0; i < shift; i++) {
    temp_dec[(length - 1) + i] = '0';
  }
  return temp_dec;
}

size_t max_shift(int shift1, int shift2) {
  return (shift1 >= shift2) ? shift1 : shift2;
}
