// Функция для выставления бита в указанную позицию

#include "s21_decimal.h"

void setbit(unsigned int *value, const int position) {
  if (value != NULL) {
    *value = *value | (1 << position);
  }
}
