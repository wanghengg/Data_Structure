#ifndef DATA_STRUCTURE_BINNODE_IMPLEMENTATION_H
#define DATA_STRUCTURE_BINNODE_IMPLEMENTATION_H

//#include "BinNode.h"
#include "BinNode_macro_BASIC.h"
#include "BinNode_travInorder.h"
#include "BinNode_travPreorder.h"

template<typename T>
int BinNode<T>::size() {
    int s = 1;  // 计入本身
    if (lc) s += lc->size();    // 递归计入左子树规模
    if (rc) s += rc->size();    // 递归计入右子树规模
    return s;
}

template<typename T>
BinNode<T>* BinNode<T>::insertAsLc(const T &e) {
    return lc = new BinNode<T>(e, this);
}

template<typename T>
BinNode<T>* BinNode<T>::insertAsRc(const T &e) {
    return rc = new BinNode<T>(e, this);
}

template<typename T>
BinNode<T>* BinNode<T>::succ() {
    BinNode<T>* s = this;
    if (rc) {
        s = rc;
        while (HasLChild(*s)) s = s->lc;
    } else {
        while (IsRChild(*s)) s = s->parent;
        s = s->parent;
    }
}

template<typename T>
template<typename VST>
void BinNode<T>::travLevel(VST &visit) {

}

template<typename T>
template<typename VST>
void BinNode<T>::travPre(VST &visit) {}

template<typename T>
template<typename VST>
void BinNode<T>::travIn(VST &visit) {
    switch (rand() % 4) {
        case 1:
            travIn_I1(this, visit);
            break;
        case 2:
            travIn_I2(this, visit);
            break;
        case 3:
            travIn_I3(this, visit);
        default:
            travIn_R(this, visit);
    }
}

template<typename T>
template<typename VST>
void BinNode<T>::travPost(VST &visit) {}

#endif //DATA_STRUCTURE_BINNODE_IMPLEMENTATION_H
