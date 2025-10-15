#include <stdio.h>
#include <stdlib.h>

// Function to solve the distinct elements problem
void solve(int n, int b[]) {
    int *a = (int *)malloc(n * sizeof(int));
    
    // Start with first element as 1
    a[0] = 1;
    int next_val = 2;
    
    // Build array based on differences in b
    for (int i = 1; i < n; i++) {
        int diff = b[i] - b[i-1];
        
        // If maximum increase, use new distinct value
        if (diff == i + 1) {
            a[i] = next_val;
            next_val++;
        } 
        // Otherwise reuse value 1
        else {
            a[i] = 1;
        }
    }
    
    // Print result
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");
    
    free(a);
}

int main() {
    int t;
    scanf("%d", &t);
    
    // Process all test cases using for loop
    for (int tc = 0; tc < t; tc++) {
        int n;
        scanf("%d", &n);
        
        int *b = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
        }
        
        solve(n, b);
        
        free(b);
    }
    
    return 0;
}
