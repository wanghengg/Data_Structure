//
// Created by wangheng on 2020/5/11.
//

#include <iostream>

void insertionSort(int A[], int length) {
    int preIndex, current;
    // i表示已排序个数
    for (int i = 1; i < length; i++) {
        preIndex = i - 1;
        // 保存未排序部分的第一个元素值
        current = A[i];
        while (preIndex >= 0 && A[preIndex] > current) {
            A[preIndex + 1] = A[preIndex];
            preIndex--;
        }
        A[preIndex + 1] = current;
    }
}

int main() {
    int a[] = {9, 2, 7, 1, 8, 13, 90, 6, 3, 0, 5, 33, 100, 11, 10, 34, 25, 77, 19, 18, 9, 8};
    insertionSort(a, sizeof(a)/sizeof(a[0]));
    for (auto iter : a)
        std::cout << iter << ' ';
    return 0;
}