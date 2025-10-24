#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
This program generates all possible letter combinations that a phone number could represent.

Each digit from 2–9 maps to some letters:
2 → abc
3 → def
4 → ghi
5 → jkl
6 → mno
7 → pqrs
8 → tuv
9 → wxyz

For example:
Input:  "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
*/

// Mapping digits 2–9 to their corresponding letters
char* map[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

/*
Custom strdup() function:
The strdup() function is not part of ANSI C but is available in most systems.
It duplicates a string — allocates new memory, copies content, and returns the new pointer.
*/
char* my_strdup(const char* s) {
char* dup = malloc(strlen(s) + 1); // +1 for '\0'
strcpy(dup, s);
return dup;
}

/*
Backtracking function:

digits   → input string like "23"
index    → which digit we are currently processing
current  → partially built string (e.g., "a", "ae", etc.)
result   → array of final strings to store answers
count    → how many combinations we have added so far

Recursion is used because:

* We don't know how many nested loops are needed (depends on digits length)
* Recursion automatically explores all possible letter combinations.
  */
  void backtrack(char* digits, int index, char* current, char** result, int* count) {
  // Base case: if we’ve processed all digits
  if (digits[index] == '\0') {
  // strdup (or my_strdup here) makes a fresh copy of the current string
  // Otherwise all results would point to the same memory (bug!)
  result[*count] = my_strdup(current);
  (*count)++;
  return;
  }

  // Find the letters for the current digit
  char* letters = map[digits[index] - '2'];

  // Try each letter and go deeper
  for (int i = 0; letters[i]; i++) {
  current[index] = letters[i];              // choose one letter
  backtrack(digits, index + 1, current, result, count);  // recurse for next digit
  // No need to "undo" because we overwrite current[index] next loop
  }
  }

/*
Main function that sets up memory, handles empty input,
and calls backtrack() to generate all combinations.
*/
char** letterCombinations(char* digits, int* returnSize) {
int len = strlen(digits);

```
// If input is empty, return nothing
if (len == 0) {
    *returnSize = 0;
    return NULL;
}

// Calculate maximum number of combinations (product of 3 or 4 for each digit)
int max = 1;
for (int i = 0; i < len; i++) {
    char d = digits[i];
    if (d == '7' || d == '9') max *= 4;
    else max *= 3;
}

// Allocate memory for result and current string
char** result = malloc(sizeof(char*) * max);
char* current = calloc(len + 1, sizeof(char)); // +1 for '\0'
int count = 0;

// Start recursion
backtrack(digits, 0, current, result, &count);

*returnSize = count; // total combinations found

// Free temporary buffer
free(current);

return result;
```

}

// Example usage
int main(void) {
char digits[] = "23";
int returnSize;
char** combinations = letterCombinations(digits, &returnSize);

```
printf("Combinations for \"%s\":\n", digits);
for (int i = 0; i < returnSize; i++) {
    printf("%s\n", combinations[i]);
    free(combinations[i]); // free each strdup-ed string
}
free(combinations); // free main array

return 0;
```

}
