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

#include <stdio.h>

int main() {
    int a = 5, b = 6, c = 7;
    int *p1 = &a, *p2 = &b;
    int **q1 = &p1, **q2 = &p2;
    int ***r = &q1;

    **q2 = **q1 + 2;
    *r = q2;
    ***r = ***r + 3;

    printf("%d %d %d\n", a, b, c);
    return 0;
}

