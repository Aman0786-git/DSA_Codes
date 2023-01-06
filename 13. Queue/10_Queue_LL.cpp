#include <iostream>
using namespace std;

struct Node
{

    int data;
    Node *next;
} *front = NULL, *rear = NULL;

void enqueue(int x)
{
    Node *t = new Node;
    if (t == NULL)
    {
        cout << "Queue is Full";
    }
    else
    {
        t->data = x;
        if (front == rear)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue()
{
    int x = -1;
    Node *p;
    if (front == NULL)
        cout << "Queue is Empty";
    else
    {

        p = front;
        front = front->next;
        x = p->data;
        delete p;
    }
    return x;
}

void Display()
{
    if (front == NULL)
        cout << "Queue is Empty";
    else
    {
        Node *p;
        p = front;
        while (p)
        {
            cout << p->data << " ";
            p = p->next;
        }
        delete p;
    }
}

int main()
{
    enqueue(19);
    enqueue(10);
    enqueue(29);
    Display();
    return 0;
}