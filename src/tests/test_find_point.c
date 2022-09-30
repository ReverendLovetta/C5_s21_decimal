#include "../s21_decimal.h"

char *find_point(const char *string);  // Поиск начала дробной части

int main() {
  char mass[] = "123456.5345";
  char *p_point = NULL;
  p_point = find_point(mass);
  if (*p_point == '.') {
    printf("Sucsess\n");
  } else {
    printf("find_point returned NULL\n");
  }
  return 0;
}

char *find_point(const char *string) {
  char *p_point = NULL;
  char tmpmass[2] = ".";
  p_point = strstr(string, tmpmass);
  return p_point;
}
