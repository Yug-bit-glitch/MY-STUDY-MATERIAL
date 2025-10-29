Here's the corrected code with fixes for the overflow and edge case issues:

```c
#include<stdio.h>
#include<stdlib.h>

int compare(const void* a, const void *b){
    long long p1 = *(long long*)a;
    long long p2 = *(long long*)b;
    // Fix: Avoid overflow in comparison
    if(p1 < p2) return -1;
    if(p1 > p2) return 1;
    return 0;
}

int lowerindex(long long* arr, long long x, int n){
    int low = 0;
    int high = n - 1;
    int idx = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] >= x){
            idx = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return idx;
}

int highindex(long long* arr, long long x, int n){
    int low = 0;
    int high = n - 1;
    int idx = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] <= x){
            idx = mid;
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return idx;
}

int main(){
    int n, q;
    scanf("%d %d", &n, &q);
    long long arr[n];
    for(int i = 0; i < n; i++){
        scanf("%lld", &arr[i]);
    }
    qsort(arr, n, sizeof(long long), compare);
    
    for(int i = 0; i < q; i++){
        long long a, b;
        scanf("%lld %lld", &a, &b);
        
        int low_idx = lowerindex(arr, a, n);
        int high_idx = highindex(arr, b, n);
        
        // Fix: Handle edge cases where no elements in range
        if(low_idx == -1 || high_idx == -1 || low_idx > high_idx){
            printf("0\n");
        }else{
            printf("%d\n", high_idx - low_idx + 1);
        }
    }
    return 0;
}
```

## Key Changes:

1. **Fixed `compare` function**: Uses conditional returns instead of subtraction to avoid integer overflow

2. **Changed parameter type**: `lowerindex` and `highindex` now take `long long x` instead of `int x` to match the query values

3. **Added edge case handling**: Checks if either index is `-1` or if `low_idx > high_idx` (no elements in range), then prints `0`

This corrected version will handle all edge cases properly and avoid overflow issues with large numbers.
