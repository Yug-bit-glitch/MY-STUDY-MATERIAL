#include <stdio.h>
#include <stdlib.h>

// Define structure for a single node
typedef struct Node {
    int data;           // Stores the actual value
    struct Node* next;  // Pointer to the next node (self-referential structure)
} Node;
