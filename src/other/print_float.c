#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int checkbit(const int value, const int position) {
    return ((value & (1 << position)) != 0);
}

int main() {
    int a = 314;
    size_t len = sizeof(int) * CHAR_BIT;
    for (int k = 31; k >= 0; k--) {
        if (k < 10)
            printf("%-2d ", k);
        else
            printf("%-3d", k);
    }
    printf("\n");
    for (size_t i = len; i > 0; i--) {
        if (checkbit(a, i-1) == 1)
            printf("\x1b[31m%-2d\x1b[0m ", checkbit(a, i-1));
        else
            printf("%-2d ", checkbit(a, i-1));
    }
    printf("\n");
    return 0;
}
