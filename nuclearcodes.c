#include<stdio.h>

int solve(int n, long long k) {
    // Base case
    if (n == 1) return 0;
    
    // 1LL << (n-1) is a bitwise left shift: shifts 1 left by (n-1) positions
    // This calculates 2^(n-1) efficiently. For example:
    // 1 << 0 = 1 (2^0), 1 << 1 = 2 (2^1), 1 << 2 = 4 (2^2), 1 << 3 = 8 (2^3)
    // The 'LL' suffix makes it a long long to avoid integer overflow for large n
    long long mid = (1LL << (n - 1)) - 1; // Calculate 2^(n-1) - 1
    
    if (k == mid) {
        // Middle bit is always 1
        return 1;
    } else if (k < mid) {
        // In inv(C_{n-1}) section
        // inv flips the bit, so return 1 - solve(n-1, k)
        return 1 - solve(n - 1, k);
    } else {
        // In rev(C_{n-1}) section
        // Find the corresponding position in C_{n-1}
        long long mirror = (2LL * mid) - k;
        return solve(n - 1, mirror);
    }
}

int main(){
    int n;
    long long k;
    scanf("%d %lld", &n, &k);
    printf("%d", solve(n, k));
    return 0;
}
