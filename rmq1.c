// this is brute force solution 
// in this for loop is done from l to r
// just new part is the safety check of l,r
// limits.h is included for INT_MAX
#include <stdio.h>
#include <limits.h>

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    int A[n+1];
    for (int i = 1; i < n+1; ++i)
        scanf("%d", &A[i]);

    while (q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        if (l > r) { int t = l; l = r; r = t; }

        int mn = INT_MAX;
        for (int i = l; i <= r; ++i)
            if (A[i] < mn) mn = A[i];

        printf("%d\n", mn);
    }
    return 0;
}
