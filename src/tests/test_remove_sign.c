#include "../s21_decimal.h"

char *remove_sign(
    char *string,
    unsigned int *value);  // Проверяет наличие знака у числа в строке,
                           // записывает в байт структуру, удаляет из строки

int main() {
  s21_decimal ints = {0};
  char string[] = "12313214141412.3131413213";
  char *mass = NULL;
  mass = remove_sign(string, &ints.bits[3]);
  if (mass == NULL) {
    printf("test_remove_sign: FAIL\n");
  }
  return 0;
}

char *remove_sign(char *string, unsigned int *value) {
  char *mass = string;
  if (*string == '-') {
    mass += 1;
    *value += 1;
    *value = *value << 31;
  }
  return mass;
}
