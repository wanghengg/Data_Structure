/*
 * 递归方法实现fibonacci数列，时间复杂度是O(n^2),空间复杂度是O(n)
 */

#include <iostream>

long long fib(int n) {
    return (2 > n) ? n : fib(n - 1) + fib(n - 2);
}

int main() {
    std::cout << fib(2) << std::endl;
}