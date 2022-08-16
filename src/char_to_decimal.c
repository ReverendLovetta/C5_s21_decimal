/* Функция char_to_decimal(char *string).
 * Конвертирует строку, в которую записано число в число с типом decimal.
 */

#include "s21_decimal.h"

#define MAX_VALUE 96  // Максимальное кол-во битов в 3-х int

int find_point(char *string);  // Поиск начала дробной части
void delete_point(
    char *string,
    s21_decimal *value);  // Запись количества разрядов в структуру числа
                          // decimal и удаления точки из строки
void binary_conversion(
    char *string,
    s21_decimal *value);  // Перевод числа из десятичной системы счисления в
                          // двоичную и запись разрядов в структуре decimal

s21_decimal char_to_decimal(char *string) {
  s21_decimal result;
  int binary_mass[MAX_VALUE + 1];
  if (find_point(string) == 0) {
    delete_point(string, &result);
  }
  binary_conversion(string, &result);
  return result;
}