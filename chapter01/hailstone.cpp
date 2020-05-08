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