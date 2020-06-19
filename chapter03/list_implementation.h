//
// Created by wangheng on 2020/5/18.
//

#ifndef DATA_STRUCTURE_LIST_IMPLEMENTATION_H
#define DATA_STRUCTURE_LIST_IMPLEMENTATION_H

#include "list.h"
#include "../chapter02/swap.h"
#include <random>
#include <iostream>

template<typename T>
void List<T>::init() {
    header = new ListNode<T>;
    trailer = new ListNode<T>;
    header->succ = trailer;
    header->pred = nullptr;
    trailer->pred = header;
    trailer->succ = nullptr;
    _size = 0;
}

template<typename T>
int List<T>::clear() {
    int oldSize = _size;
    while (0 < _size)
        remove(header->succ);
    return oldSize;
}

template<typename T>
void List<T>::copyNodes(ListNode<T> *p, int n) {
    init();
    while (n--) {
        insertAsEnd(p->data);
        p = p->succ;
    }
}

template<typename T>
void List<T>::merge(ListNode<T> *&p, int n, List<T> &L, ListNode<T> *q, int m) {
    ListNode<T>* pp = p->pred;
    while (0 < m) {
        if ( (0 < n) && (p->data <= q->data) ) {
            if (q == (p = p->succ))
                break;
            n--;
        } else {
            insertBefore(p, L.remove((q = q->succ)->pred));
            m--;
        }
    }
    p = pp->succ;
}

template<typename T>
void List<T>::mergeSort(ListNode<T> *&p, int n) {
    std::cout << "mergeSort()" << std::endl;
    if (n < 2) return;
    int m = n >> 1;
    ListNode<T>* q = p;
    for (int i = 0; i < m; i++)
        q = q->succ;
    mergeSort(p, m);
    mergeSort(q, n - m);
    merge(p, m, *this, q, n - m);
}

template<typename T>
void List<T>::selectionSort(ListNode<T> *p, int n) {
    std::cout << "selectionSort()" << std::endl;
    ListNode<T>* head = p->pred;
    ListNode<T>* tail = p;
    for (int i = 0; i < n; ++i)
        tail = tail->succ;
    while (0 < --n) {
        // 这里必须使用head->succ,不能直接使用p，因为p作为第一个元素可能被remove。
        ListNode<T>* max = selectMax(head->succ, n + 1);
//        insertBefore(tail, remove(max));
//        tail = tail->pred;
        // 交换max节点和tail节点的data，不使用remove和insertBefore，提高效率
        // 因为insertBefore和remove需要动态分配内存，相对消耗时间
        swap(max->data, (tail = tail->pred)->data);
    }
}

template<typename T>
void List<T>::insertionSort(ListNode<T> *p, int n) {
    std::cout << "insertionSort()" << std::endl;
    for (int r = 0; r < n; ++r) {
        insertAfter(search(p->data, r, p), p->data);
        p = p->succ;
        remove(p->pred);
    }
}

template<typename T>
List<T>::List(List<T> const &L) {
    copyNodes(L.first(), L._size);
}

template<typename T>
List<T>::List(List<T> const &L, Rank r, Rank n) {
    ListNode<T>* p = L.first();
    while (0 < r--)
        p = p->succ;
    copyNodes(p, n);
}

template<typename T>
List<T>::List(ListNode<T> *p, int n) {
    copyNodes(p, n);
}

template<typename T>
List<T>::~List() {
    clear();
    delete header;
    delete trailer;
    header = nullptr;
    trailer = nullptr;
}

template<typename T>
T& List<T>::operator[](Rank r) const {
    ListNode<T>* p = first();
    while (0 < r--)
        p = p->succ;
    return p->data;
}

template<typename T>
ListNode<T> * List<T>::find(const T &e, int n, ListNode<T> *p) const {
    while (0 < n--) {
        if ( e == (p = p->pred)->data)
            return p;
    }
    return nullptr;
}

template<typename T>
ListNode<T>* List<T>::search(const T &e, int n, ListNode<T> *p) const {
    while (-1 < n--) {  // 对于p的n个前驱，从右向左逐个比较
        if (((p = p->pred)->data) <= e) // 直至命中，或者越界
            break;
    }
    return p;   // 查找失败返回区间左边界的前驱
}

template<typename T>
ListNode<T>* List<T>::selectMax(ListNode<T> *p, int n) {
    ListNode<T>* max = p;
    while (0 < --n)
        max = (((p = p->succ)->data) >= max->data) ? p : max;
    return max;
}

template<typename T>
ListNode<T>* List<T>::insertAsFirst(const T &e) {
    _size++;
    return header->insertAsSucc(e);
}

template<typename T>
ListNode<T>* List<T>::insertAsEnd(const T &e) {
    _size++;
    return trailer->insertAsPred(e);
}

template<typename T>
ListNode<T>* List<T>::insertBefore(ListNode<T> *p, const T &e) {
    _size++;
    return p->insertAsPred(e);
}

template<typename T>
ListNode<T>* List<T>::insertAfter(ListNode<T> *p, const T &e) {
    _size++;
    return p->insertAsSucc(e);
}

template<typename T>
T List<T>::remove(ListNode<T> *p) {
    T e = p->data;
    p->pred->succ = p->succ;
    p->succ->pred = p->pred;
    delete p;
    p = nullptr;
    _size--;
    return e;
}

template<typename T>
void List<T>::sort(ListNode<T> *p, int n) {
    std::uniform_int_distribution<unsigned int> dis(0,2);
    std::random_device rd;
    switch (dis(rd) % 3) {
        case 1:
            insertionSort(p, n);
            break;
        case 2:
            selectionSort(p, n);
            break;
        default:
            mergeSort(p, n);
    }
}

// 无序列表唯一化
template<typename T>
int List<T>::deduplicate() {
    if (2 > _size) return 0;
    int oldSize = _size;
    ListNode<T>* p = first();
    Rank r = 1;
    while (trailer != (p = p->succ)) {
        ListNode<T>* q = find(p->data, r, p);
        q ? remove(q) : r++;
    }
    return oldSize - _size;
}

// 有序列表唯一化
template<typename T>
int List<T>::uniquify() {
    if ( _size < 2 ) return 0;
    int oldSize = _size;
    ListNode<T>* p = first();
    ListNode<T>* q;
    while ((q = p->succ) != trailer) {
        if (p->data == q->data)
            remove(q);
        else
            p = q;
    }
    return oldSize - _size;
}

template<typename T>
void List<T>::reverse() {
    ListNode<T>* p = header;
    ListNode<T>* q = trailer;
    // 直接交换数据项
    for (int i = 1; i < _size; i += 2)
        swap((p = p->succ)->data, (q = q->pred)->data);
}

// 使用函数指针对列表进行遍历操作
template<typename T>
void List<T>::traverse(void (*visit)(T &)) {
    for (ListNode<T>* p = header->succ; p != trailer; p = p->succ)
        visit(p->data);
}

// 使用函数对象对列表进行遍历操作，实用性更强
template<typename T>
template<typename VST>
void List<T>::traverse(VST &visit) {
    for (ListNode<T>* p = header->succ; p != trailer; p = p->succ)
        visit(p->data);
}

template<typename T>
void List<T>::print() const {
    ListNode<T>* iter = header;
    for (int i = 0; i < _size; i++)
        std::cout << (iter = iter->succ)->data << ' ';
    std::cout << std::endl;
}

#endif //DATA_STRUCTURE_LIST_IMPLEMENTATION_H
