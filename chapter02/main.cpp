//
// Created by wangheng on 2020/5/16.
//

#include <iostream>
#include "bitMap.h"

int main() {
    BitMap bitmap;
    bitmap.set(79999);
    std::cout << std::boolalpha << bitmap.get(79999) << std::endl;
    bitmap.set(3);
    std::cout << bitmap.get(3) << std::endl;

    return 0;
}