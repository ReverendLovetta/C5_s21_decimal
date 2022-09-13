//Округляет Decimal до ближайшего целого числа.
#include "s21_decimal.h"

// Функция для прибавления любой степени двойки к числу типа децимал, при чем
// экспонента это стпень двойки а не само число

void slozhenie(s21_decimal *dst, int exponent) {
  if (exponent >= 64) {
    if ((dst->bits[2] & 1 << (exponent - 64)) == 0) {
      dst->bits[2] |= 1 << (exponent - 64);
    } else {
      dst->bits[2] -= pow(2, (exponent - 64));
      exponent += 1;
      slozhenie(dst, exponent);
    }
  } else if (exponent >= 32) {
    if ((dst->bits[1] & 1 << (exponent - 32)) == 0) {
      dst->bits[1] |= 1 << (exponent - 32);
    } else {
      dst->bits[1] -= pow(2, (exponent - 32));
      exponent += 1;
      slozhenie(dst, exponent);
    }
  } else {
    if ((dst->bits[0] & 1 << exponent) == 0) {
      dst->bits[0] |= 1 << exponent;
    } else {
      dst->bits[0] -= pow(2, exponent);
      exponent += 1;
      slozhenie(dst, exponent);
    }
  }
}

int s21_round(s21_decimal value, s21_decimal *result) {
  result->bits[0] = 0;
  result->bits[1] = 0;
  result->bits[2] = 0;
  result->bits[3] = 0;
  int status = 0;
  char d[1024];
  dec_output(&value, d);
  if (d != NULL) {
    char *ukaz = d;
    while (1) {
      if (*ukaz == '\0') {
        s21_truncate(value, result);
        break;
      }
      if (*ukaz == '.') {
        if (*(ukaz + 1) >= '5') {
          s21_truncate(value, result);
          slozhenie(result, 0);
        } else {
          s21_truncate(value, result);
        }
        break;
      }
      ukaz++;
    }
  } else {
    status = 1;
  }
  return status;
}
