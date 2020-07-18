#ifndef DATA_STRUCTURE_BINNODE_TRAVINORDER_H
#define DATA_STRUCTURE_BINNODE_TRAVINORDER_H

#include "../../chapter04/Stack.h"


template<typename T, typename VST>
void travIn_R(BinNode<T>* x, VST& visit) {
    if (!x) return; // 递归基，如果树为空，则停止遍历
    travIn_R(x->lc, visit); // 先遍历左子树
    visit(x->data); // 访问父节点
    travIn_R(x->rc, visit); // 遍历右子树
}

template<typename T>
static void goAlongLeftBranch(BinNode<T>* x, Stack<BinNode<T>*>& s) {
    while (x) {
        s.push(x);
        x = x->lc;
    }
}

template<typename T, typename VST>
void travIn_I1(BinNode<T>* x, VST& visit) {
    Stack<BinNode<T>*> s;
    while (true) {
        goAlongLeftBranch(x, s);
        if (s.empty()) break;
        x = s.pop();
        visit(x->data);
        x = x->rc;
    }
}

template<typename T, typename VST>
void travIn_I2(BinNode<T>* x, VST& visit) {
    Stack<BinNode<T>*> s;
    while (true) {
        if (x) {
            s.push(x);
            x = x->lc;
        } else if (!s.empty()) {
            x = s.pop();
            visit(x->data);
            x = x->rc;
        } else
            break;
    }
}

template<typename T, typename VST>
void travIn_I3(BinNode<T>* x, VST& visit) {
    bool backtrack = false;
    while (true) {
        if (!backtrack && HasLChild(*x))
            x = x->lc;
        else {
            visit(x->data);
            if (HasRChild(*x)) {
                x = x->rc;
                backtrack = false;
            } else {
                if (! (x = x->succ())) break;
                backtrack = true;
            }
        }
    }
}

#endif //DATA_STRUCTURE_BINNODE_TRAVINORDER_H
