#include "s21_decimal.h"

// Вспомогательные функции для s21_sub():_____________________________
// Берем число по модулю
void remove_sign(u_int32_t *val);

// Сравниваем модули чисел
int compare_val(s21_decimal *val_1, s21_decimal *val_2);

// Вычитание 2-х чисел через строки
int sub_val(s21_decimal *val_1, s21_decimal *val_2, s21_decimal *res);

// Превращения числа в 0
int result_0(s21_decimal *res);

// Вычитает 2 числа (1-е > 2-го). Работает со строками
void sub_str(char **tmp1, char **tmp2, char **tmp3, int flag);

/* Занимает из следующего разряда (если следующий 0, то заполняет его 9 и
 * занимает у следующего != 0). i принимает 2 значения: 0 - целая часть; 1 -
 * дробная часть. Функция работает рекурсивно.*/
int take_shift(char **tmp, char *str_ptr, int i);

/* Подготавлявает числа в виде строк для работы с дробной частью (если у
 * уменьшаемого дробная часть меньше, чем у вычитаемого) */
void check_afterpoint(char **tmp1, char **tmp2, int cnt1, int cnt2);
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

  sign_1 = checkbit(&value_1.bits[3], 31);
  sign_2 = checkbit(&value_2.bits[3], 31);
  remove_sign(&value_1.bits[3]);
  remove_sign(&value_2.bits[3]);
  cmp = compare_val(&value_1, &value_2);
  check = sign_1 | sign_2 << 1 | cmp << 2;
  switch (check) {
    case 0b00000000: {
      status = sub_val(&value_1, &value_2, result);
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
      status = sub_val(&value_1, &value_2, result);
      sign_0 = 1;
      break;
    }
    case 0b00000100: {
      status = sub_val(&value_2, &value_1, result);
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
      status = sub_val(&value_2, &value_1, result);
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

  return status;
}

void remove_sign(u_int32_t *val) { *val = *val & (~(1 << 31)); }

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

int sub_val(s21_decimal *val_1, s21_decimal *val_2, s21_decimal *res) {
  char str_1[35] = {0};
  char str_2[35] = {0};
  char str[BUF] = {0};
  char tmp1[3][35] = {0};
  char tmp2[3][35] = {0};
  char tmp3[3][69] = {0};
  int cnt1 = 0, cnt2 = 0;
  int flag = 0;  // Флаг, если дробная часть отсутствует у двоих чисел
  int status = 0;

  dec_to_string(val_1, str_1);
  dec_to_string(val_2, str_2);
  parsing_value(str_1, tmp1);
  parsing_value(str_2, tmp2);
  cnt1 = strlen(tmp1[1]);
  cnt2 = strlen(tmp2[1]);
  if (cnt1 == 0 && cnt2 == 0) {
    tmp3[1][0] = '0';
    flag = 1;
    sub_str(tmp1, tmp2, tmp3, flag);
  } else if (cnt1 > cnt2) {
    if (cnt2 == 0) {
      tmp2[1][0] = '0';
    }
    sub_str(tmp1, tmp2, tmp3, flag);
  } else {
    if (cnt1 == 0) {
      tmp1[1][0] = '0';
    }
    check_afterpoint(tmp1, tmp2, cnt1, cnt2);
    sub_str(tmp1, tmp2, tmp3, flag);
  }
  strcat(str, tmp3[0]);
  strcat(str, ".");
  strcat(str, tmp3[1]);
  if (strlen(str) > 32) {
    bank_round(str);
    if (*str == '0') {
      status = 2;
    } else {
      status = 1;
    }
  }
  *res = char_to_decimal(str);

  return status;
}

void parsing_value(char *str, char **tmp) {
  char *save_ptr = NULL;
  char *token = NULL;

  for (size_t i = 0;; str = NULL, i++) {
    token = strtok_r(str, ".", save_ptr);
    if (token == NULL) {
      break;
    }
    strcpy(token, tmp[i]);
  }
  return;
}

void sub_str(char **tmp1, char **tmp2, char **tmp3, int flag) {
  size_t i = 0, j = 0;
  char *str1_ptr = NULL, *str2_ptr = NULL;
  int shift = 0, val = 0;

  for (; i < 2; i++) {
    if (flag == 1 && i == 1) {
      break;
    }
    str1_ptr = tmp1[i] + strlen(tmp1[i]) - 1;
    str2_ptr = tmp2[i] + strlen(tmp2[i]) - 1;
    for (j = 0;; j++) {
      if (str2_ptr == tmp2[i]) {
        tmp3[i][j] = *str1_ptr;
        if (str1_ptr == tmp1[i]) {
          break;
        }
        str1_ptr--;
        continue;
      }
      val = (int)*str1_ptr;
      if ((int)(*str1_ptr) < (int)(*str2_ptr)) {
        val += 10;
        take_shift(tmp1[i], str1_ptr - 1, i);
      }
      tmp3[i][j] = (char)(val - (int)(*str2_ptr));
      str1_ptr--;
      str2_ptr--;
    }
  }
  return;
}

int take_shift(char **tmp, char *str_ptr, int i) {
  int shift = 0;
  if (i == 0) {
    if (*str_ptr == '0') {
      *str_ptr = '9';
      if (str_ptr == tmp[0]) {
        fprintf(stderr, "s21_sub:take_shift: Уменьшаемое меньше вычитаемого\n");
        exit(-5);
      }
      str_ptr--;
      shift = 1 + take_shift(tmp, str_ptr, i);
    } else {
      *str_ptr = (char)((int)(*str_ptr) - 1);
      shift++;
    }
  } else if (i == 1) {
    if (str_ptr == tmp[1] && *str_ptr == '0') {
      *str_ptr = '9';
      str_ptr = tmp[0] + strlen(tmp[0]) - 1;
      shift = 1 + take_shift(tmp, str_ptr, 0);
    } else if (str_ptr == '0') {
      *str_ptr = '9';
      str_ptr--;
      shift = 1 + take_shift(tmp, str_ptr, 1);
    } else {
      *str_ptr = (char)((int)(*str_ptr) - 1);
      shift++;
    }
  }
  return shift;
}

void check_afterpoint(char **tmp1, char **tmp2, int cnt1, int cnt2) {
  if (cnt1 < cnt2) {
    char str[35] = {0};
    for (size_t i = 0; i < cnt2 - cnt1 - 1; i++) {
      str[i] = '0';
    }
    strcat(str, tmp1[1]);
    strcpy(tmp1[1], str);
  }
  if (tmp2[1][0] != '0') {
    take_shift(tmp1, tmp1[1], 1);
    int val = (int)(tmp1[1][0]);
    val += 10;
    tmp1[1][0] = (char)(val - (int)(tmp2[1][0]));
    tmp2[1][0] = '0';
  }
  return;
}
