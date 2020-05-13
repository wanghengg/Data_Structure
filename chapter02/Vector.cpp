//
// Created by wangheng on 2020/5/13.
//

#include "vector.h"

template<typename T>
Rank Vector<T>::max(Rank lo, Rank hi) {
    return lo > hi ? lo : hi;
}

template<typename T>
void Vector<T>::expand() {
    if (_size < _capacity) return;
    _capacity = max(_capacity, DEFAULT_CAPACITY);
    T* oldElem = _elem;
    _elem = new T[_capacity <<= 1];  // 容量加倍
    for (int i = 0; i < _size; i++)
        _elem[i] = oldElem[i];
    delete [] oldElem;
}

template<typename T>
void Vector<T>::shrink() {
    if (_capacity < DEFAULT_CAPACITY << 1) return;
    if (_size << 2 > _capacity) return;
    T* oldElem = _elem;
    _elem = new T[_capacity >>= 1]; // 容量减半
    for (int i = 0; i < _size; i++)
        _elem[i] = oldElem[i];
    delete [] oldElem;
}

template<typename T>
T& Vector<T>::operator[](Rank r) const {
    return _elem[r];
}

template<typename T>
Rank Vector<T>::insert(Rank r, const T &e) {
    expand();
    for (int i = _size; i > r; i--)
        _elem[i] = _elem[i-1];
    _elem[r] = e;   // 插入新的值
    _size++;    // 更新容量
    return r;
}

template<typename T>
int Vector<T>::remove(Rank lo, Rank hi) {
    if (lo == hi) return 0;
    while (hi < _size)
        _elem[lo++] = _elem[hi++];
    _size = lo;
    shrink();
    return hi - lo;
}

template<typename T>
T Vector<T>::remove(Rank r) {
    T elem = _elem[r];
    remove(r, r + 1);
    return elem;    // 返回被删除的元素
}

template<typename T>
Rank Vector<T>::find(const T &e, Rank lo, Rank hi) const {
    while ((lo < hi--) && (e != _elem[hi])) // 逆向查找
        return hi;  // hi < lo 意味着失败，否则hi即命中元素的秩
}

template<typename T>
int Vector<T>::depulicate() {
    int oldSize = _size;
    Rank i = 1;
    while (i < _size) {
        if (find(_elem[i], 0, i) < 0)
            i++;
        else remove(i);
    }

    return oldSize - _size;
}