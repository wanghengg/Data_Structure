//
// Created by wangheng on 2020/7/18.
//

#ifndef DATA_STRUCTURE_BINNODE_TRAVPREORDER_H
#define DATA_STRUCTURE_BINNODE_TRAVPREORDER_H

#include "../../chapter04/Stack.h"
#include "BinNode.h"

template<typename T, typename VST>
static void visitAlongLeftBranch(BinNode<T>* x, VST& visit, Stack<BinNode<T>*>& s) {
    while (x) {
        visit(x->data);
        s.push(x->rc);
        x = x->lc;
    }
}

template<typename T, typename VST>
void travPre_I2(BinNode<T>* x, VST& visit) {
    Stack<BinNode<T>>* s;
    while (true) {
        visitAlongLeftBranch(x, visit, s);
        if (s->empty()) break;
        x = s->pop();
    }
}

#endif //DATA_STRUCTURE_BINNODE_TRAVPREORDER_H
