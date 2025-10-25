#include <stdio.h>

int main() {
    int a = 3, b = 4;
    int *p = &a;
    int *q = &b;
    int **r = &p;
    *r = q;
    **r = 10;

    printf("%d %d\n", a, b);
    return 0;
}
// when r is derefernced once we do p=q
