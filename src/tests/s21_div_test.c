#include "../header.h"

// MIN_DECIMAL -79228162514264337593543950335

START_TEST(div_01) {
    char s21_result[BUF] = {'\0'};
    char *a = "-79228162514264337593543950334";
    char *b = "1";
    char *result = "-79228162514264337593543950335";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    s21_decimal dec_result = {0};
    int exit_code = 0;
    exit_code = s21_div(number1, number2, &dec_result);
    dec_to_string(&dec_result, s21_result);
    ck_assert_str_eq(result, s21_result);
    ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(div_1) {
    char s21_result[BUF] = {'\0'};
    char *a = "79228162514264337593543950335";
    char *b = "1";
    char *result = "79228162514264337593543950335";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    s21_decimal dec_result = {0};
    int exit_code = 0;
    exit_code = s21_div(number1, number2, &dec_result);
    dec_to_string(&dec_result, s21_result);
    ck_assert_str_eq(result, s21_result);
    ck_assert_int_eq(exit_code, 0);
}
END_TEST

// деление на 0 отрицательного числа
START_TEST(div_2) {
    char *a = "-79228162514264337593543950334";
    char *b = "0";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    s21_decimal dec_result = {0};
    int exit_code = 0;
    exit_code = s21_div(number1, number2, &dec_result);
    ck_assert_int_eq(exit_code, 3);
}
END_TEST

// переполнение в отрицательной части
START_TEST(div_3) {
    char s21_result[BUF] = {'\0'};
    char *a = "-79228162514264337593543950334";
    char *b = "0.2";
    char *result = "-79228162514264337593543950335";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    s21_decimal dec_result = {0};
    int exit_code = 0;
    exit_code = s21_div(number1, number2, &dec_result);
    dec_to_string(&dec_result, s21_result);
    ck_assert_str_eq(result, s21_result);
    ck_assert_int_eq(exit_code, 2);
}
END_TEST

// переполнение в положителной части
START_TEST(div_4) {
    char s21_result[BUF] = {'\0'};
    char *a = "79228162514264337593543950334";
    char *b = "0.2";
    char *result = "-79228162514264337593543950335";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    s21_decimal dec_result = {0};
    int exit_code = 0;
    exit_code = s21_div(number1, number2, &dec_result);
    dec_to_string(&dec_result, s21_result);
    ck_assert_str_eq(result, s21_result);
    ck_assert_int_eq(exit_code, 1);
}
END_TEST

// применение банковского округления в положительной части
START_TEST(div_5) {
    char s21_result[BUF] = {'\0'};
    char *a = "2";
    char *b = "3";
    char *result = "0.6666666666666666666666666667";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    s21_decimal dec_result = {0};
    int exit_code = 0;
    exit_code = s21_div(number1, number2, &dec_result);
    dec_to_string(&dec_result, s21_result);
    ck_assert_str_eq(result, s21_result);
    ck_assert_int_eq(exit_code, 0);
}
END_TEST

// применение банковского округления в отрицательной части
START_TEST(div_6) {
    char s21_result[BUF] = {'\0'};
     char *a = "-2";
    char *b = "3";
    char *result = "-0.6666666666666666666666666667";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    s21_decimal dec_result = {0};
    int exit_code = 0;
    exit_code = s21_div(number1, number2, &dec_result);
    dec_to_string(&dec_result, s21_result);
    ck_assert_str_eq(result, s21_result);
    ck_assert_int_eq(exit_code, 0);
}
END_TEST

// деление отрицательного числа на -0
START_TEST(div_7) {
    char *a = "-79228162514264337593543950335";
    char *b = "-0";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    s21_decimal dec_result = {0};
    int exit_code = 0;
    exit_code = s21_div(number1, number2, &dec_result);
    ck_assert_int_eq(exit_code, 3);
}
END_TEST

// деление положительного числа на -0
START_TEST(div_8) {
    char *a = "79228162514264337593543950334";
    char *b = "-0";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    s21_decimal dec_result = {0};
    int exit_code = 0;
    exit_code = s21_div(number1, number2, &dec_result);
    ck_assert_int_eq(exit_code, 3);
}
END_TEST

// положительное число делим на отрицательное
START_TEST(div_9) {
    char s21_result[BUF] = {'\0'};
    char *a = "5";
    char *b = "-2";
    char *result = "-2.5";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    s21_decimal dec_result = {0};
    int exit_code = 0;
    exit_code = s21_div(number1, number2, &dec_result);
    dec_to_string(&dec_result, s21_result);
    ck_assert_str_eq(result, s21_result);
    ck_assert_int_eq(exit_code, 0);
}
END_TEST

// отрицательное число делим на положительное
START_TEST(div_10) {
    char *a = "5";
    char *b = "-2";
    char *result = "-2.5";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    s21_decimal right_result = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    right_result = char_to_decimal(result);
    s21_decimal s21_result = {0};
    int exit_code = 0;
    exit_code = s21_div(number1, number2, &s21_result);
    ck_assert_int_eq(s21_is_equal(s21_result, right_result), 1);
    ck_assert_int_eq(exit_code, 0);
}
END_TEST

// нулевой числитель
START_TEST(div_11) {
    char *a = "0";
    char *b = "79228162514264337593543950335";
    char *result = "0";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    s21_decimal right_result = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    right_result = char_to_decimal(result);
    s21_decimal s21_result = {0};
    int exit_code = 0;
    exit_code = s21_div(number1, number2, &s21_result);
    ck_assert_int_eq(s21_is_equal(s21_result, right_result), 1);
    ck_assert_int_eq(exit_code, 0);
}
END_TEST

// нулевой числитель
START_TEST(div_12) {
    char *a = "-0";
    char *b = "79228162514264337593543950335";
    char *result = "0";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    s21_decimal right_result = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    right_result = char_to_decimal(result);
    s21_decimal dec_result = {0};
    int exit_code = 0;
    exit_code = s21_div(number1, number2, &dec_result);
    ck_assert_int_eq(s21_is_equal(dec_result, right_result), 1);
    ck_assert_int_eq(exit_code, 0);
}
END_TEST

// банковское округление
START_TEST(div_13) {
    char *a = "0.22222222222222222222222222223";
    char *b = "2";
    char *result = "0.11111111111111111111111111112";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    s21_decimal right_result = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    right_result = char_to_decimal(result);
    s21_decimal dec_result = {0};
    int exit_code = 0;
    exit_code = s21_div(number1, number2, &dec_result);
    ck_assert_int_eq(s21_is_equal(dec_result, right_result), 1);
    ck_assert_int_eq(exit_code, 0);
}
END_TEST

// банковское округление
START_TEST(div_14) {
    char *a = "-0.22222222222222222222222222223";
    char *b = "2";
    char *result = "-0.11111111111111111111111111112";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    s21_decimal right_result = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    right_result = char_to_decimal(result);
    s21_decimal dec_result = {0};
    int exit_code = 0;
    exit_code = s21_div(number1, number2, &dec_result);
    ck_assert_int_eq(s21_is_equal(dec_result, right_result), 1);
    ck_assert_int_eq(exit_code, 0);
}
END_TEST

// банковское округление
START_TEST(div_15) {
    char *a = "0.22222222222222222222222222223";
    char *b = "-2";
    char *result = "-0.11111111111111111111111111112";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    s21_decimal right_result = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    right_result = char_to_decimal(result);
    s21_decimal dec_result = {0};
    int exit_code = 0;
    exit_code = s21_div(number1, number2, &dec_result);
    ck_assert_int_eq(s21_is_equal(dec_result, right_result), 1);
    ck_assert_int_eq(exit_code, 0);
}
END_TEST

// банковское округление
START_TEST(div_16) {
    char *a = "1";
    char *b = "3";
    char *result = "0.33333333333333333333333333333";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    s21_decimal right_result = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    right_result = char_to_decimal(result);
    s21_decimal dec_result = {0};
    int exit_code = 0;
    exit_code = s21_div(number1, number2, &dec_result);
    ck_assert_int_eq(s21_is_equal(dec_result, right_result), 1);
    ck_assert_int_eq(exit_code, 0);
}
END_TEST

Suite *decimal_test(void) {
  Suite *s;
  TCase *tc_div;

  s = suite_create("s21_div");
  tc_div = tcase_create("s21_div");
  tcase_add_test(tc_div, div_01);
  tcase_add_test(tc_div, div_1);
  tcase_add_test(tc_div, div_2);
  tcase_add_test(tc_div, div_3);
  tcase_add_test(tc_div, div_4);
  tcase_add_test(tc_div, div_5);
  tcase_add_test(tc_div, div_6);
  tcase_add_test(tc_div, div_7);
  tcase_add_test(tc_div, div_8);
  tcase_add_test(tc_div, div_9);
  tcase_add_test(tc_div, div_10);
  tcase_add_test(tc_div, div_11);
  tcase_add_test(tc_div, div_12);
  tcase_add_test(tc_div, div_13);
  tcase_add_test(tc_div, div_14);
  tcase_add_test(tc_div, div_15);
  tcase_add_test(tc_div, div_16);

  suite_add_tcase(s, tc_div);

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