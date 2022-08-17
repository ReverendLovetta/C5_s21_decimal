/* Функция char_to_decimal(char *string).
 * Конвертирует строку, в которую записано число в число с типом decimal.
 * Важно разделитель дробной части должен быть записан в виде "."
 */

#include "s21_decimal.h"

#define MAX_VALUE 96  // Максимальное кол-во битов в 3-х int

char *find_point(const char *string);  // Поиск начала дробной части
void delete_point(char *string, unsigned int *value,
                  char *p_point);  // Запись количества разрядов в структуру
                                   // числа decimal и удаления точки из строки
void binary_conversion(
    char *string,
    s21_decimal *value);  // Перевод числа из десятичной системы счисления в
                          // двоичную и запись разрядов в структуре decimal

s21_decimal char_to_decimal(char *string) {
  s21_decimal result = {0};

  int binary_mass[MAX_VALUE + 1];
  char *p_point = NULL;
  if ((p_point = find_point(string)) != NULL) {
    delete_point(string, &result.bits[3], p_point);
  } else {
    setbit(&result.bits[3], 16);
  }
  binary_conversion(string, &result);
  return result;
}

char *find_point(const char *string) {
  char *p_point = NULL;
  char tmpmass[2] = '.';
  p_point = strstr(string, tmpmass);
  return p_point;
}

void delete_point(char *string, unsigned int *value, char *p_point) {
  int col = strlen(string) - (p_point - string);  // степень 10
  *value = *value + col;
  *value = *value << 16;
  char fractional_part[col + 1];  // Хранить дробную часть
  strncpy(fractional_part, (p_point + 1), col);
  strcpy(p_point - 1, fractional_part);
}
