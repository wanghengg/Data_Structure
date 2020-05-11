/*
 * 选择排序：每次循环找出最小（大）值的索引，然后将其放在未排序数组的第一位
 */

#include <iostream>

void selectionSort(int A[], int length) {
    int minIndex = 0, temp;
    for (int i = 0; i < length - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < length; j++) {
            if (A[j] < A[minIndex])
                minIndex = j;
        }
        temp = A[i];
        A[i] = A[minIndex];
        A[minIndex] = temp;
    }
}

int main() {
    int a[] = {9, 2, 7, 1, 8, 13, 90, 6, 3, 0, 5, 33, 100, 11, 10, 34, 25, 77, 19, 18, 9, 8};
    selectionSort(a, sizeof(a)/sizeof(a[0]));
    for (auto iter : a)
        std::cout << iter << ' ';
    return 0;
}