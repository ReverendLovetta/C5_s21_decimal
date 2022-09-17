#include "../header.h"

START_TEST(mul_1) {
    char s21_result[BUF] = {'\0'};
    char result[BUF] = {'\0'};
    int a = 421, b = 79, exit_code = 0; 
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    s21_from_int_to_decimal(a, &number1);
    s21_from_int_to_decimal(b, &number2);
    s21_decimal dec_result = {0};
    exit_code = s21_mul(number1, number2, &dec_result);
    dec_to_string(&dec_result, s21_result);
    sprintf(result, "%d", a * b);
    ck_assert_str_eq(result, s21_result);
    ck_assert_int_eq(exit_code, 0);
}
END_TEST

//  Число слишком велико или равно бесконечности  
START_TEST(mul_2) {
    char s21_result[BUF], result[BUF];
    memset(result, '\0', BUF);
    memset(s21_result, '\0', BUF);
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    for (int i = 0; i < 3; i++) 
        number1.bits[i] = UINT_MAX;
    number2.bits[0] = 3;
    s21_decimal dec_result = {0};
    int exit_code = s21_mul(number1, number2, &dec_result);
    ck_assert_int_eq(exit_code, 1);
}
END_TEST

//  Число слишком мало или равно отрицательной бесконечности
START_TEST(mul_3) {
    char s21_result[BUF], result[BUF];
    memset(result, '\0', BUF);
    memset(s21_result, '\0', BUF);
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    for (int i = 0; i < 3; i++) 
        number1.bits[i] = UINT_MAX;
    number1.bits[3] |= SIGN;
    number2.bits[0] = 3;
    number2.bits[3] |= SIGN;
    s21_decimal dec_result = {0};
    int exit_code = s21_mul(number1, number2, &dec_result);
    ck_assert_int_eq(exit_code, 2);
}
END_TEST

START_TEST(mul_4) {
    char s21_result[BUF] = {'\0'};
    char *a = "79228162514264337593543950335";
    char *b = "1";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    s21_decimal dec_result = {0};
    int exit_code = 0;
    exit_code = s21_mul(number1, number2, &dec_result);
    dec_to_string(&dec_result, s21_result);
    ck_assert_str_eq("79228162514264337593543950335", s21_result);
    ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(mul_5) {
    char *a = "79228162514264337593543950335";
    char *b = "4";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    s21_decimal dec_result = {0};
    int exit_code = 0;
    exit_code = s21_mul(number1, number2, &dec_result);
    ck_assert_int_eq(exit_code, 1);
}
END_TEST

START_TEST(mul_6) {
    char *a = "79228162514264337593543950335";
    char *b = "-4";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    s21_decimal dec_result = {0};
    int exit_code = 0;
    exit_code = s21_mul(number1, number2, &dec_result);
    ck_assert_int_eq(exit_code, 2);
}
END_TEST


Suite * sprintf_test(void) {
    Suite *s;
    TCase *tc_mul;

    s = suite_create("s21_mul");

    tc_mul = tcase_create("s21_mul");
    tcase_add_test(tc_mul, mul_1);
    tcase_add_test(tc_mul, mul_2);
    tcase_add_test(tc_mul, mul_3);
    tcase_add_test(tc_mul, mul_4);
    tcase_add_test(tc_mul, mul_5);
    tcase_add_test(tc_mul, mul_6);
    suite_add_tcase(s, tc_mul);

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
