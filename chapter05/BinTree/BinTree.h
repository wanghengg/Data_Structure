#ifndef DATA_STRUCTURE_BINTREE_H
#define DATA_STRUCTURE_BINTREE_H

#include "BinNode.h"

template<typename T>
class BinTree{
protected:
    int _size;  // 规模
    BinNode<T>* _root;  // 根节点
    virtual int updateHeight(BinNode<T>* x);    // 更新节点x的高度
    void updateHeightAbove(BinNode<T>* x);  // 更新节点x及其祖先的高度
public:
    BinTree() : _size(0), _root(nullptr) {} // 构造函数,生成一个空树
    ~BinTree() { if (0 < _size) remove(_root); }    // 析构函数
    int size() const { return _size; }  // 规模
    bool empty() const { return !_root; }   // 判空
    BinNode<T>* root() const { return _root; }  // 树根
    BinNode<T>* insertAsRoot(T const &e);   // 插入树根节点
    BinNode<T>* insertAsLc(BinNode<T>* x, T const &e);  // e作为x的左孩子插入
    BinNode<T>* insertAsRc(BinNode<T>* x, T const &e);  // e作为x的右孩子插入
    BinNode<T>* attachAsLc(BinNode<T>* x, BinTree<T>* &t);  // t作为x左子树插入
    BinNode<T>* attachAsRc(BinNode<T>* x, BinTree<T>* &t);  // t作为x右子树插入
    int  remove(BinNode<T>* x); // 删除以位置x处节点为根的子树，返回该子树原先的规模
    BinTree<T>* secede(BinNode<T>* x);  // 删除以位置x处节点为根的子树，并返回该子树原先的规模

    template<typename VST>  // 操作器
    void travLevel(VST& visit) {
        if (_root)
            _root->travLevel(visit);
    }

    template<typename VST>
    void travIn(VST& visit) {
        if (_root)
            _root->travIn(visit);
    }

    template<typename VST>
    void travPre(VST& visit) {
        if (_root)
            _root->travPre(visit);
    }

    template<typename VST>
    void travPost(VST& visit) {
        if (_root)
            _root->travPost(visit);
    }

    bool operator<(BinTree<T> const &t) {
        return _root && t._root && (_root < t._root);
    }

    bool operator==(BinTree<T> const &t) {
        return _root && t._root && (_root == t._root);
    }
};

#include "BinTree_implementation.h"

#endif //DATA_STRUCTURE_BINTREE_H
