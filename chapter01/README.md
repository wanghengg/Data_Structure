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

## 归并排序(merge_sort)

```c++
/*
 * title: 归并排序(merge_sort)
 */
#include <iostream>
#include <cstdlib>

// 将有序数组合并
void merge_sort_core(int arr[], int begin, int mid, int end) {
    int i = begin, j = mid, k = 0;
    int* temp = (int*)std::malloc(sizeof(int) * (end - begin));

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
    merge_sort(a, 0, sizeof(a)/sizeof(a[0]));
    for (auto iter : a)
        std::cout << iter << ' ';

    return 0;
}
```

# 迭代与递归

## 减而治之

> 为求解一个大规模的问题，可以：
>
> 将其划分为两个子问题，其一**平凡**，另一**规模缩减**				// 单调性
>
> 分别求解子问题
>
> 由子问题的解，得到原问题的解

```c++
// 递归求和
#include <iostream>

int sum(int A[], int n) {
    return (n < 1) ? 0 : sum(A, n-1) + A[n-1];
}

int main() {
    int a[] = {1,3,4,5};
    std::cout << sum(a, sizeof(a)/sizeof(a[0]));
    return 0;
}
```



**求解递归复杂度的两种方法：递归跟踪、递归方程。**

* 递归跟踪（适用于简单递归模式）：

  检查每个递归实例，累计所需时间就是算法执行时间。

* 递归方程（适用于复杂递归模式）：

## 分而治之

> 为求解一个大规模的问题，可以：
>
> 将其划分为若干（通常两个）子问题，规模大体**相当**
>
> 分别求解子问题
>
> 由子问题的解，得到原问题的解

**二分递归求和：**

```c++
#include <iostream>

int sum(int A[], int lo, int hi) {
    if (lo == hi) return A[lo];
    int mid = (lo + hi) >> 1;
    return sum(A, lo, mid) + sum(A, mid + 1, hi);
}

int main() {
    int a[] = {1, 3, 7, 3};
    std::cout << sum(a, 0, sizeof(a)/sizeof(a[0]) - 1);

    return 0;
}
```



## 查找数组中最大两个值的索引

```c++
// 计算数组[a,b)中最大和次大的数的索引
// x1表示最大值索引，x2表示次大值索引
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

# 动态规划



## 动态规划

## 递归方程

## 递归跟踪

## 迭代

