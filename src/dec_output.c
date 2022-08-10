#include "./s21_decimal.h"

#define BUF 500

int mult_by_2(char *a, char *result);
int exp_string(char *result, int degree);
size_t max_lenght(char *num1, char *num2);
int char_to_int(char a);
int summ_two_string(char *num1, char *num2, char *result);
void revers(char *src, int size);

int dec_output(s21_decimal *a) {
    size_t len = sizeof(int) * CHAR_BIT;
    char result[BUF];
    char mid_result[BUF];
    memset(result, '\0', BUF);
    memset(mid_result, '\0', BUF);
    result[0] = '0';
    mid_result[0] = '0';
    int degree = -1;
    for (int i = 0; i < 3; i++) {
        for (size_t j = 0; j < len; j++) {
            memset(mid_result, '\0', BUF);
            degree++;
            if (checkbit(a->bits[i], j) == 1) {
                exp_string(mid_result, degree);
                summ_two_string(result, mid_result, result);
            }
        }
    }
    if (checkbit(a->bits[3], MAX_INT_SHIFT) == 1)
        result[strlen(result)] = '-';
    revers(result, strlen(result));
    printf("%s\n", result);
    return EXIT_SUCCESS;
}

int mult_by_2(char *a, char *result) {
    int carry = 0;
    int interm = 0;
    size_t i = 0;
    for (  ; i < strlen(a); i++) {
        if ((interm = ((a[i] - '0') * 2 + carry)) > 9) {
            carry = (interm - interm % 10) / 10;
        }
        result[i] = interm % 10 + 48;
        if (interm < 10)
            carry = 0;
    }
    if (carry > 0)
        result[i] = carry + 48;
    return EXIT_SUCCESS;
}

int exp_string(char *result, int degree) {
    result[0] = '2';
    if (degree == 0)
        result[0] = '1';
    else if (degree == 1) {
        result[0] = '2';
    }
    else
        for (int i = 0; i < (degree - 1); i++) {
            mult_by_2(result, result);
        }
    return EXIT_SUCCESS;
}

size_t max_lenght(char *num1, char *num2) {
    return (strlen(num1) >= strlen(num2)) ? strlen(num1) : strlen(num2);
}

int char_to_int(char a) {
    return (a <= '9' && a >= '0') ? a - '0' : 0;
}    

int summ_two_string(char *num1, char *num2, char *result) {
    int res = 0;
    size_t i = 0;
    int carry = 0;
    for ( ; i < max_lenght(num1, num2); i++) {
        if ((res = char_to_int(num1[i]) + char_to_int(num2[i]) + carry) > 9) {
            carry = (res - res % 10) / 10;
        }
        result[i] = res % 10 + 48;
        if (res < 10)
            carry = 0;
    }
    if (carry > 0)
        result[i] = carry + 48;
    return EXIT_SUCCESS;
}

void revers(char *src, int size) {
    int count = size;
    for (int i = 0; i < size /2; i++) {
        char buff = src[i];
        src[i] = src[--count];
        src[count] = buff;
    }
}
