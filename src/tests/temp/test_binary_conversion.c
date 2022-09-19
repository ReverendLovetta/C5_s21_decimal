#include <math.h>

#include "../s21_decimal.h"

void binary_conversion(char *str, s21_decimal *value);

int main() {
  s21_decimal value = {0};
  char str[] = "2933473472627543734627346275173473417346236217246262636857911";
  // char str2[BUF];
  // memset(str2, '\0', BUF - 1);
  binary_conversion(str, &value);
  value.bits[3] += 1 << 16;
  value.bits[3] += 1 << 31;
  puts("Все число в битах\n");
  printf("%u  :  %u  :  %u  :  %u", value.bits[3], value.bits[2], value.bits[1],
         value.bits[0]);
  // dec_to_string(&value, str2);
  // if (strcmp(str, str2) == 0) {
  //   printf("Sucsess\n");
  // } else {
  //   printf("Fail\n");
  // }
  return 0;
}

void binary_conversion(char *str, s21_decimal *value) {
  short len = 0;      // Длина str
  u_int32_t tmp = 0;  // Хранит двоичные цифры
  short val = 0;   // Цифра которую будут делить на 2
  short cnt1 = 0;  // Считает кол-во двоичных цифр
  short cnt2 = 0;  // Счетчик кол-ва int
  char *str1_ptr = str;   // Указатель частное
  char *str2_ptr = NULL;  // Указатель для перемещению по цифрам делимого
  u_int32_t bit = 0;      // Хранит один int

  while (cnt2 < 3) {
    len = strlen(str1_ptr) - 1;
    if (len == -1) {
      value->bits[cnt2] = bit;
      break;
    }
    str2_ptr = str1_ptr + len;
    if ((((int)str1_ptr[len]) % 2) == 0) {
      tmp = 0;
    } else {
      tmp = 1;
      str1_ptr[len] = ((str1_ptr[len] - '0') - 1 + '0');
    }

    while (str1_ptr - 1 != str2_ptr) {
      val = *str2_ptr - '0';
      if (str1_ptr != str2_ptr) {
        if ((*(str2_ptr - 1) - '0') % 2 == 1) {
          *(str2_ptr - 1) = (*(str2_ptr - 1) - '0') - 1 + '0';
          val += 10;
        }
      }
      *str2_ptr = val / 2 + '0';
      if (str1_ptr == str2_ptr) {
        if (*str1_ptr - '0' == 0) {
          str1_ptr++;
        }
        break;
      }
      str2_ptr--;
    }

    tmp = tmp << cnt1;
    bit = bit | tmp;
    cnt1++;
    if (cnt1 == 32) {
      cnt1 = 0;
      value->bits[cnt2] = bit;
      cnt2++;
      bit = 0;
    }
  }
}