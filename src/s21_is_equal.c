// Сравнивает децимал числа на равенства при равенсте 1 при неравенстве 0
#include "s21_decimal.h"

int s21_is_equal(s21_decimal src, s21_decimal dst) {
  int status = 0;
  char d[1024];
  dec_to_string(&src, d);
  char d1[1024];
  dec_to_string(&dst, d1);
  if (src.bits[0] == 0 && src.bits[1] == 0 && src.bits[2] == 0 &&
      dst.bits[0] == 0 && dst.bits[1] == 0 && dst.bits[2] == 0) {
    status = 1;
  } else {
    char *ukaz_first = d;
    char *ukaz_second = d1;
    while (*ukaz_first != '\0' && *ukaz_second != '\0') {
      if (*ukaz_first != *ukaz_second) {
        break;
      }
      ukaz_first++;
      ukaz_second++;
    }
    char *ukaz_tmp = NULL;
    if (*ukaz_first != '\0' || *ukaz_second != '\0') {
      if (*ukaz_first == '\0') {
        ukaz_tmp = ukaz_second;
      } else {
        ukaz_tmp = ukaz_first;
      }
      if (*ukaz_tmp == '.') {
        ukaz_tmp++;
        while (*ukaz_tmp != '\0') {
          if (*ukaz_tmp != '0') {
            status = 0;
            break;
          }
          ukaz_tmp++;
          status = 1;
        }
      }
    } else {
      status = 1;
    }
  }
  return status;
}

// int main() {
//   s21_decimal d = {0};
//   s21_decimal d1 = {0};
//   d.bits[0] = 2000;
//   d1.bits[0] = 20;
//   d.bits[3] |= SIGN;
//   d1.bits[3] |= SIGN;
//   char result[1024];
//   char result1[1024];
//   zapis_stepeni_v_decimal(2, &d);
//   dec_to_string(&d, result);
//   dec_to_string(&d1, result1);
//   printf("string=%s\n", result);
//   printf("string1=%s\n", result1);
//   s21_is_equal(d, d1);
//   return 0;
// }