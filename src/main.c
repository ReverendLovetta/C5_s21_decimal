#include "./s21_decimal.h"

int main() {
    s21_decimal a = {0};
    a.bits[0] = 314;
    a.bits[1] = 123456;
    a.bits[2] = 1234;
    a.bits[3] = 89234;
    bit_output(&a);
    return 0;
}
