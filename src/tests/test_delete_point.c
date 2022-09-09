#include "../s21_decimal.h"

void delete_point(char *string, unsigned int *value,
                  char *p_point);  // Запись количества разрядов в структуру
char *find_point(const char *string);  // Поиск начала дробной части
void setbit(unsigned int *value, const int position);

int main() {
  char mass[] = "13254.245264563234678956754745745745672345253623523514114341";
  s21_decimal value = {};
  char *p_point = NULL;
  if ((p_point = find_point(mass)) != NULL) {
    delete_point(mass, &value.bits[3], p_point);
  } else {
    setbit(&value.bits[3], 16);
  }
  return 0;
}

void delete_point(char *string, unsigned int *value, char *p_point) {
  int col = strlen(string) - (p_point - string);  // степень 10
  if (col > 28) {  // Ограничение на 28 разрядов, без округления числа
    col = 28;
  }
  *value = *value + col;
  *value = *value << 16;
  char fractional_part[col + 1];  // Хранить дробную часть
  strncpy(fractional_part, (p_point + 1), col * sizeof(char));
  strcpy(p_point, fractional_part);
}

char *find_point(const char *string) {
  char *p_point = NULL;
  char tmpmass[2] = ".";
  p_point = strstr(string, tmpmass);
  return p_point;
}

void setbit(unsigned int *value, const int position) {
  if (value != NULL) {
    *value = *value | (1 << position);
  }
}