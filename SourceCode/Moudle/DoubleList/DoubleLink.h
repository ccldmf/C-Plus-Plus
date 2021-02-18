#ifndef DOUBLE_LINK_H
#define DOUBLE_LINK_H
#include<iostream>
using namespace std;

typedef int T;

template <typename T>
class DoubleLink
{
private:
    struct DNode {

        T value;
        DNode* prev;
        DNode* next;

        DNode() {}
        DNode(T t, DNode* prev, DNode* next)
        {
            this->value = t;
            this->prev = prev;
            this->next = next;
        }
    };

public:
    DoubleLink();
    ~DoubleLink();

    int size();                             // 获取链表大小
    int empty() const;                      // 判断链表是否为空
    void traverse() const;                  // 遍历双链表

    T get(int index);                       // 获取节点
    T getFirst();                           // 获取首节点
    T getLast();                            // 获取尾节点

    int insert(int index, T t);             // 位序index处插入T
    int insertFirst(T t);                   // 在首节点插入T
    int appendLast(T t);                    // 在尾节点插入T

    int del(int index);                     // 删除index处的节点

private:
    int count;                              // 记录节点总数
    DNode* phead;                           // 链表头
    DNode* getNode(int index);              // 获得index处节点
};

#endif /* DOUBLE_LINK_H */
