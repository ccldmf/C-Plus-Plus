#include <iostream>

using namespace std;
typedef int elemType;

template <typename elemType>

class linkList 
{
private:
    struct Node                                         // �������
    {
        elemType data;                                  // ���������
        Node* next;                                     // ���ָ����
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

    Node* head;                                         // ����ͷ���
    Node* tail;                                         // ����β���
    int curLength;                                      // ������ǰ����
    Node* getPosition(int i) const;                     // ����ָ���i������ָ��

public:
    linkList();
    ~linkList();

    void clear();                                       // ��յ�����ʹ֮��Ϊ�ձ�
    bool empty() const {                                // �жϵ������Ƿ�Ϊ��
        return head->next == NULL;
    }
    int size() const {                                  // ���ص�����ǰ�ĳ���
        return curLength;   
    }

    void insert(int i, const elemType& value);          // λ��i������ֵΪvalue�Ľ�㣬����1
    void remove(int i);                                 // �Ƴ�λ��Ϊi���Ľ�㣬����1
    int search(const elemType& value) const;            // ����ֵΪvalue�Ľ���һ�γ��ֵ�λ��
    int prior(const elemType& value) const;             // ����ֵΪvalue�Ľ���ǰ����λ��
    void traverse() const;                              // ����������
    void headCreate();                                  // ͷ�巨����������
    void tailCreate();                                  // β�巨����������
    void inverse();                                     // ���õ�����
};
