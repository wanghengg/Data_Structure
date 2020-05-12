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