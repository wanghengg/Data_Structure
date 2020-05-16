//
// Created by wangheng on 2020/5/16.
//

#ifndef DATA_STRUCTURE_SWAP_H
#define DATA_STRUCTURE_SWAP_H

template<typename T>
void swap(const T& a, const T& b) {
    T c = a;
    a = b;
    b = c;
}

#endif //DATA_STRUCTURE_SWAP_H
