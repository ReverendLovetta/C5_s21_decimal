/*
  Функция банковского округления числа с проверкой на максимальное значние
  мантиссы. Это алгоритм округления величин до целых чисел, при котором числа,
  равноудаленные от двух ближайших целых чисел, округляются до ближайшего
  четного целого числа. равноудаленные это занчит 0.5-> 0, 1.5->2, 2,5->2
  3,5->4 Другие десятичные дроби округляются, как и следовало ожидать, — от 0,4
  до 0, от 0,6 до 1, от 1,4 до 1, от 1,6 до 2 и т. д. Только числа x,5 получают
  «особую» обработку.

  Функция получает на вход строку, которую необходимо округлить и проверить,
  и знак числа.
  Подразумевается, что строка представляет собой результат каких-то
  математических функций и у неё может быть как слишком большая целая часть,
  так и дробная. Знак подаётся в виде двух возможных значений: POSITIVE = 0,
  NEGATIVE = 1, которые прописаны в заголовочном файле

  Если строка после округления помещается в мантиссу, то функция возвращает 0.
  Если число больше максимально-возможного значения, то возвращается 1.
  Если число больше максимально-возможного значения и у него отр.знак, то
  возвр. 2

  Если число дробное и не помещается в мантиссу, то округляется дробная часть
  до допустимых пределов

  ПРИМЕРЫ:
    1) 0.0000000000000000000000000000123 состоит из 31 значащих знаков
    (0 в целой части не считается). После округления до максимального
    порядка в 28 знаков отбрасываются последние 3 знака и результат
    получается 0.
    Число слишком мало, функция вернёт 0.

    2) 79228162514264337593543950335.56738974 состоит из 38 значащих цифр.
    Округляются дробная часть, которая не помещается в мантиссу и получается
    79228162514264337593543950336. Это число больше максимального decimal.
    Функция вернёт 1, если число положительное или 2, если отрицательное.

    3) 7.92281625142643375935439503350293 состоит из 33 значащих цифрю
    После округления части, которая не помещается в мантиссу, получается
    7.9228162514264337593543950335. Это число помещается в мантиссу.
    Функция вернёт 0
*/

#include "./s21_decimal.h"

int compare_str(char *temp, int sign);  // Сравнение строки temp с эталоном
int my_round(char *str, int sign);  // Округление
// Проверка числа на ноль после округления
int zero_check(char *str, int result);

int bank_round(char *str, int sign) {
  int result = 0;
  char temp[BUF] = {'\0'};
  // Сначала определяем количество знаков перед запятой
  int int_part = (int)strlen(str) - digits_aft_dot(str);
  // И количество знаков после запятой
  int float_part = digits_aft_dot(str);
  // Если целочисленная часть больше 29 знаков, проверяем знак и присваиваем код
  // возвр
  if (int_part > 29) {
    if (sign == 0) {
      result = 1;
    } else if (sign == 1) {
      result = 2;
    }
    // Если число из 29 знаков и float_part == 0, то проверяем с эталоном и
    // копируем в temp
  } else if (int_part == 29 && float_part == 0) {
    result = compare_str(str, sign);
    strcpy(temp, str);
  } else {
    // Удаляем точку
    remove_dot(str, temp);
    // И округляем число
    result = my_round(temp, sign);
  }
  // Если в ходе округления число 9 в целой части округлилось до 10, то
  // увеличиваем счётчик целой части, для корректного возврата точки
  if (temp[0] != str[0]) int_part++;
  int i = 0;
  char temp2[BUF] = {'\0'};
  // Копируем целочисленную часть
  for (; i < int_part; i++) {
    temp2[i] = temp[i];
  }
  // Это флаг остатка. Ноль, если в дробной части есть что-то кроме нулей
  int zero_flag = 0;
  // Проверяю остаток числа на нули
  for (int j = i; j < (int)strlen(temp); j++) {
    if (temp[j] != '0') zero_flag = 1;
  }
  // Если есть дробная часть, то ставлю точку и копирую остальную часть массива
  if (zero_flag == 1) {
    temp2[i] = '.';
    i++;
    for (; i <= (int)strlen(temp); i++) {
      temp2[i] = temp[i - 1];
    }
  }
  // Копирую результат в str через предварительное обнуление массива
  strcpy(temp, temp2);
  memset(str, '\0', BUF);
  strcpy(str, temp);

  return result;
}

