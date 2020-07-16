#include "queue.h"
#include <iostream>

int main() {
    Queue<int> q;
    q.enqueue(3);
    q.enqueue(9);
    std::cout << q.size() << std::endl;
    std::cout << q.dequeue() << std::endl;
    q.enqueue(10);
    std::cout << q.front() << std::endl;
    std::cout << q.back() << std::endl;

    return 0;
}