#include "s21_decimal.h"

int s21_is_not_equal(s21_decimal src, s21_decimal dst) {
  int status = 0;
  char d[1024] = "";
  dec_output(&src, d);
  char d1[1024] = "";
  dec_output(&dst, d1);
  char *ukaz_src = d;
  char *ukaz_dst = d1;
  int chet_do_t_src = 0;
  int chet_do_t_dst = 0;
  if (src.bits[0] == 0 && src.bits[1] == 0 && src.bits[2] == 0 &&
      dst.bits[0] == 0 && dst.bits[1] == 0 && dst.bits[2] == 0) {
  } else if ((src.bits[3] &= SIGN) == 0 && (src.bits[3] &= SIGN) == 1) {
  } else if ((src.bits[3] &= SIGN) == 1 && (src.bits[3] &= SIGN) == 0) {
  } else {
    while (*ukaz_src != '.' && *ukaz_src != '\0') {
      chet_do_t_src++;
      ukaz_src++;
    }
    while (*ukaz_dst != '.' && *ukaz_dst != '\0') {
      chet_do_t_dst++;
      ukaz_dst++;
    }
    if (chet_do_t_src == chet_do_t_dst) {
      if (strcmp(d, d1) != 0) {
        status = 1;
      }
    }
  }
  return status;
}
