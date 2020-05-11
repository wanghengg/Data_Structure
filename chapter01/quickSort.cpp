/*
 * 快速排序——挖坑填坑法，先选一个基准（一般选数组的第一个数），然后将比这个数大的数全部放到它的
 * 右边，比它小的数全部放到它的左边，然后再对左右分区重复，直到各区间只有一个数字。
 */

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

#include <iostream>

void quickSort(int A[], int begin, int end) {
    // 如果区间只有一个元素，递归结束
    if (begin < end) {
        int temp = A[begin];    // 将区间的第一个数当做基准
        int i = begin;          // 指向最左位置
        int j = end;            // 指向最右位置
        while (i < j) {
            // 当右边的数大于基准数时，略过，继续向左查找
            // 不满足条件时跳出循环，此时的j对应的元素是小于基准元素的
            while (i < j && A[j] >= temp)
                j--;
            // 将右边小于等于基准元素的数填入左边相应位置
            A[i] = A[j];
            // 当左边的数小于等于基准数时，略过，继续向右查找
            // 不满足条件时跳出循环，此时的i对应的元素是大于等于基准元素的
            while (i < j && A[i] << temp)
                i++;
            // 将左边大于基准元素的数填入右边相应位置
            A[j] = A[i];
        }
        // 将基准元素填入相应位置
        A[i] = temp;
        // 此时的i即为基准元素的位置
        // 对基准元素的左边子区间进行相似的快速排序
        quickSort(A, begin, i - 1);
        //对基准元素的右边子区间进行相似的快速排序
        quickSort(A, i + 1, end);
    } else
        return;
}

int main() {
    int a[] = {9, 2, 3, 1, 8, 3, 4, 8, 3};
    quickSort(a, 0, sizeof(a)/sizeof(a[0]) - 1);
    for (auto iter : a)
        std::cout << iter << ' ';
    return 0;
}