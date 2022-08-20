
#include "../header.h"

START_TEST(negate_1) {
    char s21_result[BUF];
    char result[BUF];
    memset(result, '\0', BUF);
    memset(s21_result, '\0', BUF);
    int a = INT_MAX; 
    s21_decimal number = {0};
    s21_from_int_to_decimal(a, &number);
    s21_decimal dec_result = {0};
    s21_negate(number, &dec_result);
    dec_output(&dec_result, s21_result);
    sprintf(result, "%d", a * (-1));
    ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(negate_2) {
    char s21_result[BUF];
    char result[BUF];
    memset(result, '\0', BUF);
    memset(s21_result, '\0', BUF);
    int a = INT_MIN + 1; 
    s21_decimal number = {0};
    s21_from_int_to_decimal(a, &number);
    s21_decimal dec_result = {0};
    s21_negate(number, &dec_result);
    dec_output(&dec_result, s21_result);
    sprintf(result, "%d", a * (-1));
    ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(negate_3) {
    char s21_result[BUF];
    char result[BUF];
    memset(result, '\0', BUF);
    memset(s21_result, '\0', BUF);
    int a = 1059308; 
    s21_decimal number = {0};
    s21_from_int_to_decimal(a, &number);
    s21_decimal dec_result = {0};
    s21_negate(number, &dec_result);
    dec_output(&dec_result, s21_result);
    sprintf(result, "%d", a * (-1));
    ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(negate_4) {
    char s21_result[BUF];
    char result[BUF];
    memset(result, '\0', BUF);
    memset(s21_result, '\0', BUF);
    int a = -10530508; 
    s21_decimal number = {0};
    s21_from_int_to_decimal(a, &number);
    s21_decimal dec_result = {0};
    s21_negate(number, &dec_result);
    dec_output(&dec_result, s21_result);
    sprintf(result, "%d", a * (-1));
    ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(negate_5) {
    char s21_result[BUF];
    char result[BUF];
    memset(result, '\0', BUF);
    memset(s21_result, '\0', BUF);
    int a = 0; 
    s21_decimal number = {0};
    s21_from_int_to_decimal(a, &number);
    s21_decimal dec_result = {0};
    s21_negate(number, &dec_result);
    dec_output(&dec_result, s21_result);
    sprintf(result, "%d", a * (-1));
    ck_assert_str_eq(result, s21_result);
}
END_TEST

START_TEST(negate_6) {
    char s21_result[BUF];
    char result[BUF];
    memset(result, '\0', BUF);
    memset(s21_result, '\0', BUF);
    int a = -0; 
    s21_decimal number = {0};
    s21_from_int_to_decimal(a, &number);
    s21_decimal dec_result = {0};
    s21_negate(number, &dec_result);
    dec_output(&dec_result, s21_result);
    sprintf(result, "%d", a * (-1));
    ck_assert_str_eq(result, s21_result);
}
END_TEST

Suite * sprintf_test(void) {
    Suite *s;
    TCase *tc_negate;

    s = suite_create("s21_negate");

    tc_negate = tcase_create("s21_negate");
    tcase_add_test(tc_negate, negate_1);
    tcase_add_test(tc_negate, negate_2);
    tcase_add_test(tc_negate, negate_3);
    tcase_add_test(tc_negate, negate_4);
    tcase_add_test(tc_negate, negate_5);
    tcase_add_test(tc_negate, negate_6);
    suite_add_tcase(s, tc_negate);

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
