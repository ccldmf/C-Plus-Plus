#include <iostream>

using namespace std;
typedef int elemType;

template <typename elemType>

class Stack
{
private:
    const int MAX_SIZE = 5;         // 栈的大小
    typedef struct 
    {
        int* top;                   // 栈顶指针
        int* bottom;                // 栈底指针
    }stack;
    
    stack *mStack;
               
    int StackEmpty();               // 判断栈是否为空
    int StackFull();                // 判断栈是否为满

public:
    Stack();
    ~Stack();

    int Push(elemType value);       // 入栈
    int Pop();                      // 出栈
    void DisplayStack();            // 遍历栈
};