/* 
Функция для сдложения двух децимал. Принимает 2 числа децимал, которые надо сложить
и указатель для записи результата. Сложение осуществляется в случае, если оба числа
положительные и если оба числа отрицательные. Для сложения положительного и 
отрицательного числа используется функция вычитания
*/

#include "./s21_decimal.h"

#define SUCCESS 0
#define LARGE 1
#define SMALL 2

// Собственно, само сложение
int add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// Приведение числа с точкой к целому значению. Функция дорисовывает недостающие нули
char *aligner(char *dec, char *temp_dec, int diff);

// Определение разницы между двумя числами и возврат разницы
int shift_diff(int shift1, int shift2);

// Определение максимальной дробной части 
size_t max_shift(int shift1, int shift2);
// Common s21_mul
int size_check(char *dec);

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int exit_code = 0;
    // Если оба числа отрицательные
    if (checkbit(value_1.bits[3], MAX_INT_SHIFT) == 1 &&
        checkbit(value_2.bits[3], MAX_INT_SHIFT) == 1) {
        // Сначала привести отрицательные числа к положительному
        s21_negate(value_1, &value_1);
        s21_negate(value_2, &value_2);
        exit_code = add(value_1, value_2, result) + 1;
        // Умножить результат на -1
        s21_negate(*result, result);

    // Если оба числа положительные
    } else if (checkbit(value_1.bits[3], MAX_INT_SHIFT) == 0 &&
             checkbit(value_2.bits[3], MAX_INT_SHIFT) == 0) {
        exit_code = add(value_1, value_2, result);

    // Вычитание, если одно число положительное, другое отрицательное
    } else {
        printf("Функции вычитания большего числа из меньшего\n");
    }
    return exit_code;
}

int add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
     char dec1[BUF] = {'\0'};
     char dec2[BUF] = {'\0'};
     dec_to_string(&value_1, dec1);
     dec_to_string(&value_2, dec2);
    // Считаем количество символов после точки у двух чисел
    int shift1 = digits_aft_dot(dec1);
    int shift2 = digits_aft_dot(dec2);
    char temp_dec1[BUF] = {'\0'};
    char temp_dec2[BUF] = {'\0'};
    // Выравниваем дробную часть у двух чисел, добавляя недостающие нули и убирая точку
    aligner(dec1, temp_dec1, shift_diff(shift1, shift2));
    aligner(dec2, temp_dec2, shift_diff(shift2, shift1));
    // Переворот строк задом наперёд
    revers(temp_dec1, (int)strlen(temp_dec1));
    revers(temp_dec2, (int)strlen(temp_dec2));
    char res[BUF] = {'\0'};
    // Складываем две строки
    summ_two_string(temp_dec1, temp_dec2, res);
    // Добавляем точку
    if (shift1 > 0 || shift2 > 0) {
        dot_insert(res, max_shift(shift1, shift2));
    }
    if (shift1 > 0 || shift2 > 0)
        zero_cutter(res);
    // Ещё раз переворачиваем строку
    revers(res, (int)strlen(res));

    // Сравниваем строку с максимальным значением
    if (size_check(res)) {
        return LARGE;
    }
    // if (strcmp(res, MAX_DECIMAL_STR) > 0) {
    //     return LARGE;
    // }
    else
        // Записываем результат в decimal
        *result = char_to_decimal(res);

    return SUCCESS;
}



int shift_diff(int shift1, int shift2) {
    return (shift1 >= shift2)? 0 : shift2 - shift1;
}


char *aligner(char *dec, char *temp_dec, int shift) {
    int length = (int)strlen(dec);
    // Copy dec to temp_dec without dot
    for (int i = 0, j = 0; i < length; i++) {
        if (dec[i] != '.') {
            temp_dec[j] = dec[i];
            j++;
        }
    }
    // Fill temp_dec with zeroes at the end
    for (int i = 0; i < shift; i++) {
        temp_dec[(length - 1) + i] = '0';
    }
    return temp_dec;
}


size_t max_shift(int shift1, int shift2) {
    return (shift1 >= shift2) ? shift1 : shift2;
}

int size_check(char *dec) {
    char *max_decimal = MAX_DECIMAL_STR;
    int result = 0;
    int count = 1;
    char temp[BUF] = {'\0'};
    // Копируем массив в temp, пропуская идущие впереди нули и знак.
    // Считаем количество знаков в новом массиве
    for (size_t j = 0, i = 0; j < strlen(dec); j++, i++) {
        if (dec[j] == '0' || dec[j] == '-')
            continue;
        if (dec[j] != '.') {
            count++;
            temp[i] = dec[j];
        }
    }
    if (count > 29) {
        result = 1;
    }
    else if (count == 29) {
        for (int i = 0; i < (int)strlen(max_decimal); i++) {
            if (temp[i] <= max_decimal[i]) {
                continue;
            }
            else {
                result = 1;
                break;
            }
        }
    }
    return result;
}
