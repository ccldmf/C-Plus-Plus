#include "List.h"

/**
  * @brief  查找位序为i的内存地址
  * @desc   1.检查要查找的位序的合法性
  *         2.设置工作指针，指向头结点；设置计数器，进行计数，直到指向位序为i的结点
  * @param  None
  * @retval None
  */
template<typename elemType>
typename linkList<elemType>::Node* linkList<elemType>::getPosition(int i) const
{
    if (i < -1 || i > curLength - 1)
        return NULL;
    Node* p = head;
    int count = 0;
    while (count <= i)
    {
        p = p->next;
        count++;
    }
    return p;
}

/**
  * @brief  单链表初始化
  * @desc   创建一个带有头结点的空链表，即申请一个
  *         新的节点作为头结点，不设置节点数据，只
  *         设置其指针域为空即可
  * @param  None
  * @retval None
  */
template<typename elemType>
linkList<elemType>::linkList()
{
    head = tail = new Node();               // 创建带头结点的单链表
    curLength = 0;
}

/**
  * @brief  清除单链表
  * @desc   None
  * @param  None
  * @retval None
  */
template<typename elemType>
linkList<elemType>::~linkList()
{
    clear();                                // 清空单链表
    delete head;
}

/**
  * @brief  清空单链表
  * @desc   将链表中各个结点数据删除，边移动，边删除
  * @param  None
  * @retval None
  */
template<typename elemType>
void linkList<elemType>::clear()
{
    Node* p, * tmp;
    p = head->next;                         // 引入工作指针，防止随意修改头指针
    while (NULL != p)
    {
        tmp = p;
        p = p->next;                        // 指针后移
        delete tmp;
    }
    head->next = NULL;
    tail = head;
    curLength = 0;
}

/**
  * @brief  插入结点
  * @desc   位序i处插入值为value的结点q:
  *         1.先找到位序i结点的前驱结点p
  *         2.q的后继指向p原来的后继，修改p的后继为q
  *         3.合法的插入范围是[0,curLength],其中0表示插入点为首元素，curLength为表尾
  *         4.插入算法主要是移动指针查找结点，时间复杂度为O(n).
  * @param  i:插入结点的序号  value:插入的值
  * @retval None
  */
template<typename elemType>
void linkList<elemType>::insert(int i, const elemType& value)
{
    Node* p, * q;
    if (i < -1 || i > curLength)
    {
        throw out_of_range("Out of Range");
    }
    p = getPosition(i - 1);             // 定位到i结点的前驱
    q = new Node(value, p->next);       // 申请结点q，数据域为value，指针域为p结点的下一个结点
    p->next = q;
    if (p == tail)                      // 如果插入点在表尾，则q是新的表尾
        tail = q;
    curLength++;
}

/**
  * @brief  删除指定位序的结点
  * @desc   1.检查删除是否合法，合法范围[0,curLength]
  *         2.找到位序为i结点的前继结点，修改指针的指向关系，时间复杂度为：O(n)
  * @param  i:删除结点序号
  * @retval None
  */
template<typename elemType>
void linkList<elemType>::remove(int i)
{
    Node* pre, * p;
    if (i < 0 || i > curLength - 1)
    {
        throw out_of_range("Out of Range");
    }
    pre = getPosition(i - 1);
    p = pre->next;
    if (p == tail)                      // 如果删除的结点为表尾结点
    {
        tail = pre;                     // 将pre结点作为表尾结点
        pre->next = NULL;
        delete p;
    }
    else
    {
        pre->next = p->next;
        delete p;
    }
    curLength--;
}

/**
  * @brief  查找值为value的元素的位序
  * @desc   1.设置计数器count，从链表头开始遍历
  *         2.查找成功，返回count，如果在表中未查到，返回-1
  *         3.时间复杂度:O(n)
  * @param  
  * @retval value元素的位序
  */
template<typename elemType>
int linkList<elemType>::search(const elemType& value) const
{
    int count = 0;
    Node* p = head->next;
    while (NULL != p && p->data != value)
    {
        p = p->next;
        count++;
    }
    if (NULL == p)
    {
        return -1;
    }
    else
    {
        return count;
    }
}

