#include "../header.h"

START_TEST(test1) {
    int a = -83;

}
END_TEST

Suite * int_to_decimal_test(void) {
    Suite *s;
    TCase *tc_int_to_decimal;

    s = suite_create("s21_from_int_to_decimal");

    tc_int_to_decimal = tcase_create("int_to_decimal");
    tcase_add_test(tc_int_to_decimal, test1);
    suite_add_tcase(s, tc_int_to_decimal);

    return s;
}

int main() {
    int number_failed;
    Suite *s;
    SRunner *sr;
    s = int_to_decimal_test();
    sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
