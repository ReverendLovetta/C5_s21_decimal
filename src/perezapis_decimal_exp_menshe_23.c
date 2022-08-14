#include "./s21_decimal.h"

void perezapis_decimal_exp_menshe_23(float *a, float mantissa, int *exponent,
                                     s21_decimal *dst, int *counter_step) {
  size_t len = sizeof(float) * CHAR_BIT;
  int n = *((int *)a);
  s21_decimal tmp_dec = {0};
  // for (int k = 31; k >= 0; k--) {
  //   if (k < 10)
  //     printf("%-2d ", k);
  //   else
  //     printf("%-3d", k);
  // }
  // printf("\n");
  int nomer_bita = -8;
  int stolbik_32_bit = 0;
  for (size_t i = len; i > 0; i--, nomer_bita++) {
    if (i >= 23 && i <= 30 && checkbit(n, i) == 1) {
      *exponent += pow(2, i - 23);
    }
    if (i <= 24) {
      if (checkbit(n, i - 1) == 1) {
        float tmp = 1;
        if (i <= 23) {
          mantissa += tmp * pow(5, i - 24);
          tmp_dec.bits[stolbik_32_bit] |= 1 << (i - 1);
          if (*counter_step == 0) {
            *counter_step = i;
          }
        }
      }
    }
    // if (checkbit(n, i - 1) == 1)
    //   printf("\x1b[31m%-2d\x1b[0m ", checkbit(n, i - 1));
    // else
    //   printf("%-2d ", checkbit(n, i - 1));
  }
  // printf("\n");
  // bit_output(dst);
  char d1[1024] = "";
  dec_output(dst, d1);
  // printf("stroka=%s\n", d1);
  // printf("exponent=%d\n", *exponent);
  // printf("masntissa=%.28f\n", mantissa);
}

//   int counter_step = 0;
//   float tmp = *a;
//   // printf("tmp=%f\n", *a);
//   // for (int i = 0; i < 6; i++) {
//   //   if (fabs(tmp * pow(10, counter_step)) <= MAX_DECIMAL) {
//   //     counter_step++;
//   //   } else {
//   //     break;
//   //   }
//   // }
//   while (counter_step <= 28 && fabs(tmp * 10) <= MAX_DECIMAL) {
//     tmp *= 10;
//     counter_step++;
//   }
//   for (int j = 2; j >= 0; j--) {
//     for (int i = 31, bit = 95; i >= 0; i--, bit--) {
//       float promej = pow(2, bit) / pow(10, counter_step);
//       if (*a - promej >= 0) {
//         *a -= promej;
//         dst->bits[j] |= 1 << i;
//       }
//     }
//   }
// }