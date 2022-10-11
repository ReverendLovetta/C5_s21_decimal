// #include "s21_decimal.h"

// int find_sign(s21_decimal *val1, s21_decimal *val2);
// int find_firstbit(s21_decimal *val);
// int find_range(s21_decimal *val1, s21_decimal *val2);

// int div(s21_decimal val1, s21_decimal val2) {
//   char *str1[BUF] = {0}, str2[BUF] = {0}, res[BUF] = {0};
//   int sign_r = 0;
//   int range_r = 0;
//   int result = 0;
//   s21_decimal buf1 = {0}, buf2 = {0};

//   sign_r = find_sign(&val1, &val2);

//   remove_sign_sub(&val1);
//   remove_sign_sub(&val2);
//   dec_to_string(&val1, str1);
//   dec_to_string(&val2, str2);

//   while (s21_is_greater(val1, val2)) {
//     range_r = find_range(&val1, &val2);
//     if (range_r != 0) {
//       buf2 = s21_mul()
//     }
//   }
//   return result;
// }

// int find_sign(s21_decimal *val1, s21_decimal *val2) {
//   unsigned int sign1 = 0, sign2 = 0, sign = 0;

//   sign1 = checkbit(val1->bits[3], 31);
//   sign2 = checkbit(val2->bits[3], 31);

//   sign = sign1 ^ sign2;
//   return (int)sign;
// }

// int find_firstbit(s21_decimal *val) {
//   int count = 95, check = 0;
//   for (int i = 2; i >= 0; i--) {
//     for (int j = 31; j >= 0; j--) {
//       check = checkbit(val->bits[i], j);
//       if (check == 1) {
//         count = (i + 1) * (j + 1);
//         break;
//       }
//     }
//     if (check == 1) {
//       break;
//     }
//   }
//   return count;
// }

// int find_range(s21_decimal *val1, s21_decimal *val2) {
//   int range1 = 0, range2 = 0;
//   unsigned int exp1 = 0, exp2 = 0;

//   for (unsigned int i = 16; i < 21; i++) {
//     exp1 |= ((unsigned int)checkbit(val1->bits[3], i) << (i - 16));
//     exp2 |= ((unsigned int)checkbit(val2->bits[3], i) << (i - 16));
//   }

//   range1 = find_firstbit(&val1) - exp1;
//   range2 = find_firstbit(&val2) - exp2;
//   return range1 - range2;
// }
