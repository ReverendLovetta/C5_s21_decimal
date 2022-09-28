#include "./s21_decimal.h"


int compare_str(char *temp, int sign); // Сравнение строки temp с эталоном

int bank_round(char *str, int sign) {
    int result = 0;
    char temp[BUF] = {'\0'};
    // Сначала определяем количество знаков перед запятой
    int int_part = (int)strlen(str) - digits_aft_dot(str);
    // And float part
    int float_part = digits_aft_dot(str) - 1;
    printf("INT_PART: %d\nFLOAT_PART: %d\n", int_part, float_part);
    // If integer part is more then 29 digits, then set result code
    if (int_part > 29) {
        if (sign == 0)
            result = 1;
        else if (sign == 1)
            result = 2;
    } else {
        // Rest of code
    }
    printf("OFFSET: %d\n", int_part);
    // Удаляем запятую
    remove_dot(str, temp);

    // Потом определяем количество знаков после удаления запятой
    int int_part2 = (int)strlen(temp);
    if ((int_part2 - int_part) != 0) {
        result = compare_str(temp, sign);
    }
    printf("RESULT: %d\n", result);

    printf("OFFSET: %d\n", int_part2);
    printf("STR: %s\n", temp);
    return result;
}


int compare_str(char *temp, int sign) {
    int result = 0;
    char *max_decimal = MAX_DECIMAL_STR;
    int length = (int)strlen(temp);
    for (int i = 0; i < length; i++) {
        if (temp[i] == max_decimal[i])
            // Invoke my round here if i == 28 && i < length
            continue;
        else if (temp[i] < max_decimal[i]) {
            if (i == 28 && i < length)
                // Здесь вызвать функицю округления
                
            result = SUCCESS;
            break;
        }
        else if (temp[i] > max_decimal[i]) {
            if (sign == 0)
                result = LARGE;
            else if (sign == 1) {
                result = SMALL;
            }
        }
    }
    return result;
}
