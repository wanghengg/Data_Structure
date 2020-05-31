//
// Created by wangheng on 2020/5/10.
//

// 归并排序
#include <iostream>

// 将有序数组合并
void merge_sort_core(int arr[], int begin, int mid, int end) {
    int i = begin, j = mid, k = 0;
    int* temp = new int[end-begin];

    for (; i < mid && j < end; temp[k++] = (arr[i]<arr[j]?arr[i++]:arr[j++]));
    for (; i < mid; temp[k++]=arr[i++]);
    for (; j < end; temp[k++]=arr[j++]);
    for (i = begin, k = 0; i < end; arr[i++]=temp[k++]);

    free(temp);
}

void merge_sort(int arr[], int begin, int end) {
    if (end - begin < 2)
        return;
    int mid = (begin + end) >> 1;   // 计算中点
    merge_sort(arr, begin, mid);    // 二分递归排序
    merge_sort(arr, mid, end);
    merge_sort_core(arr, begin, mid, end);  // 将排好序的数组合并
}

int main() {
    int a[] = {45, 32, 33, 23, 16, 2, 38, 7};
    merge_sort(a, 0, sizeof(a) / sizeof(a[0]));
    for (auto iter : a)
        std::cout << iter << ' ';

    return 0;
}