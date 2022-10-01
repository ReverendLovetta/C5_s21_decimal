#include "./s21_decimal.h"

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

// void slozhenie(s21_decimal *dst, int exponent) {
//   if ((exponent - 127) >= 64) {
//     if ((dst->bits[2] & 1 << (exponent - 127 - 64)) == 0) {
//       dst->bits[2] |= 1 << (exponent - 127 - 64);
//     } else {
//       dst->bits[2] |= 0 << (exponent - 127 - 64);
//       exponent += 1;
//       slozhenie(dst, exponent);
//     }
//   } else if ((exponent - 127) >= 32) {
//     if ((dst->bits[1] & 1 << (exponent - 127 - 32)) == 0) {
//       dst->bits[1] |= 1 << (exponent - 127 - 32);
//     } else {
//       dst->bits[1] |= 0 << (exponent - 127 - 32);
//       exponent += 1;
//       slozhenie(dst, exponent);
//     }
//   } else {
//     dst->bits[0] |= 1 << (exponent - 127);
//     if ((dst->bits[0] & 1 << (exponent - 127)) == 0) {
//       dst->bits[0] |= 1 << (exponent - 127);
//     } else {
//       dst->bits[0] |= 0 << (exponent - 127);
//       exponent += 1;
//       slozhenie(dst, exponent);
//     }
//   }
// }

void perezapis_decimal(s21_decimal *src, s21_decimal *dst, int *exponent) {
  int step_mant = *exponent - 150;
  for (int i = 24; i >= 0; i--) {
    if ((src->bits[0] & 1 << i) != 0) {
      if (i + step_mant >= 64) {
        dst->bits[2] |= 1 << (i + step_mant - 64);
      } else if (i + step_mant >= 32) {
        dst->bits[1] |= 1 << (i + step_mant - 32);
      } else {
        dst->bits[0] |= 1 << (i + step_mant);
      }
    }
  }
  slozhenie(dst, *exponent);
}
