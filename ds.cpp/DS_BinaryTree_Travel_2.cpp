char c1[11] = "ABCDEFGHIJ";
char c2[11] = "CBEDAGHFJI";

// Tree Travel
// ballad 2009 ?
class Node
{
public:
    Node *right, *left;
    char data;
    Node()
    {}
    ~Node()
    {}
};
int pos(char c, char s[], int st)
{
    char *p;
    p = s + st;
    while(*p != c && *p != '\0') p++;
    return p - s;
}
void prein(Node *t, int i1, int i2, int len)
{
    int r, llen, rlen;
    if(len <= 0)
        t = NULL;
    else
    {
        t = new Node;
        (*t).data = c1[i1];
        r = pos(c1[i1], c2, i2);
        llen = r - i2;
        rlen = len - (llen + 1);
        prein((*t).left, i1 + 1, i2, llen);
        prein((*t).right, i1 + llen + 1, r + 1, rlen);
    }

}

void travel(Node *t)
{
    if(t)
    {
        travel((*t).left);
        travel((*t).right);
        putchar((*t).data);
    }
}

void main ()
{
    Node *t1;
    prein(t1, 0, 0, 10);
    travel(t1);

}