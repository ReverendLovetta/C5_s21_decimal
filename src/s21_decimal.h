#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

#define SIGN 0x80000000

typedef struct {
    int bits[4];
} s21_decimal;

int bit_output(s21_decimal *a);
int s21_from_int_to_decimal(int src, s21_decimal *dst);

#endif
