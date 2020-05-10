//
// Created by wangheng on 2020/5/10.
//

#include <iostream>

void bubbleSort(int A[], int n);
void swap(int&, int&);

int main() {
    int a[5] = {3, 6, 2, 1, 4};
    bubbleSort(a, sizeof(a) / sizeof(a[0]));
    for (auto iter : a)
        std::cout << iter << ' ';
    return 0;
}

void bubbleSort(int A[], int n) {
    for (bool sorted = false; sorted = !sorted; n--) {
        for (int i = 1; i < n; i++) {
            if (A[i-1] > A[i]) {
                sorted = false;
                swap(A[i-1], A[i]);
            }
        }
    }
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}