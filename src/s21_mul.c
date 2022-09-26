/* 
    Функция для умножения двух децимал. Принимает 2 числа децимал, которые надо умножить
    и указатель для записи результата. 
*/

#include "./s21_decimal.h"

// Само сложение
int mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result, int a);


// Считает сумму знаков после запятой
int shift_sum(int shift1, int shift2);

// Умножение двух строк
char *mult_two_string(char *temp_dec1, char *temp_dec2, char *res);

// Умножение строки на число
int mult_by_number(char *a, char *result, int number, int i);

// Проверка сроки с максимальным значением decimal
int size_check(char *dec, int sign);

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int exit_code = 0;
    // Если оба числа отрицательные
    if (checkbit(value_1.bits[3], MAX_INT_SHIFT) == 1 &&
        checkbit(value_2.bits[3], MAX_INT_SHIFT) == 1) {
        // Сначала привести отрицательные числа к положительному
        s21_negate(value_1, &value_1);
        s21_negate(value_2, &value_2);
        exit_code = mul(value_1, value_2, result, POSITIVE);

    // Если оба числа положительные
    } else if (checkbit(value_1.bits[3], MAX_INT_SHIFT) == 0 &&
             checkbit(value_2.bits[3], MAX_INT_SHIFT) == 0) {
        exit_code = mul(value_1, value_2, result, POSITIVE);

    // Вычитание, если одно число положительное, другое отрицательное
    } else {
        // Сначала привести оба числа к положительному
        if (checkbit(value_1.bits[3], MAX_INT_SHIFT) == 1)
            s21_negate(value_1, &value_1);
        if (checkbit(value_2.bits[3], MAX_INT_SHIFT) == 1)
            s21_negate(value_2, &value_2);
        // Произвести умножение
        exit_code = mul(value_1, value_2, result, NEGATIVE);
        // Дорисовать минус
        s21_negate(*result, result);
    }
    return exit_code;
}

int mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result, int sign) {
     char dec1[BUF] = {'\0'};
     char dec2[BUF] = {'\0'};
     dec_to_string(&value_1, dec1);
     dec_to_string(&value_2, dec2);
    // Считаем количество символов после точки у двух чисел
    int shift1 = digits_aft_dot(dec1) - 1;
    int shift2 = digits_aft_dot(dec2) - 1;
    int offset_sum = shift_sum(shift1, shift2);
    // printf("shift1: %d\nshift2: %d\noffset_sum: %d\n", 
    //         shift1, shift2, offset_sum);
    char temp_dec1[BUF] = {'\0'};
    char temp_dec2[BUF] = {'\0'};
    // Убираем точку и копируем строки во временный масив
    remove_dot(dec1, temp_dec1);
    remove_dot(dec2, temp_dec2);
    // Переворот строк задом наперёд
    revers(temp_dec1, (int)strlen(temp_dec1));
    revers(temp_dec2, (int)strlen(temp_dec2));
    char res[BUF] = {'\0'};
    // умножаем две строки
    mult_two_string(temp_dec1, temp_dec2, res);
    printf("RES: %s\n", res);
    // Добавляем точку
    if (shift1 > 0 || shift2 > 0) {
        dot_insert(res, offset_sum);
    printf("RES: %s\n", res);
    }

    if (shift1 > 0 || shift2 > 0) {
        zero_cutter(res);
    printf("RES: %s\n", res);
    }

    // Ещё раз переворачиваем строку
    revers(res, (int)strlen(res));
    printf("RES: %s\n", res);
    // // Округляем результат
    // bank_round(res, sign);

    // Сравниваем строку с максимальными значением
    switch (size_check(res, sign)) {
    case SMALL:
        return SMALL;
    case LARGE:
        return LARGE;
    case 0:
        // Записываем результат в decimal
        *result = char_to_decimal(res);
    }
    return SUCCESS;
}

