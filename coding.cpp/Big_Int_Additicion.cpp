#include <iostream>
#include <string.h>
#include <assert.h>

using namespace std;

// 特大数加法
// author ballad @ 2009 ?
template <class T>
class Stack
{
private:
    int top;
    T *List;
    int MaxSize;
public:
    Stack(int n = 50)
    {
        top = 0;
        MaxSize = n;
        List = new T[MaxSize];
    }

    bool isEmpty()
    {
        return (top == -1 || top == 0) ? true : false;
    }
    bool isFull()
    {
        return top == MaxSize ? true : false;
    }
    void push(T e)
    {
        //	assert(isFull());
        top++;
        List[top] = e;

    }
    T pop()
    {
        assert(!isEmpty());
        T p = List[top];
        top--;
        return p;

        //		delete p;
    }
    T gettop()
    {
        assert(!isEmpty());
        T q = List[top];
        return q;
    }

    ~Stack()
    {
        top = (MaxSize = -1);
    }
};

class Bigplus
{
private:
    Stack<int> S1;
    Stack<int> S2;
    Stack<int> S3;

public:
    Bigplus()
    {
        Stack<int> S1;
        Stack<int> S2;
        Stack<int> S3;
    }
    ~Bigplus()
    {
    }
    void plus();
    void getnum();
    void show();

};

void Bigplus::getnum()
{
    char c;
    while (cin >> c, c != '/')
    {
        S1.push(c - 48);
    }
    cout << "+" << endl;
    while (cin >> c, c != '/')
    {
        S2.push(c - 48);
    }
}

void Bigplus::plus()
{
    int a, k;
    k = 0;
    while (!S1.isEmpty() && !S2.isEmpty())
    {

        if(k < 10)
            a = S1.pop() + S2.pop();
        else
            a = S1.pop() + S2.pop() + 1;

        if(a >= 10)
            S3.push(a - 10);
        else
            S3.push(a);
        k = a;
        /*
        a=S1.pop()+S2.pop();
        if (a>=10){
        	a=a-10;
        	k=1;
        }
        if(k==1)
        S3.push(a);
        */
    }
    int i = 0;
    while (!S1.isEmpty())
    {
        if(i == 0 && k >= 10)
        {
            a = S1.pop() + 1;
        }
        else
            a = S1.pop();
        S3.push(a);
        i++;
    }
    while (!S2.isEmpty())
    {
        if(i == 0 && k >= 10)
        {
            a = S2.pop() + 1;
        }
        else
            a = S2.pop();

        S3.push(a);
        i++;
    }
}

void Bigplus::show()
{

    while(!S3.isEmpty())
    {
        cout << (S3.pop());
    }
    cout << endl;
}

int main ()
{
    Bigplus a1;
    a1.getnum();
    a1.plus();
    a1.show();
}
