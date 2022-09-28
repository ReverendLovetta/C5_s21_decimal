#include "../header.h"

START_TEST(bank_round_1) {
    // RESULT 79228162511264337593543950335 Почти максимальное значение decimal
    char str[BUF] = "78228162514264337593543950335.89";
    char etalon[BUF] = "78228162514264337593543950335";
    ck_assert_int_eq(bank_round(str, POSITIVE), 0);
    ck_assert_str_eq(str, etalon);
}
END_TEST


Suite * sprintf_test(void) {
    Suite *s;
    TCase *tc_bank_round;

    s = suite_create("Bank round");

    tc_bank_round = tcase_create("Bank round");
    tcase_add_test(tc_bank_round, bank_round_1);
    suite_add_tcase(s, tc_bank_round);

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
