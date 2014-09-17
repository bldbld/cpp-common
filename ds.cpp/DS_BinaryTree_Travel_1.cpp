#define EL 10
#define TEL 2*EL+1
#define LEN sizeof(struct node)
#include "stdio.h"
#include "stdlib.h"

char pre[TEL] = "ABCDEFGHIJ";
char pin[TEL] = "CBEDAGHFJI";

// Tree Travel
// ballad 2009 ?

typedef struct node
{
    char data;
    struct node *lch, *rch;
} BTNode, *BTree;
BTNode root;
BTree rt = &root;

int pos(char c, char s[], int st)
{
    char *p;
    p = s + st;
    while(*p != c && *p != '\0') p++;
    return p - s;
}

void create(BTree *t, int i1, int i2, int len)
{
    int r, llen, rlen;
    if(len <= 0) *t = NULL;
    else
    {
        *t = (BTree)malloc(LEN);
        (*t)->data = pre[i1];
        r = pos(pre[i1], pin, i2);
        llen = r - i2;
        rlen = len - (llen + 1);
        create(&(*t)->lch, i1 + 1, i2, llen);
        create(&(*t)->rch, i1 + llen + 1, r + 1, rlen);
    }
}

void travel(BTree t)
{
    if(t)
    {
        travel(t->lch);
        travel(t->rch);
        putchar(t->data);
    }
}

int main()
{
    create(&rt, 0, 0, EL);
    if(rt) travel(rt);
}
