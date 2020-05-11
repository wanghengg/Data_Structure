//
// Created by wangheng on 2020/5/11.
//

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

#include <iostream>

void quickSort(int A[], int begin, int end) {
    if (begin < end) {
        int temp = A[begin];
        int i = begin, j = end;
        while (i < j) {
            while (i < j && A[j] >= temp)
                j--;
            swap(A[i], A[j]);
            while (i < j && A[i] <= temp)
                i++;
            swap(A[i], A[j]);
        }
        quickSort(A, begin, i - 1);
        quickSort(A, i + 1, end);
    }
}

int main() {
    int a[] = {9, 2, 7, 1, 8, 13, -1, 90, 6, 3, 0, 5, 33, 100, 11, 10, 34, 25, 77, 19, 18, 9, 8};
    quickSort(a, 0, sizeof(a)/sizeof(a[0]) - 1);
    for (auto iter : a)
        std::cout << iter << ' ';
    return 0;
}