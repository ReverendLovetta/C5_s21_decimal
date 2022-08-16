#include "./s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int status = 0;
  if (fabs(src) >= 1e-28 && src != INFINITY && fabs(src) <= MAX_DECIMAL) {
    int counter_step = 0;
    int exponent = 0;
    float mantissa = 1.0;
    if (src < 0) {
      dst->bits[3] |= SIGN;
      src = fabs(src);
    }
    mantissa = float_bit_output(&src, mantissa, &exponent, dst, &counter_step);
  } else {
    status = 1;
  }
  return status;
}

// int main() {
//   s21_decimal d = {0};
//   float b = -3129375678932561782378.14;
//   s21_from_float_to_decimal(b, &d);
//   printf("nast=%7f=float\n", b);
//   return 0;
// }