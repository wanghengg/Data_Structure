#ifndef DATA_STRUCTURE_BINTREE_REMOVE_H
#define DATA_STRUCTURE_BINTREE_REMOVE_H

#include "BinTree.h"

// 删除二叉树中位置x处的节点及其后代，返回被删除节点的数值
template<typename T>
int BinTree<T>::remove(BinNode<T> *x) {
    FromParentTo(*x) = nullptr; // 切断来自父节点的指针
    updateHeightAbove(x->parent);
    int n = removeAt(x); _size -= n; return n;  // 删除子树x，更新规模，返回删除节点总数
}

template<typename T>
static int removeAt(BinNode<T>* x) {
    if(!x) return 0;    // 递归基，空树
    int n = 1 + removeAt(x->lc) + removeAt(x->rc);  // 递归释放左、右子树
    release(x->data); release(x); return n; // 释放被删除节点，并返回删除节点总数
}

#endif //DATA_STRUCTURE_BINTREE_REMOVE_H
