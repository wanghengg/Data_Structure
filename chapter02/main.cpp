#include <iostream>
#include "Vector.h"

int main() {
    Vector<int> ivec;
    ivec.insert(3);
    ivec.insert(9);
    std::cout << ivec.size() << std::endl;
    std::cout << ivec.search(3) << std::endl;

    return 0;
}