#include "../header.h"

START_TEST(float_to_decimal_1) {
    char s21_result[BUF];
    memset(s21_result, '\0', BUF);
    float a = FLT_MAX; 
    s21_decimal number = {0};
    s21_from_float_to_decimal(a, &number);
    ck_assert_int_eq(s21_from_float_to_decimal(a, &number), 1);
}
END_TEST

START_TEST(float_to_decimal_2) {
    char s21_result[BUF];
    memset(s21_result, '\0', BUF);
    float a = FLT_MIN; 
    s21_decimal number = {0};
    s21_from_float_to_decimal(a, &number);
    ck_assert_int_eq(s21_from_float_to_decimal(a, &number), 1);
}
END_TEST

START_TEST(float_to_decimal_3) {
    char s21_result[BUF];
    memset(s21_result, '\0', BUF);
    float a = 1516256164.4214;
    char result[] = "1516256000";
    s21_decimal number = {0};
    s21_from_float_to_decimal(a, &number);
    dec_to_string(&number, s21_result);
    ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(float_to_decimal_4) {
    char s21_result[BUF];
    memset(s21_result, '\0', BUF);
    float a = -1516256164.4214;
    char result[] = "-1516256000";
    s21_decimal number = {0};
    s21_from_float_to_decimal(a, &number);
    dec_to_string(&number, s21_result);
    ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(float_to_decimal_5) {
    char s21_result[BUF];
    memset(s21_result, '\0', BUF);
    float a = 1516256564.4214;
    char result[] = "1516257000";
    s21_decimal number = {0};
    s21_from_float_to_decimal(a, &number);
    dec_to_string(&number, s21_result);
    ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(float_to_decimal_6) {
    char s21_result[BUF];
    memset(s21_result, '\0', BUF);
    float a = -1516256564.4214;
    char result[] = "-1516257000";
    s21_decimal number = {0};
    s21_from_float_to_decimal(a, &number);
    dec_to_string(&number, s21_result);
    ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(float_to_decimal_7) {
    char s21_result[BUF];
    memset(s21_result, '\0', BUF);
    float a = 15162561644214;
    char result[] = "15162560000000";
    s21_decimal number = {0};
    s21_from_float_to_decimal(a, &number);
    dec_to_string(&number, s21_result);
    ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(float_to_decimal_8) {
    char s21_result[BUF];
    memset(s21_result, '\0', BUF);
    float a = -15162561644214;
    char result[] = "-15162560000000";
    s21_decimal number = {0};
    s21_from_float_to_decimal(a, &number);
    dec_to_string(&number, s21_result);
    ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(float_to_decimal_9) {
    char s21_result[BUF];
    memset(s21_result, '\0', BUF);
    float a = 15162565644214;
    char result[] = "15162570000000";
    s21_decimal number = {0};
    s21_from_float_to_decimal(a, &number);
    dec_to_string(&number, s21_result);
    ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(float_to_decimal_10) {
    char s21_result[BUF];
    memset(s21_result, '\0', BUF);
    float a = -15162565644214;
    char result[] = "-15162570000000";
    s21_decimal number = {0};
    s21_from_float_to_decimal(a, &number);
    dec_to_string(&number, s21_result);
    ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(float_to_decimal_11) {
    char s21_result[BUF];
    memset(s21_result, '\0', BUF);
    float a = 151.62561644214;
    char result[] = "151.6256";
    s21_decimal number = {0};
    s21_from_float_to_decimal(a, &number);
    dec_to_string(&number, s21_result);
    ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(float_to_decimal_12) {
    char s21_result[BUF];
    memset(s21_result, '\0', BUF);
    float a = -151.62561644214;
    char result[] = "-151.6256";
    s21_decimal number = {0};
    s21_from_float_to_decimal(a, &number);
    dec_to_string(&number, s21_result);
    ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(float_to_decimal_13) {
    char s21_result[BUF];
    memset(s21_result, '\0', BUF);
    float a = -151.62565644214;
    char result[] = "-151.6257";
    s21_decimal number = {0};
    s21_from_float_to_decimal(a, &number);
    dec_to_string(&number, s21_result);
    ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(float_to_decimal_14) {
    char s21_result[BUF];
    memset(s21_result, '\0', BUF);
    float a = 151.62565644214;
    char result[] = "151.6257";
    s21_decimal number = {0};
    s21_from_float_to_decimal(a, &number);
    dec_to_string(&number, s21_result);
    ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(float_to_decimal_15) {
    char s21_result[BUF];
    memset(s21_result, '\0', BUF);
    float a = -1516;
    char result[] = "-1516.000";
    s21_decimal number = {0};
    s21_from_float_to_decimal(a, &number);
    dec_to_string(&number, s21_result);
    ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(float_to_decimal_16) {
    char s21_result[BUF];
    memset(s21_result, '\0', BUF);
    float a = 1516;
    char result[] = "1516.000";
    s21_decimal number = {0};
    s21_from_float_to_decimal(a, &number);
    dec_to_string(&number, s21_result);
    ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(float_to_decimal_17) {
    char s21_result[BUF];
    memset(s21_result, '\0', BUF);
    float a = -1516256.2;
    char result[] = "-1516256";
    s21_decimal number = {0};
    s21_from_float_to_decimal(a, &number);
    dec_to_string(&number, s21_result);
    ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(float_to_decimal_18) {
    char s21_result[BUF];
    memset(s21_result, '\0', BUF);
    float a = 1516256.2;
    char result[] = "1516256";
    s21_decimal number = {0};
    s21_from_float_to_decimal(a, &number);
    dec_to_string(&number, s21_result);
    ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(float_to_decimal_19) {
    char s21_result[BUF];
    memset(s21_result, '\0', BUF);
    float a = -1516256.7;
    char result[] = "-1516257";
    s21_decimal number = {0};
    s21_from_float_to_decimal(a, &number);
    dec_to_string(&number, s21_result);
    ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(float_to_decimal_20) {
    char s21_result[BUF];
    memset(s21_result, '\0', BUF);
    float a = 1516257;
    char result[] = "1516257";
    s21_decimal number = {0};
    s21_from_float_to_decimal(a, &number);
    dec_to_string(&number, s21_result);
    ck_assert_str_eq(result, s21_result);
}
END_TEST

Suite * sprintf_test(void) {
    Suite *s;
    TCase *tc_float_to_decimal;

    s = suite_create("s21_float_to_decimal");

    tc_float_to_decimal = tcase_create("s21_float_to_decimal");
    tcase_add_test(tc_float_to_decimal, float_to_decimal_1);
    tcase_add_test(tc_float_to_decimal, float_to_decimal_2);
    tcase_add_test(tc_float_to_decimal, float_to_decimal_3);
    tcase_add_test(tc_float_to_decimal, float_to_decimal_4);
    tcase_add_test(tc_float_to_decimal, float_to_decimal_5);
    tcase_add_test(tc_float_to_decimal, float_to_decimal_6);
    tcase_add_test(tc_float_to_decimal, float_to_decimal_7);
    tcase_add_test(tc_float_to_decimal, float_to_decimal_8);
    tcase_add_test(tc_float_to_decimal, float_to_decimal_9);
    tcase_add_test(tc_float_to_decimal, float_to_decimal_10);
    tcase_add_test(tc_float_to_decimal, float_to_decimal_11);
    tcase_add_test(tc_float_to_decimal, float_to_decimal_12);
    tcase_add_test(tc_float_to_decimal, float_to_decimal_13);
    tcase_add_test(tc_float_to_decimal, float_to_decimal_14);
    tcase_add_test(tc_float_to_decimal, float_to_decimal_15);
    tcase_add_test(tc_float_to_decimal, float_to_decimal_16);
    tcase_add_test(tc_float_to_decimal, float_to_decimal_17);
    tcase_add_test(tc_float_to_decimal, float_to_decimal_18);
    tcase_add_test(tc_float_to_decimal, float_to_decimal_19);
    tcase_add_test(tc_float_to_decimal, float_to_decimal_20);
    suite_add_tcase(s, tc_float_to_decimal);

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
