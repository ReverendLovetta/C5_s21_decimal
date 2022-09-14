#include "s21_decimal.h"

int check_sign(u_int32_t *val);
int remove_sign(u_int32_t *val);
int compare_val(s21_decimal *val_1, s21_decimal *val_2);
void sub_val(s21_decimal *val_1, s21_decimal *val_2, s21_decimal *res);

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int status = 0;
  unsigned int sign_1 = 0, sign_2 = 0, sign_0 = 0;
  unsigned int cmp = 0,
               check = 0;  // cmp = 0: |val_1| > |val_2|, cmp = 1: |val_1| <
                           // |val_2|, cmp = 2: |val_1| = |val_2|

  sign_1 = check_sign(&value_1.bits[3]);
  sign_2 = check_sign(&value_2.bits[3]);
  remove_sign(&value_1.bits[3]);
  remove_sign(&value_2.bits[3]);
  cmp = compare_val(&value_1, &value_2);
  // cmp ^= 1;
  check = sign_1 | sign_2 << 1 | cmp << 2;
  switch (check) { case 0b00000000: }

  if (sign_1 != 0) {
    if (sign_2 != 0) {
      sub_val(&value_2, &value_1, result);
      sign_0 ^= cmp;
    } else {
      s21_add(value_1, value_2, result);
      sign_0 = 1;
    }
  } else {
    if (sign_2 != 0) {
      s21_add(value_1, value_2, result);
    } else {
      sub_val(&value_1, &value_2, result);
      sign_0 ^= cmp;
    }
  }

  return status;
}
