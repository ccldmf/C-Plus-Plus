/**
  ******************************************************************************
  * @file    BinaryTree.cpp
  * @author  CC
  * @version V1.0.0
  * @date    03-02-2020
  * @brief   This file contains the binary tree module implementation.
  ******************************************************************************
  * @attention
  *
  * NULL
  *
  ******************************************************************************
  */

#include "BinaryTree.h"

#define MAX(a,b) ((a)>(b)?(a):(b))

int BT::heightSize(BTNode*N)
{
    if (NULL == N)
    {
        return 0;
    }
    else
    {
        return N->height;
    }
}

BT::BTNode* BT::newNode(int key)
{
    mBTNode = (BTNode*)malloc(sizeof(struct Node));
    mBTNode->key    = key;
    mBTNode->left   = NULL;
    mBTNode->right  = NULL;
    mBTNode->height = 1;
    return (mBTNode);
}

int BT::getBalance(BTNode*N)
{
    if (NULL == N)
    {
        return 0;
    }
    else
    {
        return heightSize(N->left) - heightSize(N->right);
    }
}

BT::BTNode* BT::minValueNode(BTNode* aNode)
{
    BTNode* theTemp = aNode;
    while (theTemp->left != NULL)
    {
        theTemp = theTemp->left;
    }
    return theTemp;
}

BT::BTNode* BT::LLRotate(BTNode* aNode)
{
    BTNode* theNode = aNode->left;
    aNode->left     = theNode->right;
    theNode->right  = aNode;

    aNode->height   = MAX(heightSize(aNode->left), heightSize(aNode->right)) + 1;
    theNode->height = MAX(heightSize(theNode->left), heightSize(theNode->right)) + 1;
    return theNode;
}

BT::BTNode* BT::RRRotate(BTNode* aNode)
{
    BTNode* theNode = aNode->right;
    aNode->right    = theNode->left;
    theNode->left   = aNode;
    
    aNode->height   = MAX(heightSize(aNode->left), heightSize(aNode->right)) + 1;
    theNode->height = MAX(heightSize(theNode->left), heightSize(theNode->right)) + 1;
    return theNode;
}

BT::BTNode* BT::Insert(BTNode* aNode, int key)
{
    if (NULL == aNode)
        return newNode(key);

    if (key < aNode->key)
    {
        aNode->left = Insert(aNode->left, key);
    }
    else if (key > aNode->key)
    {
        aNode->right = Insert(aNode->right, key);
    }
    else
    {
        return aNode;
    }

    aNode->height = 1 + MAX(heightSize(aNode->left),heightSize(aNode->right));

    int theBalance = getBalance(aNode);

    if (theBalance > 1 && key < aNode->left->key)         // LL
    {
        return LLRotate(aNode);
    }

    if (theBalance < -1 && key > aNode->right->key)       // RR
    {
        return RRRotate(aNode);
    }

    if (theBalance > 1 && key > aNode->left->key)         // LR
    {
        aNode->left = RRRotate(aNode->left);
        return LLRotate(aNode);
    }

    if (theBalance < -1 && key < aNode->right->key)        // RL
    {
        aNode->right = LLRotate(aNode->right);
        return RRRotate(aNode);
    }

    return aNode;
}

BT::BTNode* BT::Delete(BTNode* aNode,int key)
{
    if (NULL == aNode)
        return aNode;

    if (key < aNode->key)
    {
        aNode->left = Delete(aNode->left, key);
    }
    else if (key > aNode->key)
    {
        aNode->right = Delete(aNode->right, key);
    }
    else
    {
        if ((NULL == aNode->left) || (NULL == aNode->right))
        {
            BTNode* theTemp = aNode->left ? aNode->left : aNode->right;
            if (NULL == theTemp)
            {
                theTemp = aNode;
                aNode = NULL;
            }
            else
            {
                *aNode = *theTemp;
            }
            free(theTemp);
        }
        else
        {
            BTNode* theTemp = minValueNode(aNode->right);
            aNode->key = theTemp->key;
            aNode->right = Delete(aNode->right, theTemp->key);
        }
    }

    if (NULL == aNode)
        return aNode;

    aNode->height = 1 + MAX(heightSize(aNode->left), heightSize(aNode->right));

    int theBalance = getBalance(aNode);

    if (theBalance > 1 && getBalance(aNode->left) >= 0)      // LL
        return LLRotate(aNode);

    if (theBalance > 1 && getBalance(aNode->left) < 0)       // LR
    {
        aNode->left = RRRotate(aNode->left);
        return LLRotate(aNode);
    }

    if (theBalance < -1 && getBalance(aNode->right) <= 0)   // RR
        return RRRotate(aNode);

    if (theBalance < -1 && getBalance(aNode->right) > 0)    // RL
    {
        aNode->right = LLRotate(aNode->right);
        return RRRotate(aNode);
    }
    return aNode;
}

void BT::preOrder(BTNode* aNode)
{
    if (NULL != aNode)
    {
        cout<< aNode->key<<" ";
        preOrder(aNode->left);
        preOrder(aNode->right);
    }
}

void BT::printNode(void)
{
    preOrder(mBTNode);
}

void BT::insertNode(int key)
{
    mBTNode = Insert(mBTNode,key);
}

void BT::deleteNode(int key)
{
    mBTNode = Delete(mBTNode, key);
}

int main()
{
    BT theBT;

    theBT.insertNode(9);
    theBT.insertNode(5);
    theBT.insertNode(10);
    theBT.insertNode(0);
    theBT.insertNode(6);
    theBT.insertNode(11);
    theBT.insertNode(-1);
    theBT.insertNode(1);
    theBT.insertNode(2);
    cout << "前序遍历:" << endl;
    theBT.printNode();

    cout << endl;
    cout << "删除指定结点后前序遍历：" << endl;
    theBT.deleteNode(10);
    theBT.printNode();
    return 0;
}