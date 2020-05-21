//
// Created by wangheng on 2020/5/18.
//

#ifndef DATA_STRUCTURE_LIST_IMPLEMENTATION_H
#define DATA_STRUCTURE_LIST_IMPLEMENTATION_H

#include "list.h"

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
ListNode<T>* List<T>::selectMax(ListNode<T> *p, int n) {
    T max = p->data;
    while (0 < --n)
        max = ((p = p->succ)->data > max) ? p->data : max;
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

}

#endif //DATA_STRUCTURE_LIST_IMPLEMENTATION_H
