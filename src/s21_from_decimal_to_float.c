#include "s21_decimal.h"

int to_int(char a) { return (a <= '9' && a >= '0') ? a - '0' : 0; }

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  float fisting = 0;
  int flag = 1;
  if (src.bits[3] & SIGN) {
    flag = -1;
    src.bits[3] ^= SIGN;
  }
  char d[1024] = "";
  dec_output(&src, d);
  char blij_step[1024];
  char *ukaz = d;
  size_t i = 0;
  int j = 0;
  while (*ukaz != '\0' && *ukaz != '.') {
    ukaz++;
    i++;
  }
  int k = 95;
  for (; k >= 0; k--) {
    float tmp = pow(2, k);
    sprintf(blij_step, "%.0f", tmp);
    if (i > strlen(blij_step)) {
      j = 1;
      break;
    }
    if (i == strlen(blij_step)) {
      if (strcmp(d, blij_step) >= 0) {
        break;
      }
    }
  }
  char result[1024] = "";
  int res = 0;
  int carry = 0;
  for (int tmp = i - 1; tmp >= j; tmp--) {
    if ((res = to_int(d[tmp]) - to_int(blij_step[tmp - j]) - carry) < 0) {
      carry = 1;
    }
    if (res >= 0) {
      carry = 0;
    }
    result[tmp] = res + carry * 10 + 48;
  }
  char *ukazatel = &d[i];
  while (1) {
    if (*ukazatel == '\0') {
      break;
    }
    result[i] = *ukazatel;
    ukazatel++;
    i++;
  }
  result[i] = '\0';
  float mantissa_tmp = atof(result) / pow(2, k - 23);
  int mantissa_real = (int)mantissa_tmp;
  if (mantissa_tmp - mantissa_real - 0.5 >= 0 && k <= 23) {
    mantissa_real++;
  }
  fisting += pow(2, k);
  fisting += mantissa_real * pow(2, k - 23);
  *dst = fisting * flag;
  return 0;
}
