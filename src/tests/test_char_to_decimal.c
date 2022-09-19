#include "../header.h"

START_TEST(char_to_decimal_1) {
  char str[] = "1925571";
  s21_decimal value = {0};
  value = char_to_decimal(str);
  printf("value: %u  :   %u  :  %u  :  %u\n", value.bits[3], value.bits[2],
         value.bits[1], value.bits[0]);
  char str2[16] = {'\0'};
  dec_to_string(&value, str2);
  printf("str2: %s\n", str2);
  ck_assert_int_eq(strcmp(str, str2), 0);
}
END_TEST

Suite *sprintf_test(void) {
  Suite *s;
  TCase *tc_is_char_to_decimal;

  s = suite_create("char_to_decimal");

  tc_is_char_to_decimal = tcase_create("char_to_decimal");
  tcase_add_test(tc_is_char_to_decimal, char_to_decimal_1);
  suite_add_tcase(s, tc_is_char_to_decimal);

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
