#include <iostream>

using namespace std;
typedef int elemType;

template <typename elemType>

class linkList 
{
private:
    struct Node                                         // 结点类型
    {
        elemType data;                                  // 结点数据域
        Node* next;                                     // 结点指针域
        Node(const elemType value, Node* p = NULL)
        {
            data = value;
            next = p;
        }

        Node(Node* p = NULL)
        {
            next = p;
        }
    };

    Node* head;                                         // 链表头结点
    Node* tail;                                         // 链表尾结点
    int curLength;                                      // 单链表当前长度
    Node* getPosition(int i) const;                     // 返回指向第i个结点的指针

public:
    linkList();
    ~linkList();

    void clear();                                       // 清空单链表，使之成为空表
    bool empty() const {                                // 判断单链表是否为空
        return head->next == NULL;
    }
    int size() const {                                  // 返回单链表当前的长度
        return curLength;   
    }

    void insert(int i, const elemType& value);          // 位序i处插入值为value的结点，表长加1
    void remove(int i);                                 // 移除位序为i处的结点，表长减1
    int search(const elemType& value) const;            // 查找值为value的结点第一次出现的位序
    int prior(const elemType& value) const;             // 查找值为value的结点的前驱的位序
    void traverse() const;                              // 遍历单链表
    void headCreate();                                  // 头插法建立单链表
    void tailCreate();                                  // 尾插法建立单链表
    void inverse();                                     // 逆置单链表
};