void plus_step(s21_decimal *dst, int exponent) {
  if (exponent >= 64) {
    if ((dst->bits[2] & 1 << (exponent - 64)) == 0) {
      dst->bits[2] |= 1 << (exponent - 64);
    } else {
      dst->bits[2] -= pow(2, (exponent - 64));
      exponent += 1;
      plus_step(dst, exponent);
    }
  } else if (exponent >= 32) {
    if ((dst->bits[1] & 1 << (exponent - 32)) == 0) {
      dst->bits[1] |= 1 << (exponent - 32);
    } else {
      dst->bits[1] -= pow(2, (exponent - 32));
      exponent += 1;
      plus_step(dst, exponent);
    }
  } else {
    if ((dst->bits[0] & 1 << exponent) == 0) {
      dst->bits[0] |= 1 << exponent;
    } else {
      dst->bits[0] -= pow(2, exponent);
      exponent += 1;
      plus_step(dst, exponent);
    }
  }
  // Округлённое число ещё раз проверяем с эталоном
  result = compare_str(str, sign);
  // Проверяем, состоит ли число только из нулей
  result = zero_check(str, result);

  return result;
}

<<<<<<< HEAD
// Посимвольно проверяем строку с максимальным decimal.
// Если число такое же, то идём на следующую итерацию.
// Если число меньше, чем значение эталона, то завершаем цикл
// Если число больше, то в зависимости от знака ставим LARGE или SMALL

int compare_str(char *temp, int sign) {
  if (strlen(temp) < 29) return 0;
  int result = 0;
  char *max_decimal = MAX_DECIMAL_STR;
  int length = (int)strlen(max_decimal);
  for (int i = 0; i < length; i++) {
    if (temp[i] == max_decimal[i])
      continue;
    else if (temp[i] < max_decimal[i]) {
      result = SUCCESS;
      break;
    } else if (temp[i] > max_decimal[i]) {
      if (sign == 0)
        result = LARGE;
      else if (sign == 1) {
        result = SMALL;
=======
void bank_round(char *string_of_number) {
  if (string_of_number != NULL) {
    char *ukaz = string_of_number;
    while (1) {
      if (*ukaz == '\0') {
        break;
      }
      if (*ukaz == '.') {
        if (*(ukaz + 1) >= '5') {
          int number_before_dot = *(ukaz - 1) - '\0';
          int flag = 0;
          if (*(ukaz + 1) == '5') {
            ukaz += 1;
            while (*(ukaz + 1) != '\0') {
              if (*(ukaz + 1) != '0') {
                flag = 1;
                break;
              }
            }
          }
          if (flag == 1 || (flag == 0 && number_before_dot % 2 != 0)) {
            my_truncate(string_of_number);
            s21_decimal result_number = {0};
            result_number = char_to_decimal(string_of_number);
            plus_step(&result_number, 0);
            dec_to_string(&result_number, string_of_number);
          } else {
            if (number_before_dot % 2 == 0) {
              my_truncate(string_of_number);
            }
          }
        } else {
          my_truncate(string_of_number);
        }
        break;
>>>>>>> исправил функцию сравнения дописал флот ту децимал осталось протестировать
      }
      break;
    }
  }
  return result;
}

// Функция проверяет строку на что-то помимо нулей.
// Если строка состоит только из нулей (это уже округлённое значение), то
// возвращаем 2.

int zero_check(char *str, int result) {
  int zero_flag = 0;
  char temp[BUF] = {'\0'};
  remove_dot(str, temp);
  for (int i = 0; i < (int)strlen(temp); i++) {
    if (temp[i] != '0') {
      zero_flag = 1;
    }
  }
  if (zero_flag == 0) {
    result = 2;
  }
  return result;
}
