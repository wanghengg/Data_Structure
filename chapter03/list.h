//
// Created by wangheng on 2020/5/18.
//

#ifndef DATA_STRUCTURE_LIST_H
#define DATA_STRUCTURE_LIST_H

#include "listNode.h"

template<typename T> class List{
private:
    int _size;  // 规模
    ListNode<T>* header;    // 头哨兵
    ListNode<T>* trailer;   // 尾哨兵

protected:
    void init();    // 列表创建时初始化
    int clear();    // 清除所有节点
    void copyNodes(ListNode<T>*, int ); // 复制列表中自位置p起的n项
    void merge(ListNode<T>*&, int, List<T>&, ListNode<T>*, int);    // 归并
    void mergeSort(ListNode<T>*&, int);  // 对从p开始连续的n个节点归并排序
    void selectionSort(ListNode<T>*, int); // 对从p开始连续的n个节点选择排序
    void insertionSort(ListNode<T>*, int); // 对从p开始连续的n个节点插入排序

public:
    // 构造函数
    List() { init(); }
    List(List<T> const &L); // 拷贝构造函数
    List(List<T> const &L, Rank r, Rank n); // 复制列表L中自r项起的n项
    List(ListNode<T>* p, int n);    // 复制列表中自位置p起的n项

    // 析构函数
    ~List();    // 释放(包含头哨兵和尾哨兵在内的)所有节点

    // 只读访问接口
    Rank size() const { return _size; } // 规模
    bool empty() const { return _size <= 0; }   // 判空
    T& operator[](Rank r) const ;   // 重载，支持寻秩访问
    ListNode<T>* first() const { return header->succ; } // 首节点位置
    ListNode<T>* end() const { return trailer->pred; }  // 末节点位置
    bool valid(ListNode<T>* p) // 判断位置p是否合法
    {
        return p && (header != p) && (trailer != p);
    }
    ListNode<T>* find(T const &e) const {   // 无序查找
        return find(e, _size, trailer);
    }
    ListNode<T>* find(T const &e, int n, ListNode<T>* p) const ;    // 无序列表区间查找
    ListNode<T>* search(T const &e) const { // 有序列表查找
        search(e, _size, trailer);
    }
    ListNode<T>* search(T const &e, int n, ListNode<T>* p) const ;  // 有序列表区间查找
    ListNode<T>* selectMax(ListNode<T>* p, int n);  // 在p及其后继n-1个后继中选出最大者
    ListNode<T>* selectMax() { return selectMax(header->succ, _size); } // 选出整体最大者

    // 可写访问接口
    ListNode<T>* insertAsFirst(T const &e); // 将e当做首节点插入
    ListNode<T>* insertAsEnd(T const &e);   // 将e当做末节点插入
    ListNode<T>* insertAfter(ListNode<T>* p, T const &e);   // 将e当做p的后继插入(after)
    ListNode<T>* insertBefore(ListNode<T>* p, T const &e);   // 将e当做p的前驱插入(before)
    T remove(ListNode<T>* p);   // 删除合法位置p处的节点，返回被删除节点
    void merge(List<T>& L) { merge(first(), size(), L, L.first(), L._size); }
    void sort( ListNode<T>* p, int n);  // 列表区间排序
    void sort() { sort(first(), _size); }   // 列表整体排序
    int deduplicate();  // 无序去重
    int uniquify(); // 有序去重
    void reverse(); // 前后倒置
    void traverse(void (*)(T&));    // 遍历
    template<typename VST>
    void traverse(VST&);    // 遍历（函数对象）
};

#include "list_implementation.h"

#endif //DATA_STRUCTURE_LIST_H
