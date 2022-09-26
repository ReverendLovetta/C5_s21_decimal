#include "./s21_decimal.h"


int compare_str(char *temp, int sign); // Сравнение строки temp с эталоном

int bank_round(char *str, int sign) {
    int result = 0;
    char temp[BUF] = {'\0'};
    // Сначала определяем количество знаков перед запятой
    int offset = (int)strlen(str) - digits_aft_dot(str);
    printf("OFFSET: %d\n", offset);
    // Удаляем запятую
    remove_dot(str, temp);

    // Потом определяем количество знаков после удаления запятой
    int offset2 = (int)strlen(temp);
    if ((offset2 - offset) != 0) {
        result = compare_str(temp, sign);
    }
    printf("RESULT: %d\n", result);

    printf("OFFSET: %d\n", offset2);
    printf("STR: %s\n", temp);
    return result;
}


int compare_str(char *temp, int sign) {
    int result = 0;
    char *max_decimal = MAX_DECIMAL_STR;
    int length = (int)strlen(temp);
    for (int i = 0; i < length; i++) {
        if (temp[i] == max_decimal[i])
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
