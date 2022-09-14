#include "s21_decimal.h"

int check_sign(u_int32_t *val);
int remove_sign(u_int32_t *val);
int compare_val(s21_decimal *val_1, s21_decimal *val_2);

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int status = 0;
  int sign_1 = 0, sign_2 = 0, sign_0 = 0;
  int cmp = 0;

  sign_1 = check_sign(&value_1.bits[3]);
  sign_2 = check_sign(&value_2.bits[3]);
  remove_sign(&value_1.bits[3]);
  remove_sign(&value_2.bits[3]);
  cmp = compare_val(&value_1, &value_1);
  if (sign_1 != 0) {
    if (sign_2 != 0) {
    }
  }
  if (s21_is_less(value_1, value_2) == 1) {
  } else if (s21_is_greater(value_1, value_2)) {
  } else if (s21_is_equal(value_1, value_2)) {
  }
  return status;
}
