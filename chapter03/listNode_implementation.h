//
// Created by wangheng on 2020/5/18.
//

#ifndef DATA_STRUCTURE_LISTNODE_IMPLEMENTATION_H
#define DATA_STRUCTURE_LISTNODE_IMPLEMENTATION_H

#include "listNode.h"

template<typename T>
ListNode<T> * ListNode<T>::insertAsPred(const T &e) {
    ListNode<T> *x = new ListNode<T>(e, pred, this);
    pred->succ = x;
    pred = x;
    return x;
}

template<typename T>
ListNode<T> * ListNode<T>::insertAsSucc(const T &e) {
    ListNode<T> *x = new ListNode<T>(e, this, succ);
    succ->pred = x;
    succ = x;
    return x;
}

#endif //DATA_STRUCTURE_LISTNODE_IMPLEMENTATION_H
