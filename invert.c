//inversion concept
//my On^2 solution did not work out
// this is O(nlogn) solution taught and explained by claude 
// review it 
#include <stdio.h>
#include <stdlib.h>

/**
 * OPTIMIZED INVERSION COUNT USING MERGE SORT
 * 
 * Original Code: O(n²) - nested loops checking every pair
 * Optimized Code: O(n log n) - merge sort based counting
 * 
 * For n=10000: Original ~50M operations vs Optimized ~133K operations
 * That's about 375x faster!
 */

// Merge two sorted halves and count inversions
long long mergeAndCount(int arr[], int temp[], int left, int mid, int right) {
    int i = left;    // Starting index of left subarray
    int j = mid + 1; // Starting index of right subarray
    int k = left;    // Starting index to be sorted
    long long invCount = 0;
    
    // Merge the two halves while counting inversions
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            // No inversion - element from left is smaller
            temp[k++] = arr[i++];
        } else {
            // Inversion found!
            // All remaining elements in left subarray (from i to mid)
            // are greater than arr[j], so count them all
            temp[k++] = arr[j++];
            invCount += (mid - i + 1); // KEY OPTIMIZATION: count all inversions at once
        }
    }
    
    // Copy remaining elements from left subarray
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    
    // Copy remaining elements from right subarray
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    
    // Copy sorted elements back to original array
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
    
    return invCount;
}

// Recursive merge sort that counts inversions
long long mergeSortAndCount(int arr[], int temp[], int left, int right) {
    long long invCount = 0;
    
    if (left < right) {
        int mid = left + (right - left) / 2; // Avoid overflow
        
        // Count inversions in left half
        invCount += mergeSortAndCount(arr, temp, left, mid);
        
        // Count inversions in right half
        invCount += mergeSortAndCount(arr, temp, mid + 1, right);
        
        // Count split inversions (left element > right element)
        invCount += mergeAndCount(arr, temp, left, mid, right);
    }
    
    return invCount;
}

// Main function to count inversions
long long countInversions(int arr[], int n) {
    int* temp = (int*)malloc(n * sizeof(int));
    long long result = mergeSortAndCount(arr, temp, 0, n - 1);
    free(temp);
    return result;
}

int main() {
    int d;
    scanf("%d", &d); // Read number of test cases
    
    for (int test = 0; test < d; test++) {
        int n;
        scanf("%d", &n); // Read array size
        
        int* arr = (int*)malloc(n * sizeof(int)); // Dynamic allocation for large arrays
        
        // Read array elements
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        
        // Count inversions using optimized method
        long long inversions = countInversions(arr, n);
        
        printf("%lld\n", inversions); // Use %lld for long long
        
        free(arr); // Free memory
    }
    
    return 0;
}

/**
 * STEP-BY-STEP EXPLANATION:
 * 
 * 1. PROBLEM: Count inversions (pairs where i < j but arr[i] > arr[j])
 * 
 * 2. ORIGINAL APPROACH: O(n²)
 *    - Check every pair with nested loops
 *    - For n=10000, that's 50 million comparisons!
 * 
 * 3. OPTIMIZED APPROACH: O(n log n) using Modified Merge Sort
 *    - Key Insight: When merging sorted halves, if arr[i] > arr[j],
 *      then arr[i] is also greater than ALL elements after j in right half
 *    - Count inversions while sorting!
 * 
 * 4. HOW IT WORKS:
 *    Example: [2, 4, 1, 3, 5]
 *    
 *    Split:
 *    [2, 4] and [1, 3, 5]
 *    
 *    When merging:
 *    - Compare 2 and 1: 2>1, so inversion! Count = (mid-i+1) = 2 inversions
 *      (both 2 and 4 are greater than 1)
 *    - Compare 2 and 3: 2<3, no inversion
 *    - Compare 4 and 3: 4>3, inversion! Count = 1
 * 
 * 5. THREE TYPES OF INVERSIONS:
 *    - Left half inversions (counted in left recursion)
 *    - Right half inversions (counted in right recursion)
 *    - Split inversions (counted during merge)
 * 
 * 6. COMPLEXITY ANALYSIS:
 *    Time: O(n log n) - same as merge sort
 *    Space: O(n) - temporary array
 * 
 * 7. OTHER IMPROVEMENTS:
 *    - Removed \n from scanf (unnecessary and can cause issues)
 *    - Used long long to prevent overflow for large counts
 *    - Dynamic allocation instead of VLA for portability
 *    - Better variable names (test instead of reusing i)
 *    - Added comments for clarity
 */
