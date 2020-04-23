# 目录

[查找数组中最大两个值的索引](#查找数组中最大两个值的索引)



## 级数

* $$1 + \frac{1}{2} + \frac{1}{3} + ... + \frac{1}{n} = O(\log{n})$$
* $$\log{1} + log{2} + \log{3} + ... + \log{n} = O(n \log{n})$$

## 查找数组中最大两个值的索引

```c++
#include <iostream>

void swap(int& a, int& b) {
    int c = a;
    a = b;
    b = c;
}

void max2(int A[], int lo, int hi, int& x1, int& x2) {
    // 最终还剩2个元素
    if (lo + 2 == hi) {
        if (A[x1 = lo] < A[x2 = lo + 1]) {
            swap(x1, x2);
        }
        return; // 必须return使递归结束
    }

    // 最终还剩3个元素
    if (lo + 3 == hi) {
        if (A[x1 = lo] < A[x2 = lo + 1]) {
            swap(x1, x2);
        }
        if (A[lo + 2] > A[x2]) {
            if (A[x2 = lo + 2] > A[x1]) {
                swap(x1, x2);
            }
        }
        return;
    }

    int mid = (lo + hi) / 2;
    int x1L, x2L;
    max2(A, lo, mid, x1L, x2L);
    int x1R, x2R;
    max2(A, mid, hi, x1R, x2R);
    if (A[x1L] > A[x1R]) {
        x1 = x1L, x2 = (A[x2L] > A[x1R]) ? x2L : x1R;
    } else {
        x1 = x1R, x2 = (A[x2R] > A[x1L]) ? x2R : x1L;
    }
}

int main()
{
    int A[] = {1,5,6,4,11,3,8,9,10};
    int x1, x2;
    max2(A, 0, sizeof(A)/sizeof(A[0]), x1, x2);
    std::cout << x1 << '\t' << x2 << std::endl;

    return 0;
}
```

