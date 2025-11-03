#include <stdio.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

        // In trạng thái mảng sau mỗi bước
        printArray(arr, n);
    }
}

int main() {
    int arr[] = {3, 6, 1, -1, 0, 5, 8, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Mảng ban đầu:\n");
    printArray(arr, n);

    printf("\nQuá trình sắp xếp:\n");
    insertionSort(arr, n);

    printf("\nMảng sau khi sắp xếp:\n");
    printArray(arr, n);

    return 0;
}
