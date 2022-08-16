#include "s21_decimal.h"

int s21_is_greater(s21_decimal src, s21_decimal dst) {
  int status = 0;
  int flag = 0;
  //   zapis_stepeni_v_decimal(12, src);
  //   bit_output(src);
  char d[1024] = "";
  dec_output(&src, d);
  char d1[1024] = "";
  dec_output(&dst, d1);
  //   printf("src=%s\n", d);
  //   printf("dst=%s\n", d1);
  char *ukaz_src = d;
  char *ukaz_dst = d1;
  int chet_do_t_src = 0;
  int chet_do_t_dst = 0;
  if (src.bits[0] == 0 && src.bits[1] == 0 && src.bits[2] == 0 &&
      dst.bits[0] == 0 && dst.bits[1] == 0 && dst.bits[2] == 0) {
  } else if ((src.bits[3] &= SIGN) == 0 && (src.bits[3] &= SIGN) == 1) {
    status = 1;
  } else if ((src.bits[3] &= SIGN) == 1 && (src.bits[3] &= SIGN) == 0) {
  } else {
    if (*ukaz_src == '-') {
      flag = 1;
    }
    while (*ukaz_src != '.' && *ukaz_src != '\0') {
      chet_do_t_src++;
      ukaz_src++;
    }
    while (*ukaz_dst != '.' && *ukaz_dst != '\0') {
      chet_do_t_dst++;
      ukaz_dst++;
    }
    if (chet_do_t_src > chet_do_t_dst) {
      if (flag == 1) {
        status = 0;
      } else {
        status = 1;
      }
    } else if (chet_do_t_src == chet_do_t_dst) {
      if (strcmp(d, d1) > 0 && (src.bits[3] &= SIGN) == 0) {
        status = 1;
      }
      if (strcmp(d, d1) < 0 && flag == 1) {
        status = 1;
      }
    }
  }
  //   printf("status=%d\n", status);
  return status;
}

// int main() {
//   s21_decimal d = {0};
//   s21_decimal d1 = {0};
//   d.bits[0] = 2048;
//   d.bits[1] = 2048;
//   d.bits[2] = 2046;
//   d.bits[3] |= SIGN;
//   d1.bits[0] = 2048;
//   d1.bits[1] = 2048;
//   d1.bits[2] = 2047;
//   d1.bits[3] |= SIGN;
//   s21_is_greater(&d, &d1);
//   return 0;
// }