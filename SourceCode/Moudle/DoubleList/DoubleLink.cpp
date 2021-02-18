#include "DoubleLink.h"

/**
  * @brief  双链表初始化
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
  * @brief  双链表清除
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
  * @brief  获取双链表节点数目
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
  * @brief  判断双链表是否为空
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
  * @brief  遍历双链表
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
  * @brief  获取第index位置的节点的值
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
  * @brief  获取第1个节点的值
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
  * @brief  获取最后1个节点的值
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
  * @brief  将节点插入到第index位置之前
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
  * @brief  将节点插入到第1个位置
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
  * @brief  将节点插入到最后位置
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
  * @brief  删除index位置的节点
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
  * @brief  获取第index位置的节点
  * @desc   None
  * @param  None
  * @retval DNode
  */
template <typename T>
typename DoubleLink<T>::DNode* DoubleLink<T>::getNode(int index)
{
    if (index < 0 || index >= count)        // 判断参数有效性
    {
        cout << "get node failed!the index in out of bound!" << endl;
        return NULL;
    }

    if (index <= count / 2)                 // 正向查找
    {
        int i = 0;
        DNode* pindex = phead->next;
        while (i++ < index)
        {
            pindex = pindex->next;
        }
        return pindex;
    }

    int j = 0;                              // 反向查找
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
    // 双链表初始化
    DoubleLink<T>::DoubleLink();
    DoubleLink<T> Dlist;

    // 双链表数据插入
    Dlist.insert(0,20);
    Dlist.traverse();

    Dlist.insertFirst(40);
    Dlist.traverse();

    Dlist.appendLast(10);
    Dlist.traverse();

    // 双链表数据删除
    Dlist.del(1);
    Dlist.traverse();

    system("pause");
    return 0;
}
