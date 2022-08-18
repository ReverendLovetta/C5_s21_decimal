#include "./s21_decimal.h"

int add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int exit_code = 0;
    if (checkbit(value_1.bits[3], MAX_INT_SHIFT) == 1 &&
        checkbit(value_2.bits[3], MAX_INT_SHIFT) == 1) {
        printf("Функция для сложения двух децимал\n");
    } else if (checkbit(value_1.bits[3], MAX_INT_SHIFT) == 0 &&
             checkbit(value_2.bits[3], MAX_INT_SHIFT) == 0) {
        exit_code = add(value_1, value_2, result);
    } else {
        printf("Функции вычитания большего числа из меньшего\n");
    }
    return exit_code;
}

// Если число float, то проверить последний знак. Если 0, то порядок надо умножить на 10

int add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int carry = 0, temp = 0;
    int exit_code = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j <= MAX_INT_SHIFT; j++) {
            temp = checkbit(value_1.bits[i], j) + checkbit(value_2.bits[i], j);
            if (temp == 2) {
                if (carry == 1)
                    result->bits[i] ^= (1 << j);
                else {
                    carry = 1;
                }
            } else if (temp == 1) {
                if (carry == 0)
                    result->bits[i] ^= (1 << j);
            } else if (temp == 0) {
                if (carry == 1) {
                    result->bits[i] ^= (1 << j);
                    carry = 0;
                }
            }
        }
    }
    if (carry == 1 && checkbit(result->bits[3], MAX_INT_SHIFT)) 
        exit_code = 2;
    else if ((carry == 1) && (checkbit(result->bits[3], MAX_INT_SHIFT) == 0))
        exit_code = 1;
    return exit_code;
}
