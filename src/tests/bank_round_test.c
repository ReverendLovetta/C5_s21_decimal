#include "../header.h"
// MAX_DECIMAL 79228162514264337593543950335

START_TEST(bank_round_1) {
    char str[BUF] = "78228162514264337593543950335.89";
    char etalon[BUF] = "78228162514264337593543950336";
    ck_assert_int_eq(bank_round(str, POSITIVE), 0);
    ck_assert_str_eq(str, etalon);
}
END_TEST

START_TEST(bank_round_2) {
    char str[BUF] = "9.999999999999999999999999999999";
    char etalon[BUF] = "10";
    ck_assert_int_eq(bank_round(str, POSITIVE), 0);
    ck_assert_str_eq(str, etalon);
}
END_TEST

START_TEST(bank_round_3) {
    char str[BUF] = "1231527195718295.716295812782912389146";
    char etalon[BUF] = "1231527195718295.7162958127829";
    ck_assert_int_eq(bank_round(str, POSITIVE), 0);
    ck_assert_str_eq(str, etalon);
}
END_TEST

START_TEST(bank_round_4) {
    char str[BUF] = "0.79228162514264337593543950335";
    char etalon[BUF] = "0.7922816251426433759354395034";
    ck_assert_int_eq(bank_round(str, POSITIVE), 0);
    ck_assert_str_eq(str, etalon);
}
END_TEST

START_TEST(bank_round_5) {
    char str[BUF] = "7.92281625142643375935439503350293";
    char etalon[BUF] = "7.9228162514264337593543950335";
    ck_assert_int_eq(bank_round(str, POSITIVE), 0);
    ck_assert_str_eq(str, etalon);
}
END_TEST

START_TEST(bank_round_6) {
    char str[BUF] = "0.00000000000000001328419158128";
    char etalon[BUF] = "0.0000000000000000132841915813";
    ck_assert_int_eq(bank_round(str, POSITIVE), 0);
    ck_assert_str_eq(str, etalon);
}
END_TEST

START_TEST(bank_round_7) {
    char str[BUF] = "79228162514.264337593543950336";
    char etalon[BUF] = "79228162514.26433759354395034";
    ck_assert_int_eq(bank_round(str, POSITIVE), 0);
    ck_assert_str_eq(str, etalon);
}
END_TEST

START_TEST(bank_round_8) {
    char str[BUF] = "79228162514.264337599543950335";
    char etalon[BUF] = "79228162514.26433759954395034";
    ck_assert_int_eq(bank_round(str, POSITIVE), 0);
    ck_assert_str_eq(str, etalon);
}
END_TEST

START_TEST(bank_round_9) {
    char str[BUF] = "0.0000000000000000000000000000123";
    char etalon[BUF] = "0";
    ck_assert_int_eq(bank_round(str, POSITIVE), 2);
    ck_assert_str_eq(str, etalon);
}
END_TEST

START_TEST(bank_round_10) {
    char str[BUF] = "78228162514264337593543950335.89";
    char etalon[BUF] = "78228162514264337593543950336";
    ck_assert_int_eq(bank_round(str, NEGATIVE), 0);
    ck_assert_str_eq(str, etalon);
}
END_TEST

START_TEST(bank_round_11) {
    char str[BUF] = "9.999999999999999999999999999999";
    char etalon[BUF] = "10";
    ck_assert_int_eq(bank_round(str, NEGATIVE), 0);
    ck_assert_str_eq(str, etalon);
}
END_TEST

START_TEST(bank_round_12) {
    char str[BUF] = "1231527195718295.716295812782912389146";
    char etalon[BUF] = "1231527195718295.7162958127829";
    ck_assert_int_eq(bank_round(str, NEGATIVE), 0);
    ck_assert_str_eq(str, etalon);
}
END_TEST

START_TEST(bank_round_13) {
    char str[BUF] = "0.79228162514264337593543950335";
    char etalon[BUF] = "0.7922816251426433759354395034";
    ck_assert_int_eq(bank_round(str, NEGATIVE), 0);
    ck_assert_str_eq(str, etalon);
}
END_TEST

START_TEST(bank_round_14) {
    char str[BUF] = "7.92281625142643375935439503350293";
    char etalon[BUF] = "7.9228162514264337593543950335";
    ck_assert_int_eq(bank_round(str, NEGATIVE), 0);
    ck_assert_str_eq(str, etalon);
}
END_TEST

START_TEST(bank_round_15) {
    char str[BUF] = "0.00000000000000001328419158128";
    char etalon[BUF] = "0.0000000000000000132841915813";
    ck_assert_int_eq(bank_round(str, NEGATIVE), 0);
    ck_assert_str_eq(str, etalon);
}
END_TEST

START_TEST(bank_round_16) {
    char str[BUF] = "79228162514.264337593543950336";
    char etalon[BUF] = "79228162514.26433759354395034";
    ck_assert_int_eq(bank_round(str, NEGATIVE), 0);
    ck_assert_str_eq(str, etalon);
}
END_TEST

