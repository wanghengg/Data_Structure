//
// Created by wangheng on 2020/5/16.
//

#ifndef DATA_STRUCTURE_FIBSEARCH_H
#define DATA_STRUCTURE_FIBSEARCH_H

#include "../chapter01/Fib.h"
#include "Vector.h"

template<typename T>
Rank fibSearch(T* S, const T& e, Rank lo, Rank hi) {
    for (Fib fib(hi - lo); lo < hi; ) {
        while (hi - lo < fib.get())
            fib.prev();
        Rank mi = lo + fib.get() - 1;
        if (e < S[mi])
            hi = mi;
        else if(S[mi] < e)
            lo = mi + 1;
        else
            return mi;
    }
    return -1;
}

#endif //DATA_STRUCTURE_FIBSEARCH_H
