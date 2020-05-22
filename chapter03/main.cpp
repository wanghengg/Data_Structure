//
// Created by wangheng on 2020/5/18.
//

#include <iostream>
#include "list.h"

template<typename T>
struct Increase {
    virtual void operator()(T &e) { e++; }
};

int main() {
    List<int> list;
    list.insertAsEnd(4);
    list.insertAsFirst(12);
    list.insertAsFirst(9);
    list.insertAsEnd(3);
    list.insertAsEnd(2);
    list.insertAsFirst(7);
    list.print();
    ListNode<int>* p = list.first();
    list.sort();
    list.print();
    Increase<int> increase;
    list.traverse(increase);
    list.print();
    list.reverse();
    list.print();

    return 0;
}