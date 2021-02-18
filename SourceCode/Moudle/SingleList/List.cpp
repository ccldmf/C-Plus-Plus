#include "List.h"

/**
  * @brief  ����λ��Ϊi���ڴ��ַ
  * @desc   1.���Ҫ���ҵ�λ��ĺϷ���
  *         2.���ù���ָ�룬ָ��ͷ��㣻���ü����������м�����ֱ��ָ��λ��Ϊi�Ľ��
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
  * @brief  �������ʼ��
  * @desc   ����һ������ͷ���Ŀ�����������һ��
  *         �µĽڵ���Ϊͷ��㣬�����ýڵ����ݣ�ֻ
  *         ������ָ����Ϊ�ռ���
  * @param  None
  * @retval None
  */
template<typename elemType>
linkList<elemType>::linkList()
{
    head = tail = new Node();               // ������ͷ���ĵ�����
    curLength = 0;
}

/**
  * @brief  ���������
  * @desc   None
  * @param  None
  * @retval None
  */
template<typename elemType>
linkList<elemType>::~linkList()
{
    clear();                                // ��յ�����
    delete head;
}

/**
  * @brief  ��յ�����
  * @desc   �������и����������ɾ�������ƶ�����ɾ��
  * @param  None
  * @retval None
  */
template<typename elemType>
void linkList<elemType>::clear()
{
    Node* p, * tmp;
    p = head->next;                         // ���빤��ָ�룬��ֹ�����޸�ͷָ��
    while (NULL != p)
    {
        tmp = p;
        p = p->next;                        // ָ�����
        delete tmp;
    }
    head->next = NULL;
    tail = head;
    curLength = 0;
}

/**
  * @brief  ������
  * @desc   λ��i������ֵΪvalue�Ľ��q:
  *         1.���ҵ�λ��i����ǰ�����p
  *         2.q�ĺ��ָ��pԭ���ĺ�̣��޸�p�ĺ��Ϊq
  *         3.�Ϸ��Ĳ��뷶Χ��[0,curLength],����0��ʾ�����Ϊ��Ԫ�أ�curLengthΪ��β
  *         4.�����㷨��Ҫ���ƶ�ָ����ҽ�㣬ʱ�临�Ӷ�ΪO(n).
  * @param  i:����������  value:�����ֵ
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
    p = getPosition(i - 1);             // ��λ��i����ǰ��
    q = new Node(value, p->next);       // ������q��������Ϊvalue��ָ����Ϊp������һ�����
    p->next = q;
    if (p == tail)                      // ���������ڱ�β����q���µı�β
        tail = q;
    curLength++;
}

/**
  * @brief  ɾ��ָ��λ��Ľ��
  * @desc   1.���ɾ���Ƿ�Ϸ����Ϸ���Χ[0,curLength]
  *         2.�ҵ�λ��Ϊi����ǰ�̽�㣬�޸�ָ���ָ���ϵ��ʱ�临�Ӷ�Ϊ��O(n)
  * @param  i:ɾ��������
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
    if (p == tail)                      // ���ɾ���Ľ��Ϊ��β���
    {
        tail = pre;                     // ��pre�����Ϊ��β���
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
  * @brief  ����ֵΪvalue��Ԫ�ص�λ��
  * @desc   1.���ü�����count��������ͷ��ʼ����
  *         2.���ҳɹ�������count������ڱ���δ�鵽������-1
  *         3.ʱ�临�Ӷ�:O(n)
  * @param  
  * @retval valueԪ�ص�λ��
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
  * @brief  ����ֵΪvalue�Ľ���ǰ��λ��
  * @desc   1.���ü�����count������ָ��p��pre���ֱ�ָ��ǰ��������ǰ��
  *         2.��p==NULL,����ʧ�ܣ�����-1
  *         3.���ҵ�ֵΪvalue�Ľ�㣬�Ҹýڵ�Ϊ��Ԫ�ؽ�㣬����ǰ��������-1
  *         4.���ҵ�ֵΪvalue�Ľ�㣬�Ҹýڵ�Ϊ��Ԫ�ؽ�㣬����ǰ��������ǰ����λ��
  * @param  value:���ҵ�ֵ
  * @retval valueԪ�صĽ���ǰ��λ��
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
  * @brief  ����������
  * @desc   1.��ͷ��β���������е�ÿ�����
  *         2.ʱ�临�Ӷ�Ϊ��O(n)
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
  * @brief  ͷ�巨����������
  * @desc   1.ͷ�巨���������ͷ�������㽨��������ÿ�β��뽫�����������ͷ���֮����Ԫ���֮ǰ
  *           ��Ϊ�ڵ������ͷ�����룬���Զ������ݵ�˳������෴�ġ�
  *         2.ʱ�临�Ӷ�Ϊ��O(n)
  * @param  None
  * @retval None
  */
template<typename elemType>
void linkList<elemType>::headCreate()
{
    Node* p;
    elemType value, flag;
    cout << "Input elements,end with:" << endl;
    cin >> flag;                            // ���������־
    while (cin >> value, value != flag)
    {
        p = new Node(value, head->next);    // �����½��p->data = value,p->next = head->next;
        head->next = p;
        if (head == tail)
            tail = p;
        curLength++;
    }
}

/**
  * @brief  β�巨����������
  * @desc   1.�ڵ������β�������㽨���µĵ�����
  *           ��ʼʱ������һ������ͷ���Ŀ�����ͷָ���βָ��ָ��ͷ���
  *           ��˳����е�Ԫ��˳�����Ԫ�ز������㣬���½�����tailָ��ĺ�ߣ��޸�tailָ���½��
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
  * @brief  ���õ�����
  * @desc   ����ͷ�巨�����ĵ���������Ԫ�ص�˳��������˳���෴�ġ� 
  *         1.p���η��ʵ������е�ÿ����㣬û����һ����㣬����������ͷ���֮��
  *         2.����ƶ�p��ֱ�����н��ȫ�����²��뵽������֮��
  *         3.ʱ�临�Ӷȣ�O(n)
  * @param  None
  * @retval None
  */
template<typename elemType>
void linkList<elemType>::inverse()
{
    Node* p, * tmp;
    p = head->next;
    head->next = NULL;                      // ͷ���ָ����Ϊ�գ����ɿ�����
    if (p)
        tail = p;                           // ���ú�ԭ������Ԫ�����Ϊβ���
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
    // �������ʼ��
    linkList<elemType>::linkList();
    linkList<elemType> list;

    // ͷ�巨��������
    list.headCreate();
    cout << "ͷ�巨��������";
    list.traverse();

    cout << "�������ã�";
    list.inverse();
    list.traverse();

    list.insert(2, 199);
    cout << "���������";
    list.traverse();

    cout << "����Ҫ���ҵ�Ԫ�أ�";
    cin >> value;
    cout << "Ԫ��" << value << "��λ��Ϊ��" << list.search(value) << endl;

    cout << "����Ҫ����Ԫ�ص�ǰ����";
    cin >> value;
    cout << "Ԫ��" << value << "��ǰ��λ��Ϊ��" << list.prior(value) << endl;

    cout << "����ɾ��Ԫ�ص�λ��";
    cin >> value;
    list.remove(value);
    list.traverse();

    // β�巨��������
    list.tailCreate();
    list.traverse();

    return 0;
}