START_TEST(bank_round_17) {
    char str[BUF] = "79228162514.264337599543950335";
    char etalon[BUF] = "79228162514.26433759954395034";
    ck_assert_int_eq(bank_round(str, NEGATIVE), 0);
    ck_assert_str_eq(str, etalon);
}
END_TEST

START_TEST(bank_round_18) {
    char str[BUF] = "0.0000000000000000000000000000123";
    char etalon[BUF] = "0";
    ck_assert_int_eq(bank_round(str, NEGATIVE), 2);
    ck_assert_str_eq(str, etalon);
}
END_TEST

START_TEST(bank_round_19) {
    char str[BUF] =    "79228162514264337593543950335.56738974";
    char etalon[BUF] = "79228162514264337593543950336";
    ck_assert_int_eq(bank_round(str, POSITIVE), 1);
    ck_assert_str_eq(str, etalon);
}
END_TEST

START_TEST(bank_round_20) {
    char str[BUF] =    "79228162514264337593543950335.56738974";
    char etalon[BUF] = "79228162514264337593543950336";
    ck_assert_int_eq(bank_round(str, NEGATIVE), 2);
    ck_assert_str_eq(str, etalon);
}
END_TEST

// MAX_DECIMAL 79228162514264337593543950335
START_TEST(bank_round_21) {
    char str[BUF] =    "79228162514264.43759354395033523459";
    char etalon[BUF] = "79228162514264.43759354395034";
    ck_assert_int_eq(bank_round(str, POSITIVE), 0);
    ck_assert_str_eq(str, etalon);
}
END_TEST

START_TEST(bank_round_22) {
    char str[BUF] =    "99228162514264.43759354395033523459";
    char etalon[BUF] = "99228162514264.43759354395034";
    ck_assert_int_eq(bank_round(str, POSITIVE), 0);
    ck_assert_str_eq(str, etalon);
}
END_TEST

START_TEST(bank_round_23) {
    char str[BUF] =    "111199228162514264.43759354395033523459";
    char etalon[BUF] = "111199228162514264.43759354395";
    ck_assert_int_eq(bank_round(str, POSITIVE), 0);
    ck_assert_str_eq(str, etalon);
}
END_TEST

START_TEST(bank_round_24) {
    char str[BUF] =    "111199228162514264.43759354395033523459";
    char etalon[BUF] = "111199228162514264.43759354395";
    ck_assert_int_eq(bank_round(str, NEGATIVE), 0);
    ck_assert_str_eq(str, etalon);
}
END_TEST

START_TEST(bank_round_25) {
    char str[BUF] =    "0.000000000000000000000000000000000123";
    char etalon[BUF] = "0";
    ck_assert_int_eq(bank_round(str, POSITIVE), 2);
    ck_assert_str_eq(str, etalon);
}
END_TEST

START_TEST(bank_round_26) {
    char str[BUF] =    "79228162514264337593543950336";
    char etalon[BUF] = "79228162514264337593543950336";
    ck_assert_int_eq(bank_round(str, POSITIVE), 1);
    ck_assert_str_eq(str, etalon);
}
END_TEST

Suite * sprintf_test(void) {
    Suite *s;
    TCase *tc_bank_round;

    s = suite_create("Bank round");

    tc_bank_round = tcase_create("Bank round");
    tcase_add_test(tc_bank_round, bank_round_1);
    tcase_add_test(tc_bank_round, bank_round_2);
    tcase_add_test(tc_bank_round, bank_round_3);
    tcase_add_test(tc_bank_round, bank_round_4);
    tcase_add_test(tc_bank_round, bank_round_5);
    tcase_add_test(tc_bank_round, bank_round_6);
    tcase_add_test(tc_bank_round, bank_round_7);
    tcase_add_test(tc_bank_round, bank_round_8);
    tcase_add_test(tc_bank_round, bank_round_9);
    tcase_add_test(tc_bank_round, bank_round_10);
    tcase_add_test(tc_bank_round, bank_round_11);
    tcase_add_test(tc_bank_round, bank_round_12);
    tcase_add_test(tc_bank_round, bank_round_13);
    tcase_add_test(tc_bank_round, bank_round_14);
    tcase_add_test(tc_bank_round, bank_round_15);
    tcase_add_test(tc_bank_round, bank_round_16);
    tcase_add_test(tc_bank_round, bank_round_17);
    tcase_add_test(tc_bank_round, bank_round_18);
    tcase_add_test(tc_bank_round, bank_round_19);
    tcase_add_test(tc_bank_round, bank_round_20);
    tcase_add_test(tc_bank_round, bank_round_21);
    tcase_add_test(tc_bank_round, bank_round_22);
    tcase_add_test(tc_bank_round, bank_round_23);
    tcase_add_test(tc_bank_round, bank_round_24);
    tcase_add_test(tc_bank_round, bank_round_25);
    tcase_add_test(tc_bank_round, bank_round_26);
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
