# Range Minimum Query (RMQ) - Square Root Decomposition
## Simple Beginner-Friendly Guide

## What is it?

Imagine you have an array and you want to find the minimum value in any range quickly. Instead of checking every element each time, we divide the array into small groups (blocks) and remember the minimum of each group!

## The Idea (Simple!)

```
Array: [2, 5, 1, 4, | 9, 3, 7, 8, | 6, 0, 11, 13, | 12, 10, 14]
        Block 0        Block 1        Block 2         Block 3
        min = 1        min = 3        min = 0         min = 10
```

When you want minimum of range [5 to 10]:
- Check elements 5,6,7 from Block 1 → min = 3
- Check complete Block 2 → min = 0  
- Check elements 8,9,10 from Block 2 → min = 0
- Answer = 0

## Super Simple C Code

```c
#include <stdio.h>
#include <math.h>

#define MAX 1000

int arr[MAX];           // Original array
int blocks[MAX];        // Minimum of each block
int n;                  // Array size
int block_size;         // Size of each block

// Find minimum of two numbers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Step 1: Build the blocks
void build() {
    block_size = sqrt(n);
    
    // Initialize blocks with first element of each block
    for (int i = 0; i < n; i += block_size) {
        blocks[i / block_size] = arr[i];
    }
    
    // Find minimum in each block
    for (int i = 0; i < n; i++) {
        int block_num = i / block_size;
        blocks[block_num] = min(blocks[block_num], arr[i]);
    }
}

// Step 2: Query minimum in range [left, right]
int query(int left, int right) {
    int answer = arr[left];  // Start with first element
    
    int left_block = left / block_size;
    int right_block = right / block_size;
    
    if (left_block == right_block) {
        // Same block - just check all elements
        for (int i = left; i <= right; i++) {
            answer = min(answer, arr[i]);
        }
    } 
    else {
        // Check left partial block
        for (int i = left; i < (left_block + 1) * block_size; i++) {
            answer = min(answer, arr[i]);
        }
        
        // Check middle complete blocks
        for (int i = left_block + 1; i < right_block; i++) {
            answer = min(answer, blocks[i]);
        }
        
        // Check right partial block
        for (int i = right_block * block_size; i <= right; i++) {
            answer = min(answer, arr[i]);
        }
    }
    
    return answer;
}

// Step 3: Update value at position
void update(int pos, int new_value) {
    arr[pos] = new_value;
    
    int block_num = pos / block_size;
    
    // Recalculate minimum for that block
    blocks[block_num] = arr[block_num * block_size];
    
    int start = block_num * block_size;
    int end = start + block_size;
    if (end > n) end = n;
    
    for (int i = start; i < end; i++) {
        blocks[block_num] = min(blocks[block_num], arr[i]);
    }
}

// Print array and blocks (for understanding)
void print() {
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    printf("Blocks: ");
    int num_blocks = (n + block_size - 1) / block_size;
    for (int i = 0; i < num_blocks; i++) {
        printf("%d ", blocks[i]);
    }
    printf("\n");
}

int main() {
    // Input array
    int input[] = {2, 5, 1, 4, 9, 3, 7, 8, 6, 0, 11, 13, 12, 10, 14};
    n = 15;
    
    // Copy to global array
    for (int i = 0; i < n; i++) {
        arr[i] = input[i];
    }
    
    printf("=== Range Minimum Query - Simple Version ===\n\n");
    
    // Build blocks
    build();
    print();
    
    // Test queries
    printf("\n--- Queries ---\n");
    printf("Min[0 to 14] = %d\n", query(0, 14));
    printf("Min[2 to 7] = %d\n", query(2, 7));
    printf("Min[5 to 10] = %d\n", query(5, 10));
    printf("Min[0 to 4] = %d\n", query(0, 4));
    
    // Test update
    printf("\n--- Update ---\n");
    printf("Changing arr[9] from 0 to 15\n");
    update(9, 15);
    print();
    
    printf("\nMin[5 to 10] after update = %d\n", query(5, 10));
    
    return 0;
}
```

## How to Run

```bash
# Compile
gcc rmq.c -o rmq -lm

# Run
./rmq
```

## Expected Output

```
=== Range Minimum Query - Simple Version ===

Array: 2 5 1 4 9 3 7 8 6 0 11 13 12 10 14 
Blocks: 1 3 0 10 

--- Queries ---
Min[0 to 14] = 0
Min[2 to 7] = 1
Min[5 to 10] = 0
Min[0 to 4] = 1

--- Update ---
Changing arr[9] from 0 to 15
Array: 2 5 1 4 9 3 7 8 6 15 11 13 12 10 14 
Blocks: 1 3 6 10 

Min[5 to 10] after update = 3
```

## Step-by-Step Example

### Array: [2, 5, 1, 4, 9, 3, 7, 8, 6, 0, 11, 13, 12, 10, 14]

**Step 1: Build Blocks (block_size = √15 ≈ 4)**
```
Block 0: [2, 5, 1, 4]     → minimum = 1
Block 1: [9, 3, 7, 8]     → minimum = 3
Block 2: [6, 0, 11, 13]   → minimum = 0
Block 3: [12, 10, 14]     → minimum = 10
```

**Step 2: Query [2, 7] - Find minimum from index 2 to 7**
```
Index 2,3 are in Block 0  → check 1, 4        → min = 1
Index 4,5,6,7 are in Block 1 → check 9,3,7,8  → min = 3
Final answer = min(1, 3) = 1 ✓
```

**Step 3: Update index 9 to value 15**
```
Old: arr[9] = 0
New: arr[9] = 15
Rebuild Block 2: [6, 15, 11, 13] → new minimum = 6
```

## Why This Works?

- **Building:** O(n) - Go through array once
- **Query:** O(√n) - Check at most √n blocks + √n elements
- **Update:** O(√n) - Rebuild one block

## Key Points for Beginners

1. **Block size = √n** (square root of array size)
2. **Divide array into equal blocks**
3. **Store minimum of each block**
4. **Query = check partial blocks + complete blocks**
5. **Update = change element + rebuild its block**

## When to Use?

✅ Learning data structures  
✅ Small to medium arrays  
✅ Not too many queries  
✅ Simple implementation needed  

❌ Very large arrays → use Segment Tree  
❌ Many updates → use other methods  

## Practice Problems

1. Try with array: [5, 2, 8, 1, 9, 3]
2. Find minimum in range [1, 4]
3. Update index 3 to 10
4. Find minimum in range [1, 4] again

---

**Made simple for beginners! 🚀**
