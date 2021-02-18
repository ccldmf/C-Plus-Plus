/**
  ******************************************************************************
  * @file    BinaryTree.h
  * @author  CC
  * @version V1.0.0
  * @date    03-02-2020
  * @brief   This file contains the headers of the binary tree module handlers.
  ******************************************************************************
  * @attention
  *
  * NULL
  *
  ******************************************************************************
  */
#include<iostream>

using namespace std;

class BT {
private:
    typedef struct Node 
    {
        int key;
        struct Node* left;
        struct Node* right;
        int height;
    }BTNode;

    BTNode* mBTNode = NULL;

    int heightSize(BTNode*);
    int getBalance(BTNode*);
    BTNode* newNode(int);
    BTNode* minValueNode(BTNode*);
    BTNode* Insert(BTNode*, int);
    BTNode* Delete(BTNode*, int);
    void preOrder(BTNode*);
    BTNode* LLRotate(BTNode*);
    BTNode* RRRotate(BTNode*);

public:
    void insertNode(int);
    void deleteNode(int);
    void printNode(void);
};
