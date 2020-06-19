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

## 快速排序

### 实现1

```c++
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
```

### 实现2

```c++
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
    int a[] = {9, 2, 7, 1, 8, 13, 90, 6, 3, 0, 5, 33, 100, 11, 10, 34, 25, 77, 19, 18, 9, 8};
    quickSort(a, 0, sizeof(a)/sizeof(a[0]) - 1);
    for (auto iter : a)
        std::cout << iter << ' ';
    return 0;
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

## 选择排序

```c++
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
```

## 插入排序

```c++
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

## `fibonacci`数列

`fibonacci`递归版

```c++
int fib(int n) {
    return (2 > n) ? n : fib(n - 1) + fib(n - 2);
}
```

算法的时间复杂度为$O(n^2)$，复杂度过高

**颠倒计算方向：由自顶向下递归，为自底向上迭代**

`fibonacci`迭代版

```c++
long long fib(long long n) {
    long long f = 1, g = 0;	// 初始化定义fib(-1), fib(0)
    while (0 < n--) {	// 根据原始定义，通过n次加法和减法计算fib(n)
        g += f;		// 计算最新一项
        f = g - f;	// 更新前一项为原来的g
    }
    return g;
}
```

## 最长公共子序列

```c++
// 递归实现，时间复杂度O(n^2)
#include <iostream>
#include <cstring>

int LCS(const char *str1, const char *str2, int l1, int l2) {
    if (l1 >= 0 && l2 >= 0) {
        if (str1[l1] == str2[l2])	// 减而治之
            return LCS(str1, str2, l1-1, l2-1) + 1;
        else	// 分而治之
            return LCS(str1, str2, l1, l2 - 1) > LCS(str1, str2, l1 - 1, l2) ?
                LCS(str1, str2, l1, l2 - 1) : LCS(str1, str2, l1 - 1, l2);
    } else
        return 0;
}

int main() {
    const char *str1 = "program";
    const char *str2 = "algorithm";
    std::cout << LCS(str1, str2, std::strlen(str1) - 1, std::strlen(str2) - 1);

    return 0;
}
```

递归实现，时间复杂度$$O(n^2)$$

```c++
/*
 * 最长公共子序列(LCS)迭代，时间复杂度为O(m*n),m、n分别是两个字符串的长度
 */

#include <iostream>
#include <cstring>

int LCS(const char *str1, const char *str2) {
    int l1 = std::strlen(str1);
    int l2 = std::strlen(str2);

    int map[l1+1][l2+1];
    for (int i = 0; i <= l1; i++)
        map[i][0] = 0;
    for (int j = 0; j <= l2; j++)
        map[0][j] = 0;
    for (int row = 1; row <= l1; row++) {
        for (int column = 1; column <= l2; column++) {
            if (str1[row-1] == str2[column-1])
                map[row][column] = map[row-1][column-1]+1;
            else
                map[row][column] = (map[row][column-1] > map[row-1][column] ?
                                    map[row][column-1] : map[row-1][column]);
        }
    }
    return map[l1][l2];
}

int main() {
    const char *str1 = "university";
    const char *str2 = "algorithm";
    std::cout << LCS(str1, str2);

    return 0;
}
```



# 课后习题

## 1-2

![image-20200616080749983](https://gitee.com/wanghengg/picture/raw/master/2020/image-20200616080749983.png)

海岛高度$H = d * h / (d_1 - d_2) + h$

海岛距离$D = d * d_2 / (d_1 - d_2)$

```c++
float islandHeight(float d1, float d2, float d, float h) {
    float pha = d1 - d2;
    float shi = d * h;
    return shi / pha + h;
}
```

```c++
float islandDistance(float d1, float d2, float d) {
    float shi = d2 * d;
    float pha = d1 - d2;
    return shi / pha;
}
```

## 1-3

(a) 所有元素已经有序

(b) ![image-20200616090255255](https://gitee.com/wanghengg/picture/raw/master/2020/image-20200616090255255.png)

(c) ![image-20200616090626876](https://gitee.com/wanghengg/picture/raw/master/2020/image-20200616090626876.png)

(d) 所有元素处于完全逆序的状态

## 1-4

不能。对n个整数进行排序，至少要对每个元素访问一次，所以时间复杂度不可能低于$O(n)$

## 1-6

输入规模按$n = 10^9$人口计算，计算量为$n^2 = 10^{18}$

该电脑的计算能力按$10^9$计，则大致需要$10^{18-9}=10^9$秒 = 30年

## 1-7

