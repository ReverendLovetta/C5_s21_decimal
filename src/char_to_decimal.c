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

int check_thebigest_int(char *string1, char *string2);
char *subtraction_str_num(char *stirng1, char *string2);

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

void binary_conversion(char *string, s21_decimal *value) {
  char mass_mod[strlen(string) + 1];
  char mass_temp[strlen(string) + 1];
  memset(mass_mod, '\0', strlen(string) + 1);
  memset(mass_temp, '\0', strlen(string) + 1);
  mass_mod[0] = '1';
  int exp = 0;
  while (check_thebigest_int(string, mass_temp) > 0) {
    while (check_thebigest_int(string, mass_mod) > 0) {
      if (mult_by_2(mass_mod, mass_mod) != 0) {
        sprintf(stderr, "Не удалось умножить число на 2");
        break;
      }
      exp += 1;
    }
    mass_temp = check_thebigest_int(string, mass_mod);
  }
}

int check_thebigest_int(char *string1, char *string2) {
  int res = 0;
  if (strlen(string1) > strlen(string2)) {
    res = 1;
  } else if (strlen(string1) < strlen(string2)) {
    res = -1;
  } else {
    res = strcmp(string1, string2);
  }
  return res;
}

char *subtraction_str_num(char *string1, char *string2) {
  char res[strlen(string1) + 1];
  memset(res, '\0', strlen(string1) + 1);
  int tmp = 0;
  int count = 0;
  for (int i = strlen(string1); i > 0; i--) {
    if ((*(string1 + strlen(string1) - i)) >=
        (*(string2 + strlen(string2) - i))) {
      tmp = ((*(string1 + strlen(string1) - i)) - '0') -
            ((*(string2 + strlen(string2) - i)) - '0');
      res[strlen(string1) - i] = tmp + '0';
    } else {
      count = 0;
      while ((*(string1 + strlen(string1) - i)) == 0) {
        count++;
        (*(string1 + strlen(string1) - i)) = '9';
        i--;
      }
      (*(string1 + strlen(string1) - i)) =
          (*(string1 + strlen(string1) - i)) - 1;
      i = i + count;
    }
  }
}