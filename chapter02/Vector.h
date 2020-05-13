//
// Created by wangheng on 2020/5/13.
//

#ifndef DATA_STRUCTURE_VECTOR_H
#define DATA_STRUCTURE_VECTOR_H

typedef int Rank ;
#define DEFAULT_CAPACITY 3

template<typename T> class Vector {
private:
    Rank _size;
    int _capacity;
    T* _elem;
protected:
    void copyFrom(T const *A, Rank lo, Rank hi)   // 赋值数组区间[lo, hi)
    {
        _elem = new T[_capacity = (hi - lo) * 2];
        _size = 0;
        while (lo < hi) {
            _elem[_size++] = A[lo++];
        }
    }
    Rank max(Rank lo, Rank hi);
    void expand();  // 空间不足时扩充
    void shrink();  // 装填因子过小时压缩
public:
    // 构造函数
    Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0) : _capacity(c) {
        _elem = new T[_capacity];
        for (_size = 0; _size < s; _elem[_size++] = v);
    }
    Vector(T const * A, Rank n) { copyFrom(A, 0, n); }
    Vector(T const * A, Rank lo, Rank hi) { copyFrom(A, lo, hi); }
    Vector(const Vector<T>& vec) { copyFrom(vec._elem, 0, vec._size); }
    Vector(const Vector<T>& vec, Rank lo, Rank hi) { copyFrom(vec._elem, lo, hi); }
    // 析构函数
    ~Vector() { delete [] _elem; }

    int size() const { return _size; }
    bool empty() const { return !_size; }
    T& operator[](Rank r) const ;
    Rank insert(Rank r, T const &e);
    int remove(Rank lo, Rank hi);
    T remove(Rank r);
    Rank find(T const & e, Rank lo, Rank hi) const ;
    int depulicate();

};

#endif //DATA_STRUCTURE_VECTOR_H
