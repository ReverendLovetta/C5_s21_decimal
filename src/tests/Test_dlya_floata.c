#include "../header.h"

START_TEST(float_chislo_0) {
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

START_TEST(float_chislo_1) {
  char s21_result[BUF];
  memset(s21_result, '\0', BUF);
  s21_decimal d = {0};
  d.bits[0] = 2048;
  d.bits[1] = 0;
  d.bits[2] = 0;
  d.bits[3] |= SIGN;
  zapis_stepeni_v_decimal(5, &d);
  dec_output(&d, s21_result);
  char result[] = "-0.02048";
  ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(float_chislo_2) {
  char s21_result[BUF];
  memset(s21_result, '\0', BUF);
  s21_decimal d = {0};
  d.bits[0] = 0;
  d.bits[1] = 0;
  d.bits[2] = 1073741824;
  d.bits[3] |= SIGN;
  zapis_stepeni_v_decimal(27, &d);
  dec_output(&d, s21_result);
  char result[] = "-19.807040628566084398385987584";
  ck_assert_str_eq(result, s21_result);
}
END_TEST

Suite *sprintf_test(void) {
  Suite *s;
  TCase *tc_float_chislo;

  s = suite_create("float_chislo");

  tc_float_chislo = tcase_create("float_chislo");
  tcase_add_test(tc_float_chislo, float_chislo_0);
  tcase_add_test(tc_float_chislo, float_chislo_1);
  tcase_add_test(tc_float_chislo, float_chislo_2);
  suite_add_tcase(s, tc_float_chislo);

  return s;
}

int main() {
  int d_failed;
  Suite *s;
  SRunner *sr;
  s = sprintf_test();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  d_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (d_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
