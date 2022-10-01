#include "../header.h"

START_TEST(less_1) {
  s21_decimal d = {0};
  s21_decimal d1 = {0};
  d.bits[0] = 2048;
  d.bits[1] = 2048;
  d.bits[2] = 2045;
  d.bits[3] |= SIGN;
  zapis_stepeni_v_decimal(0, &d);
  d1.bits[0] = 2048;
  d1.bits[1] = 2048;
  d1.bits[2] = 2046;
  d1.bits[3] |= SIGN;
  zapis_stepeni_v_decimal(0, &d1);
  ck_assert_int_eq(s21_is_less(d, d1), 0);
}
END_TEST

START_TEST(less_2) {
  s21_decimal d = {0};
  s21_decimal d1 = {0};
  d.bits[0] = 2048;
  d.bits[1] = 2048;
  d.bits[2] = 2046;
  zapis_stepeni_v_decimal(12, &d);
  d1.bits[0] = 2047;
  d1.bits[1] = 2048;
  d1.bits[2] = 2046;
  zapis_stepeni_v_decimal(0, &d1);
  ck_assert_int_eq(s21_is_less(d, d1), 1);
}
END_TEST

START_TEST(less_3) {
  s21_decimal d = {0};
  s21_decimal d1 = {0};
  d.bits[0] = 0;
  d.bits[1] = 0;
  d.bits[2] = 0;
  zapis_stepeni_v_decimal(0, &d);
  d1.bits[0] = 0;
  d1.bits[1] = 0;
  d1.bits[2] = 0;
  d1.bits[3] |= SIGN;
  zapis_stepeni_v_decimal(0, &d1);
  ck_assert_int_eq(s21_is_less(d, d1), 0);
}
END_TEST

START_TEST(less_4) {
  s21_decimal d = {0};
  s21_decimal d1 = {0};
  d.bits[0] = 2346;
  d.bits[1] = 1242;
  d.bits[2] = 124;
  zapis_stepeni_v_decimal(0, &d);
  d1.bits[0] = 3782;
  d1.bits[1] = 1512;
  d1.bits[2] = 123;
  zapis_stepeni_v_decimal(0, &d1);
  ck_assert_int_eq(s21_is_less(d, d1), 0);
}
END_TEST

START_TEST(less_5) {
  s21_decimal d = {0};
  s21_decimal d1 = {0};
  d.bits[0] = 2346;
  d.bits[1] = 1242;
  d.bits[2] = 124;
  d.bits[3] |= SIGN;
  zapis_stepeni_v_decimal(0, &d);
  d1.bits[0] = 3782;
  d1.bits[1] = 1512;
  d1.bits[2] = 123;
  d1.bits[3] |= SIGN;
  zapis_stepeni_v_decimal(0, &d1);
  ck_assert_int_eq(s21_is_less(d, d1), 1);
}
END_TEST

START_TEST(less_6) {
  s21_decimal d = {0};
  s21_decimal d1 = {0};
  d.bits[0] = 2346;
  d.bits[1] = 1242;
  d.bits[2] = 124;
  zapis_stepeni_v_decimal(10, &d);
  d1.bits[0] = 3782;
  d1.bits[1] = 1512;
  d1.bits[2] = 123;
  zapis_stepeni_v_decimal(12, &d1);
  ck_assert_int_eq(s21_is_less(d, d1), 0);
}
END_TEST

START_TEST(less_7) {
  s21_decimal d = {0};
  s21_decimal d1 = {0};
  d.bits[0] = 2346;
  d.bits[1] = 1242;
  d.bits[2] = 124;
  d.bits[3] |= SIGN;
  zapis_stepeni_v_decimal(10, &d);
  d1.bits[0] = 3782;
  d1.bits[1] = 1512;
  d1.bits[2] = 123;
  d1.bits[3] |= SIGN;
  zapis_stepeni_v_decimal(12, &d1);
  ck_assert_int_eq(s21_is_less(d, d1), 0);
}
END_TEST

START_TEST(less_8) {
  s21_decimal d = {0};
  s21_decimal d1 = {0};
  d.bits[0] = 2346;
  d.bits[1] = 1242;
  d.bits[2] = 124;
  zapis_stepeni_v_decimal(12, &d);
  d1.bits[0] = 3782;
  d1.bits[1] = 1512;
  d1.bits[2] = 123;
  zapis_stepeni_v_decimal(10, &d1);
  ck_assert_int_eq(s21_is_less(d, d1), 1);
}
END_TEST

