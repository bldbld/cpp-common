#include <iostream>
#include <string.h>
#include <assert.h>

using namespace std;

// 使用栈进行分隔符匹配
// ballad 2009 ?

// 栈的定义
int top;
template <class T>
class Stack
{
private:
    //int top;
    T *List;
    int MaxSize;
public:
    Stack(int n = 100)
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
        //		assert(!isEmpty());
        T p = List[top];
        top--;
        return p;
        //		delete p;
    }
    T gettop()
    {
        //		assert(!isEmpty());
        T q = List[top];
        return q;
    }

    ~Stack()
    {
        top = (MaxSize = -1);
    }
};

class Bracket
{
private:
    Stack <char> S1;
    Stack <char> S2;
    Stack <char> S3;
    bool pan;
public:
    Bracket()
    {
        Stack <char> S1;
        Stack <char> S2;
        Stack <char> S3;
    }
    ~Bracket()
    {

    }
    void Run();
};

void Bracket::Run()
{
    pan = true;
    char c, x;
    while (cin >> c, c != '=')
    {
        switch(c)
        {
        case'(':
            S1.push(c);
            break;

        case')':
        {
            if(S1.gettop() == '(')
                S1.pop();
            else
                pan = false;
        }
        break;

        case'{':
            S2.push(c);
            break;

        case'}':
        {
            if(S2.gettop() == '{')
                S2.pop();
            else
                pan = false;
        }
        break;

        case'/':
        {
            if(S3.gettop() == '*')
            {
                x = S3.pop();
                if(S3.pop() == '*')
                {
                    if(S3.pop() == '/')
                        pan = true;
                    else
                        pan = false;
                }
                else
                    pan = false;
            }
            else if(S3.gettop() == '/')
            {
                S3.push(c);

            }
            else
                S3.push(c);
        }
        /*
        cin>>x;
        if(x=='*'){
        	S3.push(c);
        	S3.push(x);
        }
        	}
        	*/
        break;

        case'*':
        {
            if(S3.gettop() == '/' || S3.gettop() == '*')
            {
                S3.push(c);
            }

        }
        /*
        else if(S3.gettop()=='*') {
        	x=S3.pop();
        	if(S3.pop()=='*'){
        		if(S3.pop()=='/')
        			pan=true;
        		else
        			pan=false;
        	}
        	else
        		pan=false;
        */
        break;
        }
    }
    if(S2.gettop() == '{' || S1.gettop() == '(')
        pan = false;

    if(S3.gettop() == '*')
    {

        S3.pop();
        if(S3.gettop() == '/')
            pan = false;
    }

    if(c == '=')
    {
        if (pan == true)
            cout << "Ok" << endl;
        if (pan == false)
            cout << "No" << endl;
    }
}

int main()
{
    Bracket C1;
    C1.Run();
    return 0;
}