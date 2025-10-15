#include <stdio.h>

long long merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    long long inv = 0;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
            inv += (n1 - i); // count inversions here
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    return inv;
}

long long mergeSort(int arr[], int left, int right) {
    long long inv = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        inv += mergeSort(arr, left, mid);
        inv += mergeSort(arr, mid + 1, right);
        inv += merge(arr, left, mid, right);
    }
    return inv;
}

int main() {
    int d;
    scanf("%d", &d);

    for (int t = 0; t < d; t++) {
        int n;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        long long inversion = mergeSort(arr, 0, n - 1);
        printf("%lld\n", inversion);
    }
    return 0;
}