/**
  * @brief  查找值为value的结点的前驱位序
  * @desc   1.设置计数器count，两个指针p和pre，分别指向当前结点和它的前驱
  *         2.若p==NULL,查找失败，返回-1
  *         3.若找到值为value的结点，且该节点为首元素结点，则无前驱，返回-1
  *         4.若找到值为value的结点，且该节点为首元素结点，则无前驱，返回前驱的位序
  * @param  value:查找的值
  * @retval value元素的结点的前驱位序
  */
template<typename elemType>
int linkList<elemType>::prior(const elemType& value) const
{
    int count = -1;
    Node* p, * pre;
    p = head->next;
    pre = NULL;

    while (NULL != p && p->data != value)
    {
        pre = p;
        p = p->next;
        count++;
    }
    if (NULL == p)
    {
        return -1;
    }
    else
    {
        return count;
    }
}

/**
  * @brief  遍历单链表
  * @desc   1.从头到尾遍历链表中的每个结点
  *         2.时间复杂度为：O(n)
  * @param  None
  * @retval None
  */
template<typename elemType>
void linkList<elemType>::traverse() const
{
    Node* tmp = head->next;
    while (NULL != tmp)
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

/**
  * @brief  头插法建立单链表
  * @desc   1.头插法即在链表的头部插入结点建立单链表：每次插入将新增结点置于头结点之后，首元结点之前
  *           因为在单链表的头部插入，所以读入数据的顺序会是相反的。
  *         2.时间复杂度为：O(n)
  * @param  None
  * @retval None
  */
template<typename elemType>
void linkList<elemType>::headCreate()
{
    Node* p;
    elemType value, flag;
    cout << "Input elements,end with:" << endl;
    cin >> flag;                            // 输入结束标志
    while (cin >> value, value != flag)
    {
        p = new Node(value, head->next);    // 创建新结点p->data = value,p->next = head->next;
        head->next = p;
        if (head == tail)
            tail = p;
        curLength++;
    }
}

/**
  * @brief  尾插法建立单链表
  * @desc   1.在单链表的尾部插入结点建立新的单链表
  *           初始时，创建一个带有头结点的空链表，头指针和尾指针指向头结点
  *           按顺序表中的元素顺序读入元素并申请结点，将新结点插入tail指针的后边，修改tail指向新结点
  * @param  None
  * @retval None
  */
template<typename elemType>
void linkList<elemType>::tailCreate()
{
    Node* p;
    elemType value, flag;
    cout << "Input elements,end with:" << endl;
    cin >> flag;
    while (cin >> value, value != flag)
    {
        p = new Node(value, NULL);
        tail->next = p;
        tail = p;
        curLength++;
    }
}

/**
  * @brief  逆置单链表
  * @desc   利用头插法建立的单链表，对于元素的顺序与读入的顺序相反的。 
  *         1.p依次访问单链表中的每个结点，没访问一个结点，将它插入在头结点之后
  *         2.向后移动p，直到所有结点全部重新插入到单链表之中
  *         3.时间复杂度：O(n)
  * @param  None
  * @retval None
  */
template<typename elemType>
void linkList<elemType>::inverse()
{
    Node* p, * tmp;
    p = head->next;
    head->next = NULL;                      // 头结点指针域为空，构成空链表
    if (p)
        tail = p;                           // 逆置后，原来的首元结点变成为尾结点
    while (p)
    {
        tmp = p->next;
        p->next = head->next;
        head->next = p;
        p = tmp;
    }
}

int main()
{
    elemType value;
    // 单链表初始化
    linkList<elemType>::linkList();
    linkList<elemType> list;

    // 头插法建立链表
    list.headCreate();
    cout << "头插法建立链表：";
    list.traverse();

    cout << "链表逆置：";
    list.inverse();
    list.traverse();

    list.insert(2, 199);
    cout << "插入后单链表：";
    list.traverse();

    cout << "输入要查找的元素：";
    cin >> value;
    cout << "元素" << value << "的位置为：" << list.search(value) << endl;

    cout << "输入要查找元素的前驱：";
    cin >> value;
    cout << "元素" << value << "的前驱位序为：" << list.prior(value) << endl;

    cout << "输入删除元素的位序：";
    cin >> value;
    list.remove(value);
    list.traverse();

    // 尾插法建立链表
    list.tailCreate();
    list.traverse();

    return 0;
}