int shift_sum(int shift1, int shift2) {
    int sum = 0;
    if (shift1 > 0)
        sum += shift1;
    if (shift2 > 0)
        sum += shift2;
    return sum;
}



/*
    Умножаем первую строку на каждый элемент второго массива и складываем результат.
    При умножении на второй и далее элемент сдвигаем строку и дополняем её нулями.
    Пример: 421 * 79 = 33259
      124
    * 97
    = 9873 +
      07492
    = 95233     После переворота массива будет 33259
*/

char *mult_two_string(char *temp_dec1, char *temp_dec2, char *res) {
    char temp[BUF] = {'\0'};
    for (size_t i = 0; i < strlen(temp_dec2); i++) {
        mult_by_number(temp_dec1, temp, char_to_int(temp_dec2[i]), i);
        summ_two_string(temp, res, res);
    }
    return res;
}

/*
   Так как вся обработка строк идёт задом наперёд сначала в res записываются нули,
   соответствующие сдвигу при умножении в столбик. Затем со сдвигом на число j производится
   умножение остальной строки и запись результата.
   Пример: 15 * 125 = 1875
     51
   * 521
   = 57 +
     003 + 
     0051
   = 5781       После переворота массива будет 1875
*/

int mult_by_number(char *a, char *result, int number, int j) {
    int carry = 0;  // Знак переноса
    int interm = 0;  // Промежуточный результат
    size_t i = 0;
    if (j > 0) {
      for (int i = 0; i < j; i++) {
          result[i] = '0';
      }
    }
    for (; i < strlen(a); i++) {
    if ((interm = ((a[i] - '0') * number + carry)) > 9) {
      carry = (interm - interm % 10) / 10;
    }
    result[i + j] = interm % 10 + 48;
    if (interm < 10) carry = 0;
    }
    if (carry > 0) result[i + j] = carry + 48;
    return EXIT_SUCCESS;
}

/*
    Функция для проверки числа на максимальную длину и проверки на
    максимально-минимальное значение decimal
*/

int size_check(char *dec, int sign) {
    int result = 0;
    int count = 0;  // Счётчик знаков без нуля, если число меньше 0 и запятой
    char temp[BUF] = {'\0'};

    // Сначала определяем количество знаков перед запятой
    int offset = (int)strlen(dec) - digits_aft_dot(dec);

    // Если знаков больше 0, то копируем значение в temp
    if (offset > 0) {
        // Сначала копируем цифры до запятой. Если перед точкой только 0, то пропускаем
        int i = 0;
        for (; i < offset; i++) {
            if (dec[0] == '0')
                break;
            temp[i] = dec[i];
            count++;
        }
        // Перемещаем позицию в массиве dec на следующий элемент за точкой
        // Копируем остальную часть массива
        offset++;
        for (; offset < (int)strlen(dec); offset++, i++) {
            temp[i] = dec[offset];
            count++;
        }

    } else {
        strcpy(temp, dec);
        count = (int)strlen(temp);
    }

    // Считаем количество знаков после запятой
    int after_dot = digits_aft_dot(dec) - 1;

    // Если общее количество значащих цифр больше 29 или количество знаков после запятой
    // больше 28
    // Если надо будет добавить округление числа, не помещающееся в мантиссу, то здесь
    if (count > 29 || after_dot > 28) {
        if (sign == 0)
            result = LARGE;
        else if (sign == 1) {
            result = SMALL;
        }
    } else if (count == 29) {
    // Если в строке 29 символов, сравниваем с максимальным decimal
        char *max_decimal = MAX_DECIMAL_STR;
        for (int i = 0; i < (int)strlen(temp); i++) {
            if (temp[i] == max_decimal[i])
                continue;
            else if (temp[i] < max_decimal[i])
                result = SUCCESS;
            else if (temp[i] > max_decimal[i]) {
				if (sign == 0)
					result = LARGE;
				else if (sign == 1) {
					result = SMALL;
				}
			}
        }
    }
    return result;
}











