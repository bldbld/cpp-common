#include <iostream>
#include <tchar.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <fstream>

using namespace std;


// Tree Travel
// ballad 2009 ?

class BinTreeNode
{
public:
    friend class BinTree;
    BinTreeNode()
    {}
    BinTreeNode(char elem, BinTreeNode *lchild = NULL, BinTreeNode *rchild = NULL)
    {
        element = elem;
        left = lchild;
        right = rchild;
    }

    char element;
    BinTreeNode *left;
    BinTreeNode *right;
};

//¶þ²æÊ÷
class BinTree
{
public:
    BinTree() {}
    BinTree(BinTreeNode r)
    {
        root = &r;
    }
    BinTree(char elem)
    {
        root = new BinTreeNode(elem, NULL, NULL);
    }
    BinTree::~BinTree()

    {
    }
    void PreOrder(BinTreeNode *root)
    {
        if(root != NULL)
        {
            cout << root->element;
            PreOrder(root->left);
            PreOrder(root->right);
        }
    }

    //private:
    BinTreeNode *root;
};

void pm_order(BinTreeNode &A, char p[], char q[], int ps, int qs, int LEN)
{
    int i;
    int k = 0;
    if(LEN == 0)
        A = NULL;
    else
        for(i = 0; i < 3; i++) ///////////////
            if(q[i] == p[ps])
                k = i;
    //	A=new BinTreeNode;
    A.element = p[ps];
    if (k == qs) //
        A.left = NULL;
    else
    {
        BinTreeNode B;
        A.left = &B;

        pm_order(*A.left, p, q, ps + 1, qs, k - qs );
    }
    if (k == qs + LEN - 1)
        A.right = NULL;
    else
    {
        BinTreeNode C;
        A.right = &C;

        pm_order(*A.right, p, q, ps + 1 + (k - qs), k + 1, LEN - (k - qs) - 1);
    }
}

void text1(int length)
{
    char *p, *q;
    p = new char[length + 1];
    q = new char[length + 1];
    int i;
    for(i = 0; i < length; i++)
        cin >> p[i];
    p[length] = '\0';
    for(i = 0; i < length; i++)
        cin >> q[i];
    q[length] = '\0';
    BinTreeNode A;
    int ps = 0, qs = 0;
    pm_order(A, p, q, ps, qs, length);
    BinTree T(A);
    T.PreOrder(T.root);

}
int main()
{
    int length;

    cin >> length;
    text1(length);


    return 0;
}