//
// Created by wangheng on 2020/5/31.
//

#ifndef DATA_STRUCTURE_STACK_H
#define DATA_STRUCTURE_STACK_H

#include "../chapter02/Vector.h"

template<typename T>
class Stack : public Vector<T> {
public:
    void push(T const &e) { this->insert(e); }
    T pop() { return this->remove(this->size() - 1); }
    T& top() { return (*this)[this->size() - 1]; }
};

#endif //DATA_STRUCTURE_STACK_H
