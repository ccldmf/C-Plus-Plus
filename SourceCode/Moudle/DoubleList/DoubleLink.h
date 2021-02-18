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

    int size();                             // ��ȡ�����С
    int empty() const;                      // �ж������Ƿ�Ϊ��
    void traverse() const;                  // ����˫����

    T get(int index);                       // ��ȡ�ڵ�
    T getFirst();                           // ��ȡ�׽ڵ�
    T getLast();                            // ��ȡβ�ڵ�

    int insert(int index, T t);             // λ��index������T
    int insertFirst(T t);                   // ���׽ڵ����T
    int appendLast(T t);                    // ��β�ڵ����T

    int del(int index);                     // ɾ��index���Ľڵ�

private:
    int count;                              // ��¼�ڵ�����
    DNode* phead;                           // ����ͷ
    DNode* getNode(int index);              // ���index���ڵ�
};

#endif /* DOUBLE_LINK_H */
