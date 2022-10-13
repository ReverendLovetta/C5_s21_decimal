#include "../header.h"

// MIN_DECIMAL -79228162514264337593543950335

START_TEST(mod_1) {
    char s21_res[BUF] = {'\0'};
    s21_decimal number1 = {{17, 0, 0, 0}};
    s21_decimal number2 = {{15, 0, 0, 0}};
    char *res = "2";
    s21_decimal s21_result = {0};
    int exit_code = 0;
    exit_code = s21_mod(number1, number2, &s21_result);
    dec_to_string(&s21_result, s21_res);
    ck_assert_str_eq(s21_res, res);
    ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(mod_2) {
    char s21_res[BUF] = {'\0'};
    s21_decimal number1 = {{17, 0, 0, 0}};
    s21_decimal number2 = {0};
    s21_from_int_to_decimal(-15, &number2);
    char *res = "2";
    s21_decimal s21_result = {0};
    int exit_code = 0;
    exit_code = s21_mod(number1, number2, &s21_result);
    dec_to_string(&s21_result, s21_res);
    ck_assert_str_eq(s21_res, res);
    ck_assert_int_eq(exit_code, 0);
}
END_TEST

// zero mod and negative decimal
START_TEST(mod_3) {
    char s21_res[BUF] = {'\0'};
    s21_decimal number1 = {{33, 0, 0, 0}};
    s21_decimal number2 = {0};
    s21_from_int_to_decimal(-11, &number2);
    char *res = "0";
    s21_decimal s21_result = {0};
    int exit_code = 0;
    exit_code = s21_mod(number1, number2, &s21_result);
    dec_to_string(&s21_result, s21_res);
    ck_assert_str_eq(s21_res, res);
    ck_assert_int_eq(exit_code, 0);
}
END_TEST

// zero mod and positive decimal
START_TEST(mod_4) {
    char s21_res[BUF] = {'\0'};
    s21_decimal number1 = {{33, 0, 0, 0}};
    s21_decimal number2 = {0};
    s21_from_int_to_decimal(11, &number2);
    char *res = "0";
    s21_decimal s21_result = {0};
    int exit_code = 0;
    exit_code = s21_mod(number1, number2, &s21_result);
    dec_to_string(&s21_result, s21_res);
    ck_assert_str_eq(s21_res, res);
    ck_assert_int_eq(exit_code, 0);
}
END_TEST

// arg2 > arg1
START_TEST(mod_5) {
    char s21_res[BUF] = {'\0'};
    s21_decimal number1 = {{11, 0, 0, 0}};
    s21_decimal number2 = {0};
    s21_from_int_to_decimal(33, &number2);
    char *res = "11";
    s21_decimal s21_result = {0};
    int exit_code = 0;
    exit_code = s21_mod(number1, number2, &s21_result);
    dec_to_string(&s21_result, s21_res);
    ck_assert_str_eq(s21_res, res);
    ck_assert_int_eq(exit_code, 0);
}
END_TEST

// arg2 > arg1
START_TEST(mod_4) {
    char s21_res[BUF] = {'\0'};
    s21_decimal number1 = {{11, 0, 0, 0}};
    s21_decimal number2 = {0};
    s21_from_int_to_decimal(-33, &number2);
    char *res = "11";
    s21_decimal s21_result = {0};
    int exit_code = 0;
    exit_code = s21_mod(number1, number2, &s21_result);
    dec_to_string(&s21_result, s21_res);
    ck_assert_str_eq(s21_res, res);
    ck_assert_int_eq(exit_code, 0);
}
END_TEST

// -11 % 33 = -11
START_TEST(mod_4) {
    char s21_res[BUF] = {'\0'};
    s21_decimal number2 = {{33, 0, 0, 0}};
    s21_decimal number1 = {0};
    s21_from_int_to_decimal(-11, &number1);
    char *res = "-11";
    s21_decimal s21_result = {0};
    int exit_code = 0;
    exit_code = s21_mod(number1, number2, &s21_result);
    dec_to_string(&s21_result, s21_res);
    ck_assert_str_eq(s21_res, res);
    ck_assert_int_eq(exit_code, 0);
}
END_TEST

// float value
START_TEST(mod_5) {
    char *a = "14.5";
    char *b = "2.5";
    char *res = "2";
    char s21_res[BUF] = {'\0'};
    s21_decimal s21_result = {0};
    int exit_code = 0;
    exit_code = s21_mod(a, b, &s21_result);
    dec_to_string(&s21_result, s21_res);
    ck_assert_str_eq(s21_res, res);
    ck_assert_int_eq(exit_code, 0);
}
END_TEST

// 0 % 2.0
START_TEST(mod_6) {
    char *a = "0";
    char *b = "2.0";
    char *res = "0";
    char s21_res[BUF] = {'\0'};
    s21_decimal s21_result = {0};
    int exit_code = 0;
    exit_code = s21_mod(a, b, &s21_result);
    dec_to_string(&s21_result, s21_res);
    ck_assert_str_eq(s21_res, res);
    ck_assert_int_eq(exit_code, 0);
}
END_TEST

// -0 % 2.0
START_TEST(mod_7) {
    char *a = "-0";
    char *b = "2.0";
    char *res = "-0";
    char s21_res[BUF] = {'\0'};
    s21_decimal s21_result = {0};
    int exit_code = 0;
    exit_code = s21_mod(a, b, &s21_result);
    dec_to_string(&s21_result, s21_res);
    ck_assert_str_eq(s21_res, res);
    ck_assert_int_eq(exit_code, 0);
}
END_TEST

// 10 % 0.0
START_TEST(mod_8) {
    char *a = "10";
    char *b = "0.0";
    char s21_res[BUF] = {'\0'};
    s21_decimal s21_result = {0};
    int exit_code = 0;
    exit_code = s21_mod(a, b, &s21_result);
    ck_assert_int_eq(exit_code, 3);
}
END_TEST

// 10 % -0.0
START_TEST(mod_9) {
    char *a = "10";
    char *b = "-0.0";
    char s21_res[BUF] = {'\0'};
    s21_decimal s21_result = {0};
    int exit_code = 0;
    exit_code = s21_mod(a, b, &s21_result);
    ck_assert_int_eq(exit_code, 3);
}
END_TEST

// 10 % 0
START_TEST(mod_10) {
    char *a = "10";
    char *b = "0";
    char s21_res[BUF] = {'\0'};
    s21_decimal s21_result = {0};
    int exit_code = 0;
    exit_code = s21_mod(a, b, &s21_result);
    ck_assert_int_eq(exit_code, 3);
}
END_TEST

// 10 % -0
START_TEST(mod_11) {
    char *a = "10";
    char *b = "-0";
    char s21_res[BUF] = {'\0'};
    s21_decimal s21_result = {0};
    int exit_code = 0;
    exit_code = s21_mod(a, b, &s21_result);
    ck_assert_int_eq(exit_code, 3);
}
END_TEST

// float value
START_TEST(mod_12) {
    char *a = "-14.5";
    char *b = "-2.5";
    char *res = "-2";
    char s21_res[BUF] = {'\0'};
    s21_decimal s21_result = {0};
    int exit_code = 0;
    exit_code = s21_mod(a, b, &s21_result);
    dec_to_string(&s21_result, s21_res);
    ck_assert_str_eq(s21_res, res);
    ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(mod_13) {
    char *a = "79228162514264337593543950335";
    char *b = "1";
    char *res = "0";
    char s21_res[BUF] = {'\0'};
    s21_decimal s21_result = {0};
    int exit_code = 0;
    exit_code = s21_mod(a, b, &s21_result);
    dec_to_string(&s21_result, s21_res);
    ck_assert_str_eq(s21_res, res);
    ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(mod_14) {
    char *a = "79228162514264337593543950335";
    char *b = "-1";
    char *res = "0";
    char s21_res[BUF] = {'\0'};
    s21_decimal s21_result = {0};
    int exit_code = 0;
    exit_code = s21_mod(a, b, &s21_result);
    dec_to_string(&s21_result, s21_res);
    ck_assert_str_eq(s21_res, res);
    ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(mod_15) {
    char *a = "-79228162514264337593543950335";
    char *b = "1";
    char *res = "-0";
    char s21_res[BUF] = {'\0'};
    s21_decimal s21_result = {0};
    int exit_code = 0;
    exit_code = s21_mod(a, b, &s21_result);
    dec_to_string(&s21_result, s21_res);
    ck_assert_str_eq(s21_res, res);
    ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(mod_13) {
    char *a = "-79228162514264337593543950335";
    char *b = "-1";
    char *res = "-0";
    char s21_res[BUF] = {'\0'};
    s21_decimal s21_result = {0};
    int exit_code = 0;
    exit_code = s21_mod(a, b, &s21_result);
    dec_to_string(&s21_result, s21_res);
    ck_assert_str_eq(s21_res, res);
    ck_assert_int_eq(exit_code, 0);
}
END_TEST

// переполнение в положительной/отрицательной части
START_TEST(mod_14) {
    char *a = "-79228162514264337593543950335";
    char *b = "0.01";
    char *res = "-0.00";
    char s21_res[BUF] = {'\0'};
    s21_decimal s21_result = {0};
    int exit_code = 0;
    exit_code = s21_mod(a, b, &s21_result);
    dec_to_string(&s21_result, s21_res);
    ck_assert_str_eq(s21_res, res);
    ck_assert_int_eq(exit_code, 0);
}
END_TEST

// переполнение в положительной/отрицательной части
START_TEST(mod_15) {
    char *a = "79228162514264337593543950335";
    char *b = "0.01";
    char *res = "0.00";
    char s21_res[BUF] = {'\0'};
    s21_decimal s21_result = {0};
    int exit_code = 0;
    exit_code = s21_mod(a, b, &s21_result);
    dec_to_string(&s21_result, s21_res);
    ck_assert_str_eq(s21_res, res);
    ck_assert_int_eq(exit_code, 0);
}
END_TEST

// переполнение в положительной/отрицательной части
START_TEST(mod_16) {
    char *a = "79228162514264337593543950335";
    char *b = "0.02";
    char *res = "0.00";
    char s21_res[BUF] = {'\0'};
    s21_decimal s21_result = {0};
    int exit_code = 0;
    exit_code = s21_mod(a, b, &s21_result);
    dec_to_string(&s21_result, s21_res);
    ck_assert_str_eq(s21_res, res);
    ck_assert_int_eq(exit_code, 0);
}
END_TEST


// START_TEST(mod_1) {
//     char *a = "-0.22222222222222222222222222223";
//     char *b = "2";
//     char *result = "-0.11111111111111111111111111112";
//     s21_decimal number1 = {0};
//     s21_decimal number2 = {0};
//     s21_decimal right_result = {0};
//     number1 = char_to_decimal(a);
//     number2 = char_to_decimal(b);
//     right_result = char_to_decimal(result);
//     s21_decimal s21_result = {0};
//     int exit_code = 0;
//     exit_code = s21_mod(number1, number2, &s21_result);
//     ck_assert_int_eq(s21_is_equal(s21result, right_result), 1);
//     ck_assert_int_eq(exit_code, 0);
// }
// END_TEST


Suite *decimal_test(void) {
  Suite *s;
  TCase *tc_mod;

  s = suite_create("s21_mod");
  tc_mod = tcase_create("s21_mod");
  tcase_add_test(tc_mod, mod_1);
  tcase_add_test(tc_mod, mod_2);
  tcase_add_test(tc_mod, mod_3);
  tcase_add_test(tc_mod, mod_4);
  tcase_add_test(tc_mod, mod_5);
  tcase_add_test(tc_mod, mod_6);
  tcase_add_test(tc_mod, mod_7);
  tcase_add_test(tc_mod, mod_8);
  tcase_add_test(tc_mod, mod_9);
  tcase_add_test(tc_mod, mod_10);
  tcase_add_test(tc_mod, mod_11);
  tcase_add_test(tc_mod, mod_12);
  tcase_add_test(tc_mod, mod_13);
  tcase_add_test(tc_mod, mod_14);
  tcase_add_test(tc_mod, mod_15);
  tcase_add_test(tc_mod, mod_16);

  suite_add_tcase(s, tc_mod);

  return s;
}

int main() {
  int number_failed = 0;
  Suite *s;
  SRunner *sr;
  s = decimal_test();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}