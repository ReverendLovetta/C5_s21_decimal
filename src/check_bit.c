#include "./s21_decimal.h"

int checkbit(const unsigned int value, const unsigned int position) {
  return ((value & (1 << position)) != 0);
}
