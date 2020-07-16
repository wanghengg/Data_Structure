#ifndef DATA_STRUCTURE_BINNODE_IMPLEMENTATION_H
#define DATA_STRUCTURE_BINNODE_IMPLEMENTATION_H

#include "BinNode.h"
#include "BinNode_macro_BASIC.h"

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
BinNode<T>* BinNode<T>::succ() {}

template<typename T>
template<typename VST>
void BinNode<T>::travLevel(VST &visit) {}

template<typename T>
template<typename VST>
void BinNode<T>::travPre(VST &visit) {}

template<typename T>
template<typename VST>
<<<<<<< HEAD
void BinNode<T>::travIn(VST &visit) {
    if(!this) return;
    visit(data);
    lc->travIn(visit);
    rc->travIn(visit);
}
=======
void BinNode<T>::travIn(VST &visit) {}
>>>>>>> 327f5f82924c13b661b331df3f07c67f0907bd56

template<typename T>
template<typename VST>
void BinNode<T>::travPost(VST &visit) {}

#endif //DATA_STRUCTURE_BINNODE_IMPLEMENTATION_H
