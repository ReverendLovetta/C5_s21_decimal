#include "../header.h"

START_TEST(add_1) {
 char s21_result[BUF] = {'\0'};
 char result[BUF] = {'\0'};
 int a = 421, b = 79, exit_code = 0; 
 s21_decimal number1 = {0};
 s21_decimal number2 = {0};
 s21_from_int_to_decimal(a, &number1);
 s21_from_int_to_decimal(b, &number2);
 s21_decimal dec_result = {0};
 exit_code = s21_add(number1, number2, &dec_result);
 dec_to_string(&dec_result, s21_result);
 sprintf(result, "%d", a + b);
 ck_assert_str_eq(result, s21_result);
 ck_assert_int_eq(exit_code, 0);
}
END_TEST

//  Число слишком велико или равно бесконечности  
START_TEST(add_2) {
  s21_decimal number1 = {0};
  s21_decimal number2 = {0};
  for (int i = 0; i < 3; i++) 
      number1.bits[i] = UINT_MAX;
  number2.bits[0] = 3;
  s21_decimal dec_result = {0};
  int exit_code = s21_add(number1, number2, &dec_result);
  ck_assert_int_eq(exit_code, 1);
}
END_TEST

// //  Число слишком мало или равно отрицательной бесконечности
START_TEST(add_3) {
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
    int exit_code = s21_add(number1, number2, &dec_result);
    ck_assert_int_eq(exit_code, 2);
}
END_TEST
//
START_TEST(add_4) {
    char s21_result[BUF] = {'\0'};
    char *a = "79228162514264337593543950334";
    char *b = "1";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    s21_decimal dec_result = {0};
    int exit_code = 0;
    exit_code = s21_add(number1, number2, &dec_result);
    dec_to_string(&dec_result, s21_result);
    ck_assert_str_eq("79228162514264337593543950335", s21_result);
    ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(add_5) {
    char *a = "79228162514264337593543950335";
    char *b = "4";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    s21_decimal dec_result = {0};
    int exit_code = 0;
    exit_code = s21_add(number1, number2, &dec_result);
    ck_assert_int_eq(exit_code, 1);
}
END_TEST

// Добавить тест add_6 cо сложением положительного и отрицательного числа

START_TEST(add_7) {
    char s21_result[BUF] = {'\0'};
    char *a = "7922816251426";
    char *b = "1152";
    s21_decimal number1 = {0};
    s21_decimal number2 = {0};
    number1 = char_to_decimal(a);
    number2 = char_to_decimal(b);
    s21_decimal dec_result = {0};
    int exit_code = 0;
    exit_code = s21_add(number1, number2, &dec_result);
    dec_to_string(&dec_result, s21_result);
    char result[BUF] = "7922816252578";
    ck_assert_str_eq(result, s21_result);
    ck_assert_int_eq(exit_code, 0);
}
END_TEST
//
//  // Добавить тест add_6 cо сложением положительного и отрицательного числа
//
START_TEST(add_9) {
 char s21_result[BUF] = {'\0'};
 char *a = "7922.8166";
 char *b = "1.152";
 s21_decimal number1 = {0};
 s21_decimal number2 = {0};
 number1 = char_to_decimal(a);
 number2 = char_to_decimal(b);
 s21_decimal dec_result = {0};
 int exit_code = 0;
 exit_code = s21_add(number1, number2, &dec_result);
 dec_to_string(&dec_result, s21_result);
 char result[BUF] = "7923.9686";
 ck_assert_str_eq(result, s21_result);
 ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(add_10) {
 char s21_result[BUF] = {'\0'};
 char *a = "7922.816615";
 char *b = "0.1523";
 s21_decimal number1 = {0};
 s21_decimal number2 = {0};
 number1 = char_to_decimal(a);
 number2 = char_to_decimal(b);
 s21_decimal dec_result = {0};
 int exit_code = 0;
 exit_code = s21_add(number1, number2, &dec_result);
 dec_to_string(&dec_result, s21_result);
 char result[BUF] = "7922.968915";
 ck_assert_str_eq(result, s21_result);
 ck_assert_int_eq(exit_code, 0);
}
END_TEST

START_TEST(add_11) {
 char s21_result[BUF] = {'\0'};
 char *a = "0.9614081257132168796771975167";// 28 знаков
 char *b = "0.05"; // 2 знака
 s21_decimal number1 = {0};
 s21_decimal number2 = {0};
 number1 = char_to_decimal(a);
 number2 = char_to_decimal(b);
 char a_1[BUF] = {'\0'};
 char b_1[BUF] = {'\0'};
 dec_to_string(&number1, a_1);
 dec_to_string(&number2, b_1);
 s21_decimal dec_result = {0};
 int exit_code = 0;
 exit_code = s21_add(number1, number2, &dec_result);
 dec_to_string(&dec_result, s21_result);
 char result[BUF] = "1.0114081257132168796771975167";
 ck_assert_str_eq(result, s21_result);
 ck_assert_int_eq(exit_code, 0);
}
END_TEST

// // START_TEST(add_11) {
// //     // char s21_result[BUF] = {'\0'};
// //     // 0011 0011 0011 0011 0011 0100 0000 0000 00000000000000000000000000000000
// //     char *a = "0.9614081257132168796771975167";// 28 знаков
// //     char *b = "0.05"; // 2 знака
// //     s21_decimal number1 = {0};
// //     s21_decimal number2 = {0};
// //     number1 = char_to_decimal(a);
// //     number2 = char_to_decimal(b);
// //     bit_output(&number1);
// //     printf("A: %s\nB: %s\n", a, b);
// //     char a_1[BUF] = {'\0'};
// //     char b_1[BUF] = {'\0'};
// //     dec_to_string(&number1, a_1);
// //     dec_to_string(&number2, b_1);
// //     printf("\n\nA_AFTER: %s\nB_AFTER: %s\n\n", a_1, b_1);
// //     // s21_decimal dec_result = {0};
// //     // int exit_code = 0;
// //     // exit_code = s21_add(number1, number2, &dec_result);
// //     // dec_to_string(&dec_result, s21_result);
// //     // char result[BUF] = "1.6345632502852867518708790067";
// //     // ck_assert_str_eq(result, s21_result);
// //     // ck_assert_int_eq(exit_code, 0);
// // }
// // END_TEST
//
//
Suite * sprintf_test(void) {
    Suite *s;
    TCase *tc_add;

    s = suite_create("s21_add");

    tc_add = tcase_create("s21_add");
    tcase_add_test(tc_add, add_1);
    tcase_add_test(tc_add, add_2);
    tcase_add_test(tc_add, add_3);
    tcase_add_test(tc_add, add_4);
    tcase_add_test(tc_add, add_5);
    tcase_add_test(tc_add, add_7);
    tcase_add_test(tc_add, add_9);
    tcase_add_test(tc_add, add_10);
    tcase_add_test(tc_add, add_11);
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
