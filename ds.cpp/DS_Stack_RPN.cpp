#include <iostream>
#include <assert.h>

using namespace std;

// ջ & �沨��ʽ
// �沨��ʽ��Reverse Polish notation��RPN�����沨���Ƿ�����Ҳ�к�׺���ʽ���������д�ڲ�����֮��
// ballad 2009 ?
// VS 2005
template <class T>
class Stack
{
private:
    int top; //?ò�������� ���Զ���ȫ�ֱ���
    T *List;
    int MaxSize;
public:
    Stack(int n = 10)
    {
        top = 0;
        MaxSize = n;
        List = new T[MaxSize];
    }

    bool isEmpty()
    {
        return top == -1 ? true : false;
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

//��׺���ʽ�ļ���
class Calculator
{
private:
    Stack <int> S;
    int a1, a2;
public:
    Calculator ()
    {

    }
    void Enter(int x);
    void Run();
    void Compute(char a);
    void Calculator::Clear()
    {
        S.~Stack();
    }
    ~Calculator()
    {

    }
};

void Calculator::Run()
{
    char c;
    int x;
    while (cin >> c, c != '=')
    {
        if (c >= '0' && c <= '9')
        {
            x = c - 48;
            S.push(x);
        }
        else
            Compute(c);
        /*
        switch(c){
        	case'+':case'-':case'*':case'/':case'%':
        		Compute(c);
        		break;

        	default:
        		cin.putback(c);//�Ż�ȥ��ʲô�ã�
        		cin>>x;
        		S.push(x);
        		break;


        }
        if (!S.isEmpty())
        {
        	cout<<S.gettop()<<endl;
        }
        */
    }
    if(c == '=')
        cout << S.gettop() << endl;
}

void Calculator::Compute(char c)
{
    int re;
    //	int x;

    a1 = S.pop();
    a2 = S.pop();

    if (1)
    {
        switch(c)
        {
        case'+':
            re = a1 + a2;
            break;
        case'-':
            re = a2 - a1;
            break;
        case'*':
            re = a2 * a1;
            break;
        case'/':
            if(a1 == 0)
            {
                cout << "ERROR" << endl;
                S.~Stack();
            }
            else re = a2 / a1;
            break;
        case'%':
            if(a1 == 0)
            {
                cout << "ERROR" << endl;
                S.~Stack();
            }
            else
                re = (a2) % (a1);
            break;
        }

    }
    S.push(re);
}

int main()
{
    Calculator C1;
    C1.Run();
    return 0;
}
