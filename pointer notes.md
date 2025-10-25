#include <stdio.h>

int main() {
    int a = 1, b = 2, c = 3;
    int *arr[] = {&a, &b, &c};
    int **p = arr;

    printf("%d ", **p);
    p++;
    printf("%d ", **p);
    p++;
    printf("%d\n", **p);
    return 0;
}
