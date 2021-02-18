#include <iostream>

using namespace std;
typedef int elemType;

template <typename elemType>

class Stack
{
private:
    const int MAX_SIZE = 5;         // ջ�Ĵ�С
    typedef struct 
    {
        int* top;                   // ջ��ָ��
        int* bottom;                // ջ��ָ��
    }stack;
    
    stack *mStack;
               
    int StackEmpty();               // �ж�ջ�Ƿ�Ϊ��
    int StackFull();                // �ж�ջ�Ƿ�Ϊ��

public:
    Stack();
    ~Stack();

    int Push(elemType value);       // ��ջ
    int Pop();                      // ��ջ
    void DisplayStack();            // ����ջ
};