#ifndef DATA_STRUCTURE_QUEUE_H
#define DATA_STRUCTURE_QUEUE_H

#include "../chapter03/list.h"

template<typename T>
class Queue : public List<T> {
public:
    void enqueue(T const &e) { this->insertAsEnd(e); }  // O(1)
    T dequeue() { return this->remove(this->first()); } // O(1)
    T& front() { return this->first()->data; }
    T& back() { return this->end()->data; }
};

#endif //DATA_STRUCTURE_QUEUE_H
