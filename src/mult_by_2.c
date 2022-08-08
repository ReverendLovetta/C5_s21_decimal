#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int mult_by_2(char *a, char *result);

int main() {
    int b = 96;
    char result[500];
    //char *source = "2";
    memset(result, '\0', sizeof result);
    result[0] = '2';
    for (int i = 0; i < (b - 1); i++) {
        mult_by_2(result, result);
    }
    printf("%s\n", result);
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
