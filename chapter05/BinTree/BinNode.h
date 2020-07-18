#ifndef DATA_STRUCTURE_BINNODE_H
#define DATA_STRUCTURE_BINNODE_H

#define stature(p) ((p) ? (p)->height : -1)
typedef enum {RB_RED, RB_BLACK} RBcolor;

template<typename T> struct BinNode{
    T data; // 数值
    BinNode* parent; // 父节点
    BinNode* lc, *rc;    // 左，右孩子
    int height; // 高度
    int npl;    // null path length(左式堆，也可以直接用height代替)
    RBcolor color;  // 颜色(红黑树)

    // 构造函数
    BinNode() :
        parent(nullptr), lc(nullptr), rc(nullptr), height(0), npl(1), color(RB_RED) {}
    BinNode(T e, BinNode* p = nullptr, BinNode* lc = nullptr, BinNode* rc = nullptr,
            int h = 0, int l = 1, RBcolor c = RB_RED) :
            data(e), parent(p), lc(lc), rc(rc), height(h), npl(l), color(c) {}

    // 操作接口
    int size(); // 统计当前节点后代总数，亦即一起为根的子树的规模
    BinNode* insertAsLc(T const &); // 作为当前节点的左孩子插入新节点
    BinNode* insertAsRc(T const &); // 作为当前节点的右孩子插入新节点
    BinNode* succ();    // (中序遍历意义下)取当前节点的直接后继
    template<typename VST> void travLevel(VST&);    // 子树层次遍历
    template<typename VST> void travPre(VST&);  // 子树先序遍历
    template<typename VST> void travIn(VST&);   // 子树中序遍历
    template<typename VST> void travPost(VST&); //子树后序遍历

    // 比较器、判等器
    bool operator<(BinNode const &bn) { return data < bn.data; }    // 小于
    bool operator==(BinNode const &bn) { return data == bn.data; }  // 等于
};

#include "BinNode_implementation.h"

#endif //DATA_STRUCTURE_BINNODE_H
