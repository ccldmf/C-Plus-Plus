#include "Stack.h"
#include <stdlib.h>

/**
  * @brief  栈初始化
  * @desc   创建一个带有头结点的空链表，即申请一个
  *         新的节点作为头结点，不设置节点数据，只
  *         设置其指针域为空即可
  * @param  None
  * @retval None
  */
template <typename elemType>
Stack<elemType>::Stack()
{
    mStack = (stack*)malloc(sizeof(stack));
    mStack->bottom = (elemType*)malloc(MAX_SIZE * sizeof(elemType));
    if (NULL == mStack->bottom)
    {
        cout << "Malloc stack space error" << endl;
        return;
    }
    mStack->top = mStack->bottom;
}

/**
  * @brief  清除栈
  * @desc   None
  * @param  None
  * @retval None
  */
template <typename elemType>
Stack<elemType>::~Stack()
{
    free(mStack->bottom);
    mStack->top    = NULL;
    mStack->bottom = NULL;
    free(mStack);
}

/**
  * @brief  入栈
  * @desc   向栈中插入数据
  * @param  value:数据
  * @retval 0:Success -1:Fail
  */
template <typename elemType>
int Stack<elemType>::Push(elemType value)
{
    if (0 != StackFull())
    {
        cout << "Current Stack is full,can't push" << endl;
        return -1;
    }
    *mStack->top = value;
    mStack->top++;
    return 0;
}

/**
  * @brief  出栈
  * @desc   从栈中弹出数据
  * @param  None
  * @retval 0:Success -1:Fail
  */
template <typename elemType>
int Stack<elemType>::Pop()
{
    if (0 != StackEmpty())
    {
        cout << "Current stack is empty,can't pop" << endl;
        return -1;
    }
    mStack->top--;
    return 0;
}

/**
  * @brief  遍历栈中数据
  * @desc   None
  * @param  None
  * @retval None
  */
template <typename elemType>
void Stack<elemType>::DisplayStack()
{
    if (0 != StackEmpty())
    {
        cout << "Current stack is empty" << endl;
        return;
    }
    int *theTop;
    cout << "栈中元素为:[";
    theTop = mStack->top;
    while (theTop != mStack->bottom)
    {
        theTop--;
        cout << *theTop <<" ";
    }
    cout << "]" << endl;
}

/**
  * @brief  判断栈是否为空
  * @desc   None
  * @param  None
  * @retval 0:Success
  */
template <typename elemType>
int Stack<elemType>::StackEmpty()
{
    if (mStack->top != mStack->bottom)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

/**
  * @brief  判断栈是否为满
  * @desc   None
  * @param  None
  * @retval 0:Success
  */
template <typename elemType>
int Stack<elemType>::StackFull()
{
    if (mStack->top - mStack->bottom == MAX_SIZE)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int main()
{
    elemType value;
    Stack<elemType> theStack;
    theStack.DisplayStack();

    cout << "输入要入栈的值:";
    cin >> value;
    theStack.Push(value);
    theStack.DisplayStack();
    
    cout << "输入要入栈的值:";
    cin >> value;
    theStack.Push(value);
    theStack.DisplayStack();

    cout << "出栈测试:" << endl;
    theStack.Pop();
    theStack.DisplayStack();

    while (1);
}