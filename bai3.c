#include <stdio.h>

// Hàm in trạng thái mảng
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Hàm tìm vị trí chèn bằng tìm kiếm nhị phân
int binarySearch(int arr[], int item, int low, int high) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (item == arr[mid])
            return mid + 1;
        else if (item > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

// Thuật toán chèn nhị phân
void binaryInsertionSort(int arr[], int n) {
    int i, j, key, loc;
    for (i = 1; i < n; i++) {
        key = arr[i];
        loc = binarySearch(arr, key, 0, i - 1);

        // Dịch chuyển phần tử để chèn key vào đúng vị trí
        for (j = i - 1; j >= loc; j--)
            arr[j + 1] = arr[j];

        arr[loc] = key;

        // In trạng thái mảng sau mỗi bước
        printArray(arr, n);
    }
}

int main() {
    int arr[] = {3, 6, 1, -1, 0, 5, 8, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Mảng ban đầu:\n");
    printArray(arr, n);

    printf("\nQuá trình sắp xếp (Chèn nhị phân):\n");
    binaryInsertionSort(arr, n);

    printf("\nMảng sau khi sắp xếp:\n");
    printArray(arr, n);

    return 0;
}
