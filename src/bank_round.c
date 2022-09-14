//это алгоритм округления величин до целых чисел, при котором числа,
//равноудаленные от двух ближайших целых чисел, округляются до ближайшего
//четного целого числа. равноудаленные это занчит 0.5-> 0, 1.5->2, 2,5->2 3,5->4
//Другие десятичные дроби округляются, как и следовало ожидать, — от 0,4 до 0,
//от 0,6 до 1, от 1,4 до 1, от 1,6 до 2 и т. д. Только числа x,5 получают
//«особую» обработку.
// Подается строка, над ней происходят манипуляции
// Cтрока обрабатывает строго до целого числа

#include "s21_decimal.h"
void my_truncate(char *string_of_number) {
  if (string_of_number != NULL) {
    char *ukaz = string_of_number;
    while (1) {
      if (*ukaz == '\0' || *ukaz == '.') {
        *ukaz = '\0';
        break;
      }
      ukaz++;
    }
  }
}

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

void bank_round(char *string_of_number) {
  if (string_of_number != NULL) {
    char *ukaz = string_of_number;
    while (1) {
      if (*ukaz == '\0') {
        break;
      }
      if (*ukaz == '.') {
        if (*(ukaz + 1) >= '5') {
          int number_before_dot = *(ukaz - 1) - '\0';
          int flag = 0;
          if (*(ukaz + 1) == '5') {
            ukaz += 1;
            while (*(ukaz + 1) != '\0') {
              if (*(ukaz + 1) != '0') {
                flag = 1;
                break;
              }
            }
          }
          if (flag == 1 || (flag == 0 && number_before_dot % 2 != 0)) {
            my_truncate(string_of_number);
            s21_decimal result_number = {0};
            result_number = char_to_decimal(string_of_number);
            slozhenie(&result_number, 0);
            dec_to_string(&result_number, string_of_number);
          } else {
            if (number_before_dot % 2 == 0) {
              my_truncate(string_of_number);
            }
          }
        } else {
          my_truncate(string_of_number);
        }
        break;
      }
      ukaz++;
    }
  }
}