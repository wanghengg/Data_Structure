/*
 * 递归实现最长公共子序列，时间复杂度最坏O(n^2)，最好O(n)
 */

#include <iostream>
#include <cstring>

int LCS(const char *str1, const char *str2, int l1, int l2) {
    if (l1 >= 0 && l2 >= 0) {
        if (str1[l1] == str2[l2])   // 减而治之
            return LCS(str1, str2, l1-1, l2-1) + 1;
        else    // 分而治之
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