#include <iostream>

// Stack Def
// ballad 2009 ?

int main(int argc, char *argv[])
{
}

Template <class T>
    class Stack
    {
    private:
        int top;
        T *List;
        int MaxSize;
    public:
        Stack(int n = 10)
        {
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
            assert(isFull());
            List[top++] = e;

        }
        T get()
        {
            assert(!isEmpty());
            T *p = List[top];
            return p;
            top--;
            delete p;
        }
        T top()
        {
            assert(!isEmpty());
            T *p = List[top];
            return p;
            delete p;

        }
        ~Stack()
        {
            return top == MaxSize = -1;
        }
    };
