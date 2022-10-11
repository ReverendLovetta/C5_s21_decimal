#include "../header.h"

START_TEST(bit_output_01) {
  char str[] = "1925571";
  s21_decimal value = {0};
  value = char_to_decimal(str);
  int res = bit_output(&value);
  printf("bit3  0000 0000 0000 0000 0000 0000 0000 0000\n");
  printf("bit2  0000 0000 0000 0000 0000 0000 0000 0000\n");
  printf("bit1  0000 0000 0000 0000 0000 0000 0000 0000\n");
  printf("bit0  0000 0000 0001 1101 0110 0001 1100 0011\n");
  ck_assert_int_eq(res, 0);
}
END_TEST

Suite *sprintf_test(void) {
  Suite *s;
  TCase *tc_bit_output;

  s = suite_create("bit_output");

  tc_bit_output = tcase_create("bit_output");
  tcase_add_test(tc_bit_output, bit_output_01);
  suite_add_tcase(s, tc_bit_output);

  return s;
}

int main() {
  int number_failed;
  Suite *s;
  SRunner *sr;
  s = sprintf_test();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
