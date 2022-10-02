#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkbit(const int value, const int position) {
  return ((value & (1 << position)) != 0);
}

int bit_output(int a) {
  size_t len = sizeof(int) * CHAR_BIT;
  for (int j = 0; j < 1; j++) {
    printf("bits%d\t", j);
    for (int k = 31; k >= 0; k--) {
      if (k < 10)
        printf("%-2d ", k);
      else
        printf("%-3d", k);
    }
    printf("\n\t");
    for (size_t i = len; i > 0; i--) {
      if (checkbit(a, i - 1) == 1)
        printf("\x1b[31m%-2d\x1b[0m ", checkbit(a, i - 1));
      else
        printf("%-2d ", checkbit(a, i - 1));
    }
    printf("\n\n");
  }
  return 0;
}

int main() {
  long long int a = LONG_MAX;
  int b = (int)a;
  // unsigned int b = UINT_MAX;
  // printf("\nSIGNED INT: %d\n\n", a);
  // bit_output(a);
  printf("\nUNSIGNED INT: %d\n\n", b);
  // bit_output(b);
  return 0;
}

