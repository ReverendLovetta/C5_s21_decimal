#include "../header.h"

START_TEST(float_chislo) {
  char s21_result[BUF];
  memset(s21_result, '\0', BUF);
  s21_decimal d = {0};
  d.bits[0] = 2048;
  d.bits[1] = 2048;
  d.bits[2] = 2046;
  d.bits[3] |= SIGN;
  zapis_stepeni_v_decimal(12, &d);
  dec_output(&d, s21_result);
  char result[] = "-37742038383.605835630592";
  ck_assert_str_eq(result, s21_result);
}
END_TEST

Suite *sprintf_test(void) {
  Suite *s;
  TCase *tc_float_chislo;

  s = suite_create("float_chislo");

  tc_float_chislo = tcase_create("float_chislo");
  tcase_add_test(tc_float_chislo, float_chislo);
  suite_add_tcase(s, tc_float_chislo);

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
