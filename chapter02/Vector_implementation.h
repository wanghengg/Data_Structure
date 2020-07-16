#include "swap.h"
#include "binSearch.h"
#include "fibSearch.h"
#include <cstdlib>

template<typename T>
void Vector<T>::copyFrom(const T* A, Rank lo, Rank hi) {
    _elem = new T[_capacity = 2 * (hi - lo)];
    _size = 0;
    while (lo < hi)
        _elem[_size++] = A[lo++];
}

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
void Vector<T>::merge(Rank lo, Rank mi, Rank hi) {
    T* S = new T[hi - lo];
    int i = lo, j = mi;
    int k = 0;
    for (; i < mi && j < hi;)
        S[k++] = (_elem[i] < _elem[j]) ? _elem[i++] : _elem[j++];
    for (; i < mi;)
        S[k++] = _elem[i++];
    for (; j < hi;)
        S[k++] = _elem[j++];
    for (int m = 0; m < hi - lo; m++)
        _elem[lo + m] = S[m];
    delete [] S;
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
Rank Vector<T>::find(const T &e) const {
    return find(e, 0, _size);
}

template<typename T>
int Vector<T>::deduplicate() {
    int oldSize = _size;
    Rank i = 1;
    while (i < _size) {
        if (find(_elem[i], 0, i) < 0)
            i++;
        else remove(i);
    }
    return oldSize - _size;
}

// 遍历向量
template<typename T>
void Vector<T>::traverse(void (*visit)(T &)) {
    for (int i = 0; i < _size; i++)
        visit(_elem[i]);
}

template<typename T>
int Vector<T>::disordered() const {
    int n = 0;
    for (int i = 1; i < _size; i++)
        n += (_elem[i-1] > _elem[i]);
    return n;
}

template<typename T>
int Vector<T>::uniquify() {
    int i = 0, j = 0;
    while (++j < _size) {
        if (_elem[i] != _elem[j])
            _elem[++i] = _elem[j];
    }
    _size = ++i;
    shrink();
    return j - i;
}

template<typename T>
void Vector<T>::unsort(Rank lo, Rank hi) {
    T* V = _elem + lo;
    for (Rank i = hi - lo; i > 0; i--)
        swap(V[i-1], V[std::rand() / i]);
}

template<typename T>
Rank Vector<T>::search(const T &e, Rank lo, Rank hi) const {
    return (rand() % 2) ? binSearch(_elem, e, lo, hi) : fibSearch(_elem, e, lo, hi);
}

template<typename T>
void Vector<T>::bubbleSort(Rank lo, Rank hi) {  // 起泡排序是稳定的
    Rank last = lo; // 记录最后一次交换逆序对的位置
    // 后面是顺序的，所以直接跳转到last位置，后面不用扫描
    for(bool sorted = false; sorted = !sorted; hi = last) {
        for (int i = lo + 1; i < hi; i++) {
            if (_elem[i] < _elem[i - 1]) {
                swap(_elem[i], _elem[i - 1]);
                last = i;
                sorted = false;
            }
        }
    }
}

template<typename T>
void Vector<T>::mergeSort(Rank lo, Rank hi) {
    if (hi - lo < 2) return;
    Rank mi = (lo + hi) >> 1;
    mergeSort(lo, mi);
    mergeSort(mi, hi);
    merge(lo, mi, hi);
}