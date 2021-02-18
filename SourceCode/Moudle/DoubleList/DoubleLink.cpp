#include "DoubleLink.h"

/**
  * @brief  ˫�����ʼ��
  * @desc   None
  * @param  None
  * @retval None
  */
template <typename T>
DoubleLink<T>::DoubleLink()
{
    phead = new DNode();
    phead->prev = phead->next = phead;
}

/**
  * @brief  ˫�������
  * @desc   None
  * @param  None
  * @retval None
  */
template <typename T>
DoubleLink<T>::~DoubleLink()
{
    DNode* ptmp;
    DNode* pnode = phead->next;
    while (pnode != phead)
    {
        ptmp = pnode;
        pnode = pnode->next;
        delete ptmp;
    }
    delete phead;
    phead = NULL;
}

/**
  * @brief  ��ȡ˫����ڵ���Ŀ
  * @desc   None
  * @param  None
  * @retval value
  */
template <typename T>
int DoubleLink<T>::size()
{
    return count;
}

/**
  * @brief  �ж�˫�����Ƿ�Ϊ��
  * @desc   None
  * @param  None
  * @retval None
  */
template <typename T>
int DoubleLink<T>::empty() const
{
    return count == 0;
}

/**
  * @brief  ����˫����
  * @desc   None
  * @param  None
  * @retval None
  */
void DoubleLink<T>::traverse() const
{
    DNode* tmp = phead->next;
    while (tmp != phead)
    {
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

/**
  * @brief  ��ȡ��indexλ�õĽڵ��ֵ
  * @desc   None
  * @param  None
  * @retval value
  */
template <typename T>
T DoubleLink<T>::get(int index)
{
    return getNode(index)->value;
}

/**
  * @brief  ��ȡ��1���ڵ��ֵ
  * @desc   None
  * @param  None
  * @retval value
  */
template <typename T>
T DoubleLink<T>::getFirst()
{
    return getNode(0)->value;
}

/**
  * @brief  ��ȡ���1���ڵ��ֵ
  * @desc   None
  * @param  None
  * @retval value
  */
template <typename T>
T DoubleLink<T>::getLast()
{
    return getNode(count - 1)->value;
}

/**
  * @brief  ���ڵ���뵽��indexλ��֮ǰ
  * @desc   None
  * @param  None
  * @retval value
  */
template <typename T>
int DoubleLink<T>::insert(int index, T t)
{
    if (index == 0)
        return insertFirst(t);

    DNode* pindex = getNode(index);
    DNode* pnode = new DNode(t, pindex->prev, pindex);
    pindex->prev->next = pnode;
    pindex->prev = pnode;
    count++;
    return 0;
}

/**
  * @brief  ���ڵ���뵽��1��λ��
  * @desc   None
  * @param  None
  * @retval value
  */
template <typename T>
int DoubleLink<T>::insertFirst(T t)
{
    DNode* pnode = new DNode(t, phead, phead->next);
    phead->next->prev = pnode;
    phead->next = pnode;
    count++;
    return 0;
}

/**
  * @brief  ���ڵ���뵽���λ��
  * @desc   None
  * @param  None
  * @retval value
  */
template <typename T>
int DoubleLink<T>::appendLast(T t)
{
    DNode* pnode = new DNode(t, phead->prev, phead);
    phead->prev->next = pnode;
    phead->prev = pnode;
    count++;
    return 0;
}

/**
  * @brief  ɾ��indexλ�õĽڵ�
  * @desc   None
  * @param  None
  * @retval value
  */
template <typename T>
int DoubleLink<T>::del(int index)
{
    DNode* pindex = getNode(index);
    pindex->next->prev = pindex->prev;
    pindex->prev->next = pindex->next;
    delete pindex;
    count--;
    return 0;
}

/**
  * @brief  ��ȡ��indexλ�õĽڵ�
  * @desc   None
  * @param  None
  * @retval DNode
  */
template <typename T>
typename DoubleLink<T>::DNode* DoubleLink<T>::getNode(int index)
{
    if (index < 0 || index >= count)        // �жϲ�����Ч��
    {
        cout << "get node failed!the index in out of bound!" << endl;
        return NULL;
    }

    if (index <= count / 2)                 // �������
    {
        int i = 0;
        DNode* pindex = phead->next;
        while (i++ < index)
        {
            pindex = pindex->next;
        }
        return pindex;
    }

    int j = 0;                              // �������
    int rindex = count - index - 1;
    DNode* prindex = phead->prev;
    while (j++ < rindex)
    {
        prindex = prindex->prev;
    }
    return prindex;
}

int main()
{
    // ˫�����ʼ��
    DoubleLink<T>::DoubleLink();
    DoubleLink<T> Dlist;

    // ˫�������ݲ���
    Dlist.insert(0,20);
    Dlist.traverse();

    Dlist.insertFirst(40);
    Dlist.traverse();

    Dlist.appendLast(10);
    Dlist.traverse();

    // ˫��������ɾ��
    Dlist.del(1);
    Dlist.traverse();

    system("pause");
    return 0;
}
