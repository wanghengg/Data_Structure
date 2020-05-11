/*
 * fibonacci数列迭代实现，时间复杂度为O(n)，空间复杂度为O(1)
 */

#include <iostream>

long long fib(int n) {
    int f = 1, g = 0;   // 定义了f(-1)=1, f(0)=0
    while (0 < n--) {
        g += f;
        f = g - f;
    }
    return g;
}

int main() {
    std::cout << fib(24) << std::endl;

    return 0;
}
