//
// Created by wangheng on 2020/5/16.
//

#ifndef DATA_STRUCTURE_BINSEARCH_H
#define DATA_STRUCTURE_BINSEARCH_H

#include "Vector.h"

template<typename T>
Rank binSearch(T* S, const T& e, Rank lo, Rank hi) {
    while (lo < hi) {
        Rank mi = (lo + hi) >> 1;
        (e < S[mi]) ? hi = mi : lo = mi + 1;
    }
    return --lo;
}

#endif //DATA_STRUCTURE_BINSEARCH_H
