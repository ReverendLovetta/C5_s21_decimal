#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIGN 0x80000000
#define MAX_INT_SHIFT 31
#define BUF 1024
#define MAX_DECIMAL 79228162514264337593543950335.0
#define MIN_DECIMAL -79228162514264337593543950335.0

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
<<<<<<< HEAD
// Функция для копирования значения из одного deecimal в другой
int s21_decimal_copy(s21_decimal src, s21_decimal *dest);
// Функция для умножения decimal на -1
int s21_negate(s21_decimal value, s21_decimal *result);

// Все функции необходимые для обработки флоат

// Фунция для отображение флоата в памяти
float float_bit_output(float *a, float mantissa, int *exponent,
                       s21_decimal *dst, int *counter_step);
// Функция для записи степени в децимал
void zapis_stepeni_v_decimal(int a, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_float(s21_decimal *dst, float src);
// Функция для представления формулы записи в флоата в памяти и перевод формулы
// для записи его в тип децимал для правильного отображения всех знаков флоата
void perezapis_decimal(s21_decimal *src, s21_decimal *dst, int *exponent);
// Функция для представления формулы записи в флоата в памяти и перевод формулы
// для записи его в тип децимал для правильного отображения всех знаков флоата
// при экспоненте меньше 23
void perezapis_decimal_exp_menshe_23(float *a, float mantissa, int *exponent,
                                     s21_decimal *dst, int *counter_step);
// Умножение децимал чисел
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_is_greater(s21_decimal *src, s21_decimal *dst);
int s21_is_greater_or_equal(s21_decimal *src, s21_decimal *dst);

#endif
