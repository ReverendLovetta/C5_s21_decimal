#include "../header.h"

START_TEST(dec_to_str1) {
    char *a = "79228162514264337593543950335";
    char *b = "-79228162514264337593543950335";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    char result[BUF] = {'\0'};
    dec_to_string(&number1, result);
    ck_assert_str_eq(a, result);
    memset(result, '\0', BUF);
    dec_to_string(&number2, result);
    ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str2) {
    char *a = "79228162514264337593543950334";
    char *b = "-79228162514264337593543950334";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    char result[BUF] = {'\0'};
    dec_to_string(&number1, result);
    ck_assert_str_eq(a, result);
    memset(result, '\0', BUF);
    dec_to_string(&number2, result);
    ck_assert_str_eq(b, result);
}
END_TEST


START_TEST(dec_to_str3) {
    char *a = "792281625142643375935439534";
    char *b = "-792281625142643375935439534";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    char result[BUF] = {'\0'};
    dec_to_string(&number1, result);
    ck_assert_str_eq(a, result);
    memset(result, '\0', BUF);
    dec_to_string(&number2, result);
    ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str4) {
    char *a = "79228426433759354394";
    char *b = "-79228426433759354334";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    char result[BUF] = {'\0'};
    dec_to_string(&number1, result);
    ck_assert_str_eq(a, result);
    memset(result, '\0', BUF);
    dec_to_string(&number2, result);
    ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str5) {
    char *a = "4337593543950334";
    char *b = "-4337593543950334";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    char result[BUF] = {'\0'};
    dec_to_string(&number1, result);
    ck_assert_str_eq(a, result);
    memset(result, '\0', BUF);
    dec_to_string(&number2, result);
    ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str6) {
    char *a = "9251426433750334";
    char *b = "-9251426433750334";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    char result[BUF] = {'\0'};
    dec_to_string(&number1, result);
    ck_assert_str_eq(a, result);
    memset(result, '\0', BUF);
    dec_to_string(&number2, result);
    ck_assert_str_eq(b, result);
}
END_TEST


START_TEST(dec_to_str7) {
    char *a = "9426433750334";
    char *b = "-9426433750334";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    char result[BUF] = {'\0'};
    dec_to_string(&number1, result);
    ck_assert_str_eq(a, result);
    memset(result, '\0', BUF);
    dec_to_string(&number2, result);
    ck_assert_str_eq(b, result);
}
END_TEST


