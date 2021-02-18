#include "Stack.h"
#include <stdlib.h>

/**
  * @brief  ջ��ʼ��
  * @desc   ����һ������ͷ���Ŀ�����������һ��
  *         �µĽڵ���Ϊͷ��㣬�����ýڵ����ݣ�ֻ
  *         ������ָ����Ϊ�ռ���
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
  * @brief  ���ջ
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
  * @brief  ��ջ
  * @desc   ��ջ�в�������
  * @param  value:����
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
  * @brief  ��ջ
  * @desc   ��ջ�е�������
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
  * @brief  ����ջ������
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
    cout << "ջ��Ԫ��Ϊ:[";
    theTop = mStack->top;
    while (theTop != mStack->bottom)
    {
        theTop--;
        cout << *theTop <<" ";
    }
    cout << "]" << endl;
}

/**
  * @brief  �ж�ջ�Ƿ�Ϊ��
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
  * @brief  �ж�ջ�Ƿ�Ϊ��
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

    cout << "����Ҫ��ջ��ֵ:";
    cin >> value;
    theStack.Push(value);
    theStack.DisplayStack();
    
    cout << "����Ҫ��ջ��ֵ:";
    cin >> value;
    theStack.Push(value);
    theStack.DisplayStack();

    cout << "��ջ����:" << endl;
    theStack.Pop();
    theStack.DisplayStack();

    while (1);
}