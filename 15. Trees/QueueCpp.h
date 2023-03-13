#include <iostream>
using namespace std;

#ifndef QueueCpp_h
#define QueueCpp_h

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
};

class Queue
{
private:
    int front;
    int rear;
    int size;
    Node **Q;

public:
    Queue()
    {
        front = rear = -1;
        size = 10;
        Q = new Node *[size];
    }
    Queue(int size)
    {
        front = rear = -1;
        this->size = size;
        Q = new Node *[this->size];
    }
    void enqueue(Node *x);
    Node *dequeue();
    int isEmpty() { return front == rear; };
    void display();
};

void Queue::enqueue(Node *x)
{
    if (rear == size - 1)
        cout << "Queue is Full\n";
    else
    {
        rear++;
        Q[rear] = x;
    }
}

Node *Queue::dequeue()
{
    Node *x = NULL;
    if (front == rear)
        cout << "Queue is Empty\n";
    else
    {
        x = Q[front + 1];
        front++;
    }
    return x;
}

void Queue::display()
{
    for (int i = front + 1; i <= rear; i++)
        cout << Q[i] << " ";
    cout << "\n";
}

#endif