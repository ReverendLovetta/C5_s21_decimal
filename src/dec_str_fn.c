#include "./s21_decimal.h"

// Переворот массива. На вход подаётся строка и его размер
// Можно вызывать в виде reverse(string, (int)strlen(string))

void revers(char *src, int size) {
    int count = size;
    for (int i = 0; i < size / 2; i++) {
        char buff = src[i];
        src[i] = src[--count];
        src[count] = buff;
    }
}

// Сложение двух строк. В функцию передаётся 3 массива

int summ_two_string(char *num1, char *num2, char *result) {
    int res = 0;
    size_t i = 0;
    int carry = 0;
    for (; i < max_lenght(num1, num2); i++) {
        if ((res = char_to_int(num1[i]) + char_to_int(num2[i]) + carry) > 9) {
          carry = (res - res % 10) / 10;
        }
        result[i] = res % 10 + 48;
        if (res < 10) carry = 0;
    }
    if (carry > 0) 
        result[i] = carry + 48;
    return EXIT_SUCCESS;
}

// Сравнение двух строк и возврат наибольшей длины

size_t max_lenght(char *num1, char *num2) {
    return (strlen(num1) >= strlen(num2)) ? strlen(num1) : strlen(num2);
}

// Перевод ascii символа в целочисленный int для совершения математических операций

int char_to_int(char a) { return (a <= '9' && a >= '0') ? a - '0' : 0; }

// Вставка в строку точки, разделяющей целое и десятичную часть. 
// СТРОКА ОБЯЗАТЕЛЬНО ДОЛЖНА БЫТЬ ПЕРЕДАНА ЗАДОМ НАПЕРЁД
// Функция перезаписывает новую строку в результат. 
// В качестве аргумента передаётся строка и количество символов, которое должно быть за
// точкой

void dot_insert(char *result, size_t period_length) {
    char temp[BUF];
    memset(temp, '\0', BUF);
    int j = 0, i = 0;
    size_t k = strlen(result);
    if (period_length == 1) {
        return;
    }
    while (period_length > 1) {
        if (result[j] == '\0')
            temp[i] = '0';
        else
            temp[i] = result[j];
        i++;
        j++;
        k--;
        period_length -= 1;
    }
    temp[i] = '.';
    i++;
    while (k > 0) {
        temp[i] = result[j];
        i++;
        j++;
        k--;
    }
    memset(result, '\0', BUF);
    strcpy(result, temp);
}

// Подсчёт количества символов в строке после точки

int digits_aft_dot(char *dec) {
    char *sft1 = strchr(dec, '.');  // Define dot position
    // Count digits after dot. If sft1 == NULL return 0
    return (!sft1) ? 0 : (int)strlen(dec) - (sft1 - dec + 1);  
}

// Удаление лишних нулей в конце дробной части.
// Массив должен быть подан задом наперёд

char *zero_cutter(char *result) {
    char temp[BUF] = {'\0'};
    int i = 0;
    while (result[i] == '0') {
        i++;
    }
    for (int j = 0; i < (int)strlen(result); i++) {
        temp[j] = result[i];
        j++;
    }
    strcpy(result, temp);
    return result;
}
