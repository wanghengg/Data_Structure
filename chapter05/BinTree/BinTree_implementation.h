#ifndef DATA_STRUCTURE_BINTREE_IMPLEMENTATION_H
#define DATA_STRUCTURE_BINTREE_IMPLEMENTATION_H

#include "BinTree.h"
#include "release.h"
#include "BinTree_remove.h"
#include <algorithm>
#include "BinNode_travInorder.h"

template<typename T>
int BinTree<T>::updateHeight(BinNode<T> *x) {
    return x->height =  1 + std::max(stature(x->lc), stature(x->rc));
}

template<typename T>
void BinTree<T>::updateHeightAbove(BinNode<T> *x) {
    while (x) {
        updateHeight(x);
        x = x->parent;
    }
}

template<typename T>
BinNode<T>* BinTree<T>::insertAsRoot(const T &e) {
    _size = 1;
    return _root = new BinNode<T>(e);
}

template<typename T>
BinNode<T>* BinTree<T>::insertAsLc(BinNode<T> *x, const T &e) {
    ++_size;
    x->insertAsLc(e);
    updateHeightAbove(x);
    return x->lc;
}

template<typename T>
BinNode<T>* BinTree<T>::insertAsRc(BinNode<T> *x, const T &e) {
    ++_size;
    x->insertAsRc(e);
    updateHeightAbove(x);
    return x->rc;
}

template<typename T>
BinNode<T>* BinTree<T>::attachAsLc(BinNode<T> *x, BinTree<T> *&t) {
    x->lc = t->_root;   // x的左孩子是t的根节点
    if (x->lc)
        x->lc->parent = x;  // 接入，t的根节点的父节点是x
    _size += t->_size;  // 更新全树规模
    updateHeightAbove(x);   // 更新x所有祖先的高度
//    t->_root = nullptr;
//    t->_size = 0;
//    release(t);
    t = nullptr;

    return x;
}

template<typename T>
BinNode<T>* BinTree<T>::attachAsRc(BinNode<T> *x, BinTree<T> *&t) {
    x->rc = t->_root;
    if (x->rc)
        x->rc->parent = x;
    _size += t->_size;
    updateHeightAbove(x);
//    t->_root = nullptr;
//    t->_size = 0;
//    release(t);
    t = nullptr;    // 不能在通过t访问

    return x;
}

template<typename T>
BinTree<T>* BinTree<T>::secede(BinNode<T> *x) {
    FromParentTo(*x) = nullptr;
    updateHeightAbove(x->parent);
    auto* t = new BinTree<T>;
    t->_root = x;
    x->parent = nullptr;
    t->_size = x->size();
    _size -= t->_size;
    return t;
}

#endif //DATA_STRUCTURE_BINTREE_IMPLEMENTATION_H
