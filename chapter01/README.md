# 计算

## 算法

* **算法的性质**

  正确性：的确可以解决指定的问题

  确定性：任一算法都可以描述为一个由基本操作组成的序列

  可行性：每一基本操作都可实现，且在常数时间内完成

  有穷性：对于任何输入，经过有穷次基本操作，都可以得到输出。

* **判断一个算法是不是好算法的条件**：**正确、健壮、可读、效率**

## 有穷性

`Hailstone`序列，计算`Hailstone`序列的长度：

```c++
//
// Created by wangheng on 2020/5/9.
//

#include <iostream>

// 计算hailstone序列的长度
int hailstone(int n) {
    int length = 1;
    while (1 < n) {
        (n % 2) ? n = 3 * n + 1 : n /= 2;
        length++;
    }
    return length;
}
int main() {
    int number;
    std::cin >> number;
    std::cout << hailstone(number) << std::endl;
    return 0;
}
```

# 计算模型

## 问题规模

* 令T(n) = 用算法A求解某一问题规模为n的实例，所需的计算成本。在规模同为n的所有实例中，只关注最坏的情况。
* T(n)=算法输入规模为n的问题，所需要执行的基本操作次数。

## 图灵机

* 无限长纸带
* 有限种状态
* 字符的种类有限
* 读写头总是对准一个单元格

# 算法分析

## 级数

* $$1 + \frac{1}{2} + \frac{1}{3} + ... + \frac{1}{n} = O(\log{n})$$

* $$\log{1} + log{2} + \log{3} + ... + \log{n} = O(n \log{n})$$

* $$1 + 2 + ... + n = O(n^2)$$

* $$1^2 + 2^2 + ... + n^2 = O(n^3)$$

* $$1^3 + 2^3 + ... + n^3 = O(n^4)$$

  幂方级数：比幂次高一阶

* $$a^0 + a^1 + a^2 + ... + a^n = O(a^n)$$

* 收敛级数的复杂度是$$O(1)$$

## 冒泡排序

```c++
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
```



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

