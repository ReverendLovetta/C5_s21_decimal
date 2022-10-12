#include "../header.h"

// MIN_DECIMAL 79228162514264337593543950335

START_TEST(sub_1) {
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
    exit_code = s21_sub(number1, number2, &dec_result);
    dec_to_string(&dec_result, s21_result);
    ck_assert_str_eq(result, s21_result);
    ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(sub_2) {
    char s21_result[BUF] = {'\0'};
    char *a = "-792281625142.64337593543950334";
    char *b = "1444221.30039129847178912395";
    char *result = "-792283069363.9437672339112925";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    s21_decimal dec_result = {0};
    int exit_code = 0;
    exit_code = s21_sub(number1, number2, &dec_result);
    dec_to_string(&dec_result, s21_result);
    ck_assert_str_eq(result, s21_result);
    ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(sub_3) {
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
    exit_code = s21_sub(number1, number2, &dec_result);
    dec_to_string(&dec_result, s21_result);
    ck_assert_str_eq(result, s21_result);
    ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(sub_4) {
    char s21_result[BUF] = {'\0'};
    char *a = "-0";
    char *b = "0";
    char *result = "0";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    s21_decimal dec_result = {0};
    int exit_code = 0;
    exit_code = s21_sub(number1, number2, &dec_result);
    dec_to_string(&dec_result, s21_result);
    ck_assert_str_eq(result, s21_result);
    ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(sub_5) {
    char s21_result[BUF] = {'\0'};
    char *a = "0.00";
    char *b = "0.00";
    char *result = "0";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    s21_decimal dec_result = {0};
    int exit_code = 0;
    exit_code = s21_sub(number1, number2, &dec_result);
    dec_to_string(&dec_result, s21_result);
    ck_assert_str_eq(result, s21_result);
    ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(sub_6) {
    char s21_result[BUF] = {'\0'};
    char *a = "-0.00";
    char *b = "-11.5";
    char *result = "11.50";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    s21_decimal dec_result = {0};
    int exit_code = 0;
    exit_code = s21_sub(number1, number2, &dec_result);
    dec_to_string(&dec_result, s21_result);
    ck_assert_str_eq(result, s21_result);
    ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(sub_7) {
    char s21_result[BUF] = {'\0'};
    char *a = "-0.00";
    char *b = "11.545613";
    char *result = "-11.545613";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    s21_decimal dec_result = {0};
    int exit_code = 0;
    exit_code = s21_sub(number1, number2, &dec_result);
    dec_to_string(&dec_result, s21_result);
    ck_assert_str_eq(result, s21_result);
    ck_assert_int_eq(exit_code, 0);
}
END_TEST

// проверка на переполнение в отрицательной части
START_TEST(sub_8) {
    char s21_result[BUF] = {'\0'};
    char *a = "-79228162514264337593543950335";
    char *b = "1111";
    char *result = "-79228162514264337593543950335";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    s21_decimal dec_result = {0};
    int exit_code = 0;
    exit_code = s21_sub(number1, number2, &dec_result);
    dec_to_string(&dec_result, s21_result);
    ck_assert_str_eq(result, s21_result);
    ck_assert_int_eq(exit_code, 2);
}
END_TEST

// проверка на переполнение в положительной части
START_TEST(sub_9) {
    char s21_result[BUF] = {'\0'};
    char *a = "79228162514264337593543950335";
    char *b = "-11.5";
    char *result = "79228162514264337593543950335";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    s21_decimal dec_result = {0};
    int exit_code = 0;
    exit_code = s21_sub(number1, number2, &dec_result);
    dec_to_string(&dec_result, s21_result);
    ck_assert_str_eq(result, s21_result);
    ck_assert_int_eq(exit_code, 1);
}
END_TEST

// проверка на вычитание с применением банковского округляния
START_TEST(sub_10) {
    char s21_result[BUF] = {'\0'};
    char *a = "79228162514264337593543950335";
    char *b = "0.6666666";
    char *result = "79228162514264337593543950334";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    s21_decimal dec_result = {0};
    int exit_code = 0;
    exit_code = s21_sub(number1, number2, &dec_result);
    dec_to_string(&dec_result, s21_result);
    ck_assert_str_eq(result, s21_result);
    ck_assert_int_eq(exit_code, 0);
}
END_TEST

// проверка на вычитание с применением банковского округляния
START_TEST(sub_11) {
    char s21_result[BUF] = {'\0'};
    char *a = "79228162514264337593543950335";
    char *b = "0.444444444444444444";
    char *result = "79228162514264337593543950334";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    s21_decimal dec_result = {0};
    int exit_code = 0;
    exit_code = s21_sub(number1, number2, &dec_result);
    dec_to_string(&dec_result, s21_result);
    ck_assert_str_eq(result, s21_result);
    ck_assert_int_eq(exit_code, 0);
}
END_TEST

// проверка на вычитание с применением банковского округляния
START_TEST(sub_12) {
    char s21_result[BUF] = {'\0'};
    char *a = "-79228162514264337593543950335";
    char *b = "-0.6666666";
    char *result = "-79228162514264337593543950334";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    s21_decimal dec_result = {0};
    int exit_code = 0;
    exit_code = s21_sub(number1, number2, &dec_result);
    dec_to_string(&dec_result, s21_result);
    ck_assert_str_eq(result, s21_result);
    ck_assert_int_eq(exit_code, 0);
}
END_TEST

// проверка на вычитание с применением банковского округляния
START_TEST(sub_13) {
    char s21_result[BUF] = {'\0'};
    char *a = "-79228162514264337593543950335";
    char *b = "-0.222222222222222222222";
    char *result = "-79228162514264337593543950334";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    s21_decimal dec_result = {0};
    int exit_code = 0;
    exit_code = s21_sub(number1, number2, &dec_result);
    dec_to_string(&dec_result, s21_result);
    ck_assert_str_eq(result, s21_result);
    ck_assert_int_eq(exit_code, 0);
}
END_TEST

Suite *sprintf_test(void) {
  Suite *s;
  TCase *tc_sub;

  s = suite_create("s21_sub");
  tc_sub = tcase_create("s21_sub");
  tcase_add_test(tc_sub, sub_1);
  tcase_add_test(tc_sub, sub_2);
  tcase_add_test(tc_sub, sub_3);
  tcase_add_test(tc_sub, sub_4);
  tcase_add_test(tc_sub, sub_5);
  tcase_add_test(tc_sub, sub_6);
  tcase_add_test(tc_sub, sub_7);
  tcase_add_test(tc_sub, sub_8);
  tcase_add_test(tc_sub, sub_9);
  tcase_add_test(tc_sub, sub_10);
  tcase_add_test(tc_sub, sub_11);
  tcase_add_test(tc_sub, sub_12);
  tcase_add_test(tc_sub, sub_13);

  suite_add_tcase(s, tc_sub);

  return s;
}

int main() {
  int number_failed = 0;
  Suite *s;
  SRunner *sr;
  s = sprintf_test();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}