START_TEST(dec_to_str8) {
    char *a = "2124350334";
    char *b = "-2124350334";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    char result[BUF] = {'\0'};
    dec_to_string(&number1, result);
    ck_assert_str_eq(a, result);
    memset(result, '\0', BUF);
    dec_to_string(&number2, result);
    ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str9) {
    char *a = "9251334";
    char *b = "-9251334";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    char result[BUF] = {'\0'};
    dec_to_string(&number1, result);
    ck_assert_str_eq(a, result);
    memset(result, '\0', BUF);
    dec_to_string(&number2, result);
    ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str10) {
    char *a = "1334";
    char *b = "-1334";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    char result[BUF] = {'\0'};
    dec_to_string(&number1, result);
    ck_assert_str_eq(a, result);
    memset(result, '\0', BUF);
    dec_to_string(&number2, result);
    ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str11) {
    char *a = "1334";
    char *b = "-1334";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    char result[BUF] = {'\0'};
    dec_to_string(&number1, result);
    ck_assert_str_eq(a, result);
    memset(result, '\0', BUF);
    dec_to_string(&number2, result);
    ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str12) {
    char *a = "334";
    char *b = "-334";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    char result[BUF] = {'\0'};
    dec_to_string(&number1, result);
    ck_assert_str_eq(a, result);
    memset(result, '\0', BUF);
    dec_to_string(&number2, result);
    ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str13) {
    char *a = "34";
    char *b = "-34";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    char result[BUF] = {'\0'};
    dec_to_string(&number1, result);
    ck_assert_str_eq(a, result);
    memset(result, '\0', BUF);
    dec_to_string(&number2, result);
    ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str14) {
    char *a = "1";
    char *b = "-1";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    char result[BUF] = {'\0'};
    dec_to_string(&number1, result);
    ck_assert_str_eq(a, result);
    memset(result, '\0', BUF);
    dec_to_string(&number2, result);
    ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str15) {
    char *a = "0";
    char *b = "0";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    char result[BUF] = {'\0'};
    dec_to_string(&number1, result);
    ck_assert_str_eq(a, result);
    memset(result, '\0', BUF);
    dec_to_string(&number2, result);
    ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str16) {
    char *a = "7.7922816251426433759354395033";
    char *b = "-7.7922816251426433759354395033";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    char result[BUF] = {'\0'};
    dec_to_string(&number1, result);
    ck_assert_str_eq(a, result);
    memset(result, '\0', BUF);
    dec_to_string(&number2, result);
    ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str17) {
    char *a = "7.9228162514264337593543950335";
    char *b = "-7.9228162514264337593543950335";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    char result[BUF] = {'\0'};
    dec_to_string(&number1, result);
    ck_assert_str_eq(a, result);
    memset(result, '\0', BUF);
    dec_to_string(&number2, result);
    ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str18) {
    char *a = "7922816251426433.7593543950335";
    char *b = "-7922816251426433.7593543950335";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    char result[BUF] = {'\0'};
    dec_to_string(&number1, result);
    ck_assert_str_eq(a, result);
    memset(result, '\0', BUF);
    dec_to_string(&number2, result);
    ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str19) {
    char *a = "792281625142643375935.43950335";
    char *b = "-792281625142643375935.43950335";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    char result[BUF] = {'\0'};
    dec_to_string(&number1, result);
    ck_assert_str_eq(a, result);
    memset(result, '\0', BUF);
    dec_to_string(&number2, result);
    ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str20) {
    char *a = "7922816251426433759354395.0335";
    char *b = "-7922816251426433759354395.0335";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    char result[BUF] = {'\0'};
    dec_to_string(&number1, result);
    ck_assert_str_eq(a, result);
    memset(result, '\0', BUF);
    dec_to_string(&number2, result);
    ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str21) {
    char *a = "7922816251426433759354395033.5";
    char *b = "-7922816251426433759354395033.5";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    char result[BUF] = {'\0'};
    dec_to_string(&number1, result);
    ck_assert_str_eq(a, result);
    memset(result, '\0', BUF);
    dec_to_string(&number2, result);
    ck_assert_str_eq(b, result);
}
END_TEST
////////
START_TEST(dec_to_str22) {
    char *a = "0.0028162514264337593543950335";
    char *b = "-0.0028162514264337593543950335";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    char result[BUF] = {'\0'};
    dec_to_string(&number1, result);
    ck_assert_str_eq(a, result);
    memset(result, '\0', BUF);
    dec_to_string(&number2, result);
    ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str23) {
    char *a = "0.0000000514264337593543950335";
    char *b = "-0.0000000514264337593543950335";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    char result[BUF] = {'\0'};
    dec_to_string(&number1, result);
    ck_assert_str_eq(a, result);
    memset(result, '\0', BUF);
    dec_to_string(&number2, result);
    ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str24) {
    char *a = "0.0000000000264337593543950335";
    char *b = "-0.0000000000264337593543950335";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    char result[BUF] = {'\0'};
    dec_to_string(&number1, result);
    ck_assert_str_eq(a, result);
    memset(result, '\0', BUF);
    dec_to_string(&number2, result);
    ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str25) {
    char *a = "0.0000000000004337593543950335";
    char *b = "-0.0000000000004337593543950335";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    char result[BUF] = {'\0'};
    dec_to_string(&number1, result);
    ck_assert_str_eq(a, result);
    memset(result, '\0', BUF);
    dec_to_string(&number2, result);
    ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str26) {
    char *a = "0.0000000000000000000000950335";
    char *b = "-0.0000000000000000000000950335";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    char result[BUF] = {'\0'};
    dec_to_string(&number1, result);
    ck_assert_str_eq(a, result);
    memset(result, '\0', BUF);
    dec_to_string(&number2, result);
    ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str27) {
    char *a = "0.0000000000000000000000000005";
    char *b = "-0.0000000000000000000000000005";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    char result[BUF] = {'\0'};
    dec_to_string(&number1, result);
    ck_assert_str_eq(a, result);
    memset(result, '\0', BUF);
    dec_to_string(&number2, result);
    ck_assert_str_eq(b, result);
}
END_TEST

START_TEST(dec_to_str28) {
    char *a = "0.0000000000000000000000000001";
    char *b = "-0.0000000000000000000000000001";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    char result[BUF] = {'\0'};
    dec_to_string(&number1, result);
    ck_assert_str_eq(a, result);
    memset(result, '\0', BUF);
    dec_to_string(&number2, result);
    ck_assert_str_eq(b, result);
}
END_TEST

Suite * sprintf_test(void) {
    Suite *s;
    TCase *tc_mul;

    s = suite_create("Decimal to string");

    tc_mul = tcase_create("Decimal to string");
    tcase_add_test(tc_mul, dec_to_str1);
    tcase_add_test(tc_mul, dec_to_str2);
    tcase_add_test(tc_mul, dec_to_str3);
    tcase_add_test(tc_mul, dec_to_str4);
    tcase_add_test(tc_mul, dec_to_str5);
    tcase_add_test(tc_mul, dec_to_str6);
    tcase_add_test(tc_mul, dec_to_str7);
    tcase_add_test(tc_mul, dec_to_str8);
    tcase_add_test(tc_mul, dec_to_str9);
    tcase_add_test(tc_mul, dec_to_str10);
    tcase_add_test(tc_mul, dec_to_str11);
    tcase_add_test(tc_mul, dec_to_str12);
    tcase_add_test(tc_mul, dec_to_str13);
    tcase_add_test(tc_mul, dec_to_str14);
    tcase_add_test(tc_mul, dec_to_str15);
    tcase_add_test(tc_mul, dec_to_str16);
    tcase_add_test(tc_mul, dec_to_str17);
    tcase_add_test(tc_mul, dec_to_str18);
    tcase_add_test(tc_mul, dec_to_str19);
    tcase_add_test(tc_mul, dec_to_str20);
    tcase_add_test(tc_mul, dec_to_str21);
    tcase_add_test(tc_mul, dec_to_str22);
    tcase_add_test(tc_mul, dec_to_str23);
    tcase_add_test(tc_mul, dec_to_str24);
    tcase_add_test(tc_mul, dec_to_str25);
    tcase_add_test(tc_mul, dec_to_str26);
    tcase_add_test(tc_mul, dec_to_str27);
    tcase_add_test(tc_mul, dec_to_str28);
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
