#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define SIGN 0x80000000
#define MAX_INT_SHIFT 31
#define BUF 1024 

typedef struct {
    int bits[4];
} s21_decimal;

// Функция для вывода числа decimal в битовом отображении
int bit_output(s21_decimal *a);
// Функция для перевода числа int в decimal
int s21_from_int_to_decimal(int src, s21_decimal *dst);
// Функция, которая проверяет выставленный бит в конкретной позиции. 
// Возвращает 1, если искомый бит выствлен
int checkbit(const int value, const int position);
// Функция для вывода decimal в виде строки
int dec_output(s21_decimal *a, char *result);
// Функция для копирования значения из одного deecimal в другой
int s21_decimal_copy(s21_decimal src, s21_decimal *dest);
// Функция для умножения decimal на -1
int s21_negate(s21_decimal value, s21_decimal *result);

#endif
