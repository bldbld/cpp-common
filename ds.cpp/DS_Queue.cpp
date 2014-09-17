// Queue Def
// ballad 2009 ?

struct ListNode
{
    int data;
    ListNode *link;
};

class Queue
{
private:
    ListNode *front, * rear;
    int curr_len;
public:
    Queue()
    {}
    ~Queue()
    {}
    void EnQueue(ELEM item);
    ELEM DeQueue();

};

void Queue::EnQueue(ELEM item)
{
    ListNode *temp;
    assert(!temp == NULL);
    temp->data = item;
    temp->link = NULL;
    if(rear != NULL)
    {
        rear->link = temp;
        rear = temp;
    }
    else
        front = rear = temp;
    curr_len++;
}
ELEM Queue::DeQueue()
{
    assert(!temp == NULL);
    ELEM result = front->data;
    ListNode# temp;
    temp = front;
    front = front->link;
    delete temp;
    curr__len--;
    if(curr_len == 0)
        rear = front = NULL;
    return result;
}