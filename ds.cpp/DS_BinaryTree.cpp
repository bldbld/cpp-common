#include <iostream>
#include <tchar.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <fstream>

using namespace std;

// 二叉树
// ballad 2009 ?

// 二叉树 基本 结点
template <class T>
class BinaryTreeNode
{
private:
    BinaryTreeNode <T> *left;
    BinaryTreeNode <T> *right;
    T element;
public:
    BinaryTreeNode()
    {}
    BinaryTreeNode()
    {}
    BinaryTreeNode()
    {}
    ~BinaryTreeNode()
    {}
    T value() const;
    BinadyTreeNode<T> *leftchild() const;
    BinadyTreeNode<T> *righrchild() const;
    void setLeftchild(BinadyTreeNode<T> *);
    void setRighrchild(BinadyTreeNode<T> *);
    void setValue(constT &val);
    bool isLeaf() const;
    BinadyTreeNode<T> &operator(const BinaryTreeNode<T> &Node);
};

//二叉树 类定义 基本
template <class T>
class BinaryTree
{
private:
    BinadyTreeNode<T> *root;
    BinadyTreeNode<T> *GetParent(BinadyTreeNode<T> *current);
public:
    BinaryTree()
    {}
    ~BinaryNode()
    {}
    bool isEmpty();
    BinadyTreeNode<T> *Root()
    {
        return root;
    }

    BinaryTreeNode<T> *GetParent(BinaryTreeNode<T> *root, BinaryTreeNode<T> current);
    BinadyTreeNode<T> *Parent(BinadyTreeNode<T> *current);
    BinadyTreeNode<T> *LeftSibling(BinadyTreeNode<T> *current);
    BinadyTreeNode<T> *RightSibling(BinadyTreeNode<T> *current);


    void CreateTree(constT &elem, BinadyTreeNode<T> &leftTree, BinadyTreeNode<T> &rightTree);

    //遍历
    void LeverOrder(BinadyTreeNode<T> *root;);//广度遍历

    void PreOrder(BinadyTreeNode<T> *root);//前序
    void InOrder(BinadyTreeNode<T> *root);//中序
    void PostOrder(BinadyTreeNode<T> *root);//后序

    void PreOrder_C(BinadyTreeNode<T> *root);//前序 非递归
    void InOrder_C(BinadyTreeNode<T> *root);//中序 非递归
    void PostOrder_C(BinadyTreeNode<T> *root);//后序 非递归

    void DeleteBinaryTree(BinadyTreeNode<T> *root);
};

template <class T>
void BinaryTree::PreOrder(BinadyTreeNode<T> *root)
{
    if(root != root)
    {
        Visit(root);
        PreOrder(root->leftchild());
        PreOrder(root->rightchild());
    }
}
template <class T>
void BinaryTree::InOrder(BinadyTreeNode<T> *root)
{
    if(root != root)
    {
        InOrder(root->leftchild());
        Visit(root);
        InOrder(root->rightchild());
    }
}
template <class T>
void BinaryTree::PostOrder(BinadyTreeNode<T> *root)
{
    if(root != root)
    {
        PostOrder(root->leftchild());
        PostOrder(root->rightchild());
        Visit(root);
    }
}

template <class T>
bool BinaryTreeNode::isEmpty()const
{
    return((root) ? false : true);
}

template <class T>
BinaryTreeNode<T> *BinaryTree::GetParent(BinaryTreeNode<T> *root, BinaryTreeNode<T> current)
{
    BinaryTreeNode<T> temp;
    if(rot == NULL)
        return NULL;
    if((root->leftchild() == current) || (root->rightchild() == current))
        return root;
    if((temp = GetParent(root->leftchild(), current)) != NULL)
        return temp;
    else
        return GetParent(root->leftchild(), current);
}

template <class T>
BinaryTreeNode<T> *BinaryTree::Parent(BinadyTreeNode<T> *current)
{
    if((current == NULL) || (current == root))
        return NULL;
    return GetParent(root, current);
}

template <class T>
BinaryTreeNode<T> *BinaryTree::LeftSibling(BinadyTreeNode<T> *current)
{
    if(current)
    {
        BinaryTreeNode<T> *temp = Parent(current);
        if((temp == NULL) || current == temp->leftchild())
            return NULL;
        else return temp->leftchild();
    }
    return NULL;
}

template <class T>
BinaryTreeNode<T> *BinaryTree::RightSibling(BinadyTreeNode<T> *current)
{
    if(current)
    {
        BinaryTreeNode<T> *temp = Parent(current);
        if((temp == NULL) || current == temp->rightchild())
            return NULL;
        else return temp->rightchild();
    }
    return NULL;
}

template <class T>
void BinaryTree::CreateTree(constT &elem, BinadyTreeNode<T> &leftTree, BinadyTreeNode<T> &rightTree)
{
    root = new BinaryTreeNode<T> (elem, leftTree.root, rightTree.root);
    leftTree.rot = rightTree.root = NULL;
}

void BinadyTree<T>::DeleteBinaryTree(BinaryTreeNode<T> *root)
{
    if (root)
    {
        DeleteBinaryTree(root->left);
        DeleteBinaryTree(root->right);
        delete root;
    }
}

//穿线二叉树 未完成
template <class T>
class ThreadBinaryTreeNode
{
private:
    int lTag, rTag; //左右标志位
    ThreadBinaryTreeNode<T> *left, *right; //线索或左右子树
    T element;
public:
    ThreadBinaryTreeNode();
    ThreadBinaryTreeNode(const T): element(T), left(NULL), right(NULL), lTag(), rTag() {};
    T &value()const
    {
        return element;
    }
    ThreadBinaryTreeNode<T> *leftchild() const;
    ThreadBinaryTreeNode<T> *righrchild() const;
    void setLeftchild(ThreadBinaryTreeNode<T> *);
    void setRighrchild(ThreadBinaryTreeNode<T> *);
    void setValue(constT &val);
    //没写完
};

template <class T>
class ThreadBinaryTree
{
private:
    ThreadBinaryTreeNode<T> *root;//根结点指针
public:
    ThreadBinaryTree(ThreadBinaryTreeNode<T> *p = NULL)
    {
        root = p;
    };//构造函数
    ~ThreadBinaryTree()
    {
        DeleteTree(root);
    };
    //返回根结点指针
    ThreadBinaryTreeNode<T> *getroot()
    {
        return root;
    };
    //中序线索化二叉树
    void InThread(ThreadBinaryTreeNode<T> *root);
    //中序周游
    void InOrder(ThreadBinaryTreeNode<T> *root);
};

template <class T>
void ThreadBinaryTree<T>::InThread(
    ThreadBinaryTreeNode<T> *root, ThreadBinaryTreeNode<T> *&pre)
{
    if(root != NULL)
    {
        InThread(root->left, pre); //中序线索化左子树
        if( root->left == NULL)
        {
            root->left = pre;
            if(pre) root->lTag = 1; 	 //建立前驱线索 }
            if((pre) && (pre->right == NULL))
            {
                pre->right = root;
                pre->rTag = 1; //建立后继线索}
                pre = root;
                InThread(root->right, pre); //中序线索化右子树
            }//end if
        }
    }
};
