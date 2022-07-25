#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int checkbit(const int value, const int position) {
    return ((value & (1 << position)) != 0);
}

int main() {
    float a = 314;
    size_t len = sizeof(float) * CHAR_BIT;
    int n = *((int*) &a);
    for (int k = 0; k < 32; k++) {
        if (k < 10)
            printf("%-2d ", k);
        else
            printf("%-3d", k);
    }
    printf("\n");
    for (size_t i = 0; i < len; i++) {
        printf("%-2d ", checkbit(n, i));
    }
    printf("\n");
    return 0;
}
