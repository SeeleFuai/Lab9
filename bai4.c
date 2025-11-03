#include <stdio.h>
#include <stdbool.h>

void printArray(int arr[], int size, int step) {
    printf("Bước %d: ", step);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void shakerSort(int arr[], int n) {
    int left = 0, right = n - 1;
    int step = 1;
    bool swapped = true;

    while (swapped) {
        swapped = false;

        // Duyệt từ trái sang phải
        for (int i = left; i < right; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = true;
            }
        } 
        printArray(arr, n, step++);
        right--;

        if (!swapped) break;

        swapped = false;

        // Duyệt từ phải sang trái
        for (int i = right; i > left; i--) {
            if (arr[i] < arr[i - 1]) {
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                swapped = true;
            }
        }
        printArray(arr, n, step++);
        left++;
    }
}

int main() {
    int arr[] = {3, 6, 1, -1, 0, 5, 8, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Mảng ban đầu:\n");
    printArray(arr, n, 0);

    printf("\nQuá trình sắp xếp (Shaker Sort):\n");
    shakerSort(arr, n);

    printf("\nMảng sau khi sắp xếp:\n");
    printArray(arr, n, 0);

    return 0;
}
