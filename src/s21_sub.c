#include "s21_decimal.h"

// Вспомогательные функции для s21_sub():_____________________________

// Сравниваем модули чисел
int compare_val(s21_decimal *val_1, s21_decimal *val_2);

// Вычитание 2-х чисел через строки
int sub_val(s21_decimal val_1, s21_decimal val_2, s21_decimal *res);

// Превращения числа в 0
int result_0(s21_decimal *res);

// Вычитает 2 числа (1-е > 2-го). Работает со строками
void sub_str(char *str1, char *str2, char *str_r, int len);
//_____________________________________________________________________

/* Функция s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal
 * *result). Вычитает из value_1 value_2 и записывает в result.
 * Возвращеет код ошибки:
 *        0 - ОК
 *        1 - число слишком велико или равно бесконечности
 *        2 - число слишком мало или равно отрицательной бесконечности
 *        3 - деление на 0 */
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int status = 0;
  unsigned int sign_1 = 0, sign_2 = 0, sign_0 = 0;  // 0: "+", 1: "-"
  unsigned int cmp = 0,
               check = 0;  // cmp = 0: |val_1| > |val_2|, cmp = 1: |val_1| <
                           // |val_2|, cmp = 2: |val_1| = |val_2|

  sign_1 = checkbit(value_1.bits[3], 31);
  sign_2 = checkbit(value_2.bits[3], 31);
  remove_sign_sub(&value_1.bits[3]);
  remove_sign_sub(&value_2.bits[3]);
  cmp = compare_val(&value_1, &value_2);
  check = sign_1 | sign_2 << 1 | cmp << 2;
  switch (check) {
    case 0b00000000: {
      status = sub_val(value_1, value_2, result);
      break;
    }
    case 0b00000001: {
      status = s21_add(value_1, value_2, result);
      sign_0 = 1;
      break;
    }
    case 0b00000010: {
      status = s21_add(value_1, value_2, result);
      break;
    }
    case 0b00000011: {
      status = sub_val(value_1, value_2, result);
      sign_0 = 1;
      break;
    }
    case 0b00000100: {
      status = sub_val(value_2, value_1, result);
      sign_0 = 1;
      break;
    }
    case 0b00000101: {
      status = s21_add(value_1, value_2, result);
      sign_0 = 1;
      break;
    }
    case 0b00000110: {
      status = s21_add(value_1, value_2, result);
      break;
    }
    case 0b00000111: {
      status = sub_val(value_2, value_1, result);
      break;
    }
    case 0b00001000: {
      status = result_0(result);
      break;
    }
    case 0b00001001: {
      status = s21_add(value_1, value_2, result);
      sign_0 = 1;
      break;
    }
    case 0b00001010: {
      status = s21_add(value_1, value_2, result);
      break;
    }
    case 0b00001011: {
      status = result_0(result);
      break;
    }
    default: {
      fprintf(stderr, "s21_sub: Ошибка при определении знака числа\n");
      exit(-1);
    }
  }
  if (sign_0 == 1) {
    setbit(&result->bits[3], 31);
  }
  return status;
}

void remove_sign_sub(u_int32_t *val) { *val = *val & (~(1 << 31)); }

int compare_val(s21_decimal *val_1, s21_decimal *val_2) {
  int tmp = 0;

  if (s21_is_equal(*val_1, *val_2) == 1) {
    tmp = 2;
  } else if (s21_is_less(*val_1, *val_2) == 1) {
    tmp = 1;
  } else {
    tmp = 0;
  }
  return tmp;
}

int result_0(s21_decimal *res) {
  res->bits[0] = 0;
  return 0;
}

int sub_val(s21_decimal val1, s21_decimal val2, s21_decimal *res) {
  unsigned int exp1 = 0, exp2 = 0;
  int cmp = 0, status = 0;
  char str1[BUF] = {0}, str2[BUF] = {0}, str_r[BUF] = {0}, tmp[100] = {0},
       tmp2[BUF] = {0};
  /* tmp -  массив символов с кол-вом нулей, необходимых, чтобы невелировать
  степень */
  int len1 = 0, len2 = 0;

  for (unsigned int i = 16; i < 21; i++) {
    exp1 |= ((unsigned int)checkbit(val1.bits[3], i) << (i - 16));
    exp2 |= ((unsigned int)checkbit(val2.bits[3], i) << (i - 16));
  }
  cmp = (int)exp1 - (int)exp2;
  if (cmp != 0) {
    memset(tmp, '0', abs(cmp));
  }
  dec_to_string(&val1, str1);
  dec_to_string(&val2, str2);
  if (cmp > 0) {
    strncat(str2, tmp, abs(cmp));
  }
  if (cmp < 0) {
    strncat(str1, tmp, abs(cmp));
  }
  len1 = strlen(str1);
  len2 = strlen(str2);
  if ((len1 - len2) > 0) {
    memset(tmp2, '0', len1 - len2);
  }
  strncat(tmp2, str2, len2);
  sub_str(str1, tmp2, str_r, len1);
  status = bank_round(str_r, 0);
  *res = char_to_decimal(str_r);
  return status;
}

void sub_str(char *str1, char *str2, char *str_r, int len) {
  int buf = 0;

  memset(str_r, '0', len);
  len -= 1;
  for (int i = len; i >= 0; i--) {
    if (str1[i] == '.') {
      str_r[i] = '.';
      continue;
    }
    buf = str1[i] - '0';
    if (str2[i] > str1[i]) {
      for (int j = i - 1, count = 0; j >= 0; j--) {
        if (str1[j] == '0') {
          count++;
          continue;
        } else {
          if (str1[j] == '.') {
            continue;
          }
          str1[j] = ((str1[j] - '0') - 1) + '0';
          for (; count >= 0; count--) {
            if (str1[i - 1 - count] == '.') {
              continue;
            }
            str1[i - 1 - count] = '9';
          }
          break;
        }
      }
      buf += 10;
    }
    str_r[i] = (buf - (str2[i] - '0')) + '0';
  }
  return;
}
