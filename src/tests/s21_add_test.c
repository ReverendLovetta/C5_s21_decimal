#include "../header.h"

START_TEST(add_1) {
    char s21_result[BUF];
    char result[BUF];
    memset(result, '\0', BUF);
    memset(s21_result, '\0', BUF);
    int a = 421, b = 79; 
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    s21_from_int_to_decimal(a, &number1);
    s21_from_int_to_decimal(b, &number2);
    s21_decimal dec_result = {0};
    s21_add(number1, number2, &dec_result);
    dec_output(&dec_result, s21_result);
    sprintf(result, "%d", a + b);
    ck_assert_str_eq(result, s21_result);
}
END_TEST

Suite * sprintf_test(void) {
    Suite *s;
    TCase *tc_add;

    s = suite_create("s21_add");

    tc_add = tcase_create("s21_add");
    tcase_add_test(tc_add, add_1);
    suite_add_tcase(s, tc_add);

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
