//
// Created by wangheng on 2020/5/13.
//

#ifndef TEST_VECTOR_H
#define TEST_VECTOR_H

typedef int Rank ;
#define DEFAULT_CAPACITY 3

template<typename T> class Vector {
private:
    Rank _size;
    int _capacity;
    T* _elem;
protected:
    void copyFrom(const T* A, Rank lo, Rank hi);   // 赋值数组区间[lo, hi)
    Rank max(Rank lo, Rank hi);
    void expand();  // 空间不足时扩充
    void shrink();  // 装填因子过小时压缩
    void merge(Rank lo, Rank mi, Rank hi);
public:
    // 构造函数
    Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0) : _capacity(c) {
        _elem = new T[_capacity];
        for (_size = 0; _size < s; _elem[_size++] = v);
    }
    Vector(const T* A, Rank n) { copyFrom(A, 0, n); }
    Vector(const T* A, Rank lo, Rank hi) { copyFrom(A, lo, hi); }
    Vector(const Vector<T>& vec) { copyFrom(vec._elem, 0, vec._size); }
    // 定义拷贝赋值运算符
    Vector<T>& operator=(const Vector<T>& vec) {
        if (_elem)
            delete [] _elem;
        copyFrom(vec._elem, 0, vec._size);
        return *this;
    }
    Vector(const Vector<T>& vec, Rank lo, Rank hi) { copyFrom(vec._elem, lo, hi); }
    // 析构函数
    ~Vector() { delete [] _elem; }

    int size() const { return _size; }
    bool empty() const { return !_size; }
    T& operator[](Rank r) const ;
    Rank insert(Rank r, T const &e);
    Rank insert(T const &e) { return insert(_size, e); }
    int remove(Rank lo, Rank hi);
    T remove(Rank r);
    Rank find(T const & e, Rank lo, Rank hi) const ;    // 无序向量区间查找
    Rank find(T const & e) const; // 无序向量整体查找
    int deduplicate();  // 无序向量唯一化
    void traverse(void (*visit)(T&));
    int disordered() const ;    // 计算逆序对
    int uniquify();     // 有序向量唯一化
    void unsort(Rank lo, Rank hi);  // 等概率随机置乱区间[lo, hi)
    Rank search(T const& e, Rank lo, Rank hi) const;    // 有序区间向量区间查找
    Rank search(T const& e) const  // 有序向量整体查找
    {
        return (0 >= _size) ? -1 : search(e, 0, _size);
    }
    void bubbleSort(Rank lo, Rank hi);  // 冒泡排序
    void bubbleSort() { bubbleSort(0, _size); }
    void mergeSort(Rank lo, Rank hi);   // 归并排序
    void mergeSort() { mergeSort(0, _size); }
};

#include "Vector_implementation.h"

#endif //TEST_VECTOR_H
