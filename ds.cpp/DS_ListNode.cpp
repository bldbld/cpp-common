#include <iostream>
using namespace std;

// List Def
// 2009 ? ballad 

struct ListNode
{
    int data;
    ListNode *link;
};
ListNode *first, *last;

ListNode *FindIndex (const int i)
{
    if(i == -1)
        return first;
    ListNode *p = first->link;
    int j = 0;
    while(p != NULL && j < i)
    {
        p = p->link;
        j++;
    }
    return p;
}

ListNode *Insert(int value, int i)
{
    ListNode *p, *q;
    q = new ListNode;
    p = FindIndex(i - 1);
    if(p == NULL) return NULL;
    q->link = p->link;
    q->data = value;
    p->link = q;
    if(q->link == NULL)
        last = q;
    return q;
}

void RemoveAfter(ListNode *ln)
{
    ListNode *newlink = ln->link;
    if (newlink != NULL)
    {
        ln->link = newlink->link;
        delete newlink;
    }
}

//2.2 (是当时的题目编号？)
ListNode *InsertIn(int a, int b)
{
    ListNode *p = first;
    int j = 0;
    while(p->data != a)
    {
        p = p->link;
        j++;
    }
    return Insert(b, j);
}

//2.3
ListNode *Invert(ListNode *head)
{
    ListNode *middle, *trail;
    middle = NULL;
    while(head)
    {
        trail = middle;
        middle = head;
        head = head->link;
        middle->link = trail;
    }
    return middle;
}

//2,7 应该包含向量定义
/*
int deleter(const int i)
{
	int j=0;
	int p=nodelist[i];
	for (j=i;j<curr_len;j++){
		nodelist[j]=nodelist[j+1];
	}
	curr_len--;
	return p;
}*/

int main ()
{
    first = new ListNode;
    last = new ListNode;
    first->link = last;
    int a;
    int i = 1;
    ListNode *p;
    cin >> a;
    while (a != 0)
    {
        p = Insert(a, i);
        cout << p->data << endl;
        i++;
        cin >> a;

    }
    //插入了i-1个
    p->link = last;
    p = first->link;
    ListNode *q;
    q = Invert(p);
    q = FindIndex(2);
    cout << q->data << endl;
    return 0;
}