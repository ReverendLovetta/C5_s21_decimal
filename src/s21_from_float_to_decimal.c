#include "./s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int status = 0;
  int counter_step = 0;
  float tmp = src;
  // printf("tmp=%f\n", src);
  // for (int i = 0; i < 6; i++) {
  //   if (fabs(tmp * pow(10, counter_step)) <= MAX_DECIMAL) {
  //     counter_step++;
  //   } else {
  //     break;
  //   }
  // }
  while (counter_step <= 28 && fabs(tmp * 10) <= MAX_DECIMAL) {
    tmp *= 10;
    counter_step++;
  }
  float_bit_output(&src);
  if (src < 0) {
    dst->bits[3] |= SIGN;
  }
  src = fabs(src);
  printf("src=%.28f\n", src);
  if (fabs(src) >= 1e-28 && src != INFINITY && fabs(src) <= MAX_DECIMAL) {
    for (int j = 2; j >= 0; j--) {
      for (int i = 31, bit = 95; i >= 0; i--, bit--) {
        float promej = pow(2, bit) / pow(10, counter_step);
        if (src - promej >= 0) {
          src -= promej;
          dst->bits[j] |= 1 << i;
        }
      }
    }
    zapis_stepeni_v_decimal(counter_step, dst);
    char d[1024] = "";
    // bit_output(dst);
    dec_output(dst, d);
    printf("stroka=%s\n", d);
  } else {
    status = 1;
  }
  return status;
}

int main() {
  s21_decimal d = {0};
  d.bits[0] = 0;
  d.bits[1] = 0;
  d.bits[2] = 0;
  d.bits[3] = 0;
  float b = 3.14;
  s21_from_float_to_decimal(b, &d);
  printf("nast=%.28f=float\n", b);
  return 0;
}

// int sravnenie_strok(char *buffer_tmp, char *buffer_step) {
//   int result = 0;
//   if (stlen(buffer_tmp) > strlen(buffer_step)) {
//     result = 1;
//   } else if (stlen(buffer_tmp) == strlen(buffer_step)) {
//     char *tmp_tmp = buffer_tmp;
//     char *tmp_step = buffer_step;
//     while (*tmp_tmp != '\0') {
//       if (*tmp_tmp > *tmp_step) {
//         result = 1;
//         break;
//       }
//       if (*tmp_tmp < *tmp_step) {
//         result = 0;
//         break;
//       }
//       tmp_tmp++;
//       tmp_step++;
//     }
//   }
//   return result;
// }
