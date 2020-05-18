//
// Created by wangheng on 2020/5/18.
//

#ifndef DATA_STRUCTURE_LISTNODE_H
#define DATA_STRUCTURE_LISTNODE_H

typedef int Rank ;

template<typename T> struct ListNode {
    T data;
    ListNode<T>* pred;
    ListNode<T>* succ;

    ListNode() {}   // 针对header和trailer的构造
    ListNode(T e, ListNode<T>* p = nullptr, ListNode<T>* s = nullptr)
        : data(e), pred(p), succ(s) {}  // 默认构造器

    // 操作接口
    ListNode<T>* insertAsPred(T const &e);
    ListNode<T>* insertAsSucc(T const &e);
};

#include "listNode_implementation.h"

#endif //DATA_STRUCTURE_LISTNODE_H
