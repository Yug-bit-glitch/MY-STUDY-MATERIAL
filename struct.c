typedef struct person {
    char name[100];
    int height;
} Point;

// Merge function
void merge(Point arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Point arr1[n1], arr2[n2];

    for (int i = 0; i < n1; i++) arr1[i] = arr[left + i];
    for (int j = 0; j < n2; j++) arr2[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    // Sort by height in DESCENDING order
    while (i < n1 && j < n2) {
        if (arr1[i].height >= arr2[j].height)
            arr[k++] = arr1[i++];
        else
            arr[k++] = arr2[j++];
    }

    while (i < n1) arr[k++] = arr1[i++];
    while (j < n2) arr[k++] = arr2[j++];
}

// Merge sort function
void mergesort(Point arr[], int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergesort(arr, left, mid);
    mergesort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// Main function (LeetCode style)
char** sortPeople(char** names, int namesSize, int* heights, int heightsSize, int* returnSize) {
    Point people[namesSize];

    for (int i = 0; i < namesSize; i++) {
        strcpy(people[i].name, names[i]);
        people[i].height = heights[i];
    }

    mergesort(people, 0, namesSize - 1);

    char** result = (char**)malloc(namesSize * sizeof(char*));
    for (int i = 0; i < namesSize; i++) {
        result[i] = (char*)malloc(100 * sizeof(char));
        strcpy(result[i], people[i].name);
    }

    *returnSize = namesSize;
    return result;
}