START_TEST(less_9) {
  s21_decimal d = {0};
  s21_decimal d1 = {0};
  d.bits[0] = 3782;
  d.bits[1] = 1512;
  d.bits[2] = 123;
  zapis_stepeni_v_decimal(12, &d);
  d1.bits[0] = 3782;
  d1.bits[1] = 1512;
  d1.bits[2] = 123;
  zapis_stepeni_v_decimal(10, &d1);
  ck_assert_int_eq(s21_is_less(d, d1), 1);
}
END_TEST

START_TEST(less_10) {
  s21_decimal d = {0};
  s21_decimal d1 = {0};
  d.bits[0] = 3782;
  d.bits[1] = 1512;
  d.bits[2] = 123;
  zapis_stepeni_v_decimal(12, &d);
  d1.bits[0] = 3782;
  d1.bits[1] = 1512;
  d1.bits[2] = 123;
  zapis_stepeni_v_decimal(12, &d1);
  ck_assert_int_eq(s21_is_less(d, d1), 0);
}
END_TEST

START_TEST(less_11) {
  s21_decimal d = {0};
  s21_decimal d1 = {0};
  d.bits[0] = 3782;
  d.bits[1] = 1512;
  d.bits[2] = 123;
  d.bits[3] |= SIGN;
  zapis_stepeni_v_decimal(12, &d);
  d1.bits[0] = 3782;
  d1.bits[1] = 1512;
  d1.bits[2] = 123;
  d1.bits[3] |= SIGN;
  zapis_stepeni_v_decimal(12, &d1);
  ck_assert_int_eq(s21_is_less(d, d1), 0);
}
END_TEST

START_TEST(less_12) {
  s21_decimal d = {0};
  s21_decimal d1 = {0};
  d.bits[0] = 0;
  d.bits[1] = 0;
  d.bits[2] = 0;
  zapis_stepeni_v_decimal(0, &d);
  d1.bits[0] = 0;
  d1.bits[1] = 0;
  d1.bits[2] = 0;
  zapis_stepeni_v_decimal(0, &d1);
  ck_assert_int_eq(s21_is_less(d, d1), 0);
}
END_TEST

START_TEST(less_13) {
  s21_decimal d = {0};
  s21_decimal d1 = {0};
  d.bits[0] = 2000;
  d.bits[1] = 0;
  d.bits[2] = 0;
  zapis_stepeni_v_decimal(2, &d);
  d1.bits[0] = 20;
  d1.bits[1] = 0;
  d1.bits[2] = 0;
  zapis_stepeni_v_decimal(0, &d1);
  ck_assert_int_eq(s21_is_less(d, d1), 0);
}
END_TEST

START_TEST(less_14) {
  s21_decimal d = {0};
  s21_decimal d1 = {0};
  d.bits[0] = 20;
  d.bits[1] = 0;
  d.bits[2] = 0;
  zapis_stepeni_v_decimal(0, &d);
  d1.bits[0] = 2001;
  d1.bits[1] = 0;
  d1.bits[2] = 0;
  zapis_stepeni_v_decimal(2, &d1);
  ck_assert_int_eq(s21_is_less(d, d1), 1);
}
END_TEST

START_TEST(less_15) {
  s21_decimal d = {0};
  s21_decimal d1 = {0};
  d.bits[0] = 20;
  d.bits[1] = 0;
  d.bits[2] = 0;
  d.bits[3] |= SIGN;
  zapis_stepeni_v_decimal(0, &d);
  d1.bits[0] = 2001;
  d1.bits[1] = 0;
  d1.bits[2] = 0;
  d1.bits[3] |= SIGN;
  zapis_stepeni_v_decimal(2, &d1);
  ck_assert_int_eq(s21_is_less(d, d1), 0);
}
END_TEST

Suite *sprintf_test(void) {
  Suite *s;
  TCase *tc_is_less;

  s = suite_create("s21_is_less");

  tc_is_less = tcase_create("s21_is_less");
  tcase_add_test(tc_is_less, less_1);
  tcase_add_test(tc_is_less, less_2);
  tcase_add_test(tc_is_less, less_3);
  tcase_add_test(tc_is_less, less_4);
  tcase_add_test(tc_is_less, less_5);
  tcase_add_test(tc_is_less, less_6);
  tcase_add_test(tc_is_less, less_7);
  tcase_add_test(tc_is_less, less_8);
  tcase_add_test(tc_is_less, less_9);
  tcase_add_test(tc_is_less, less_10);
  tcase_add_test(tc_is_less, less_11);
  tcase_add_test(tc_is_less, less_12);
  tcase_add_test(tc_is_less, less_13);
  tcase_add_test(tc_is_less, less_14);
  tcase_add_test(tc_is_less, less_15);
  suite_add_tcase(s, tc_is_less);

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
