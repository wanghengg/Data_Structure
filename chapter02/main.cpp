//
// Created by wangheng on 2020/5/16.
//

#include "Vector.h"
#include "Vector.cpp"
#include <iostream>

int main() {
    int a[] = {3,1,2,9,5,3,9,1,0,8,9,1,7,34,434,21,34,5,99};
    int length = sizeof(a)/sizeof(a[0]);
    Vector<int> vec(a, length);
    vec.mergeSort(1, 9);
    for (int i = 0; i < length; i++)
        std::cout << vec[i] << std::endl;

    return 0;
}