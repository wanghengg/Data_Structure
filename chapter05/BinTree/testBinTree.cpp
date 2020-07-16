#include <iostream>
#include "BinTree.h"

void fun(const int *a) {
    std::cout << *a << std::endl;
    a = nullptr;
}

int main() {
    BinTree<int> bt1;
    bt1.insertAsRoot(3);
    bt1.insertAsLc(bt1.root(), 3);
    bt1.insertAsRc(bt1.root(), 12);
    std::cout << bt1.size() << std::endl;
    bt1.remove(bt1.root()->lc);
    std::cout << bt1.size() << std::endl;

    BinTree<int> bt2;
    bt2.insertAsRoot(2);
    bt2.insertAsRc(bt2.root(), 1);
    bt2.insertAsLc(bt2.root()->rc, 5);
    std::cout << bt2.size() << std::endl;

    BinTree<int>* pbt = &bt2;
    bt1.attachAsLc(bt1.root()->rc, pbt);
    std::cout << bt1.size() << std::endl;

    return 0;
}