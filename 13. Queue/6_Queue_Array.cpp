#include <iostream>
using namespace std;

class Queue
{

private:
    int size;
    int front;
    int rear;
    int *Q;

public:
    Queue()
    {
        front = rear = -1;
        size = 5;
        Q = new int[size];
    }
    Queue(int size)
    {
        front = rear = -1;
        this->size = size;
        Q = new int[size];
    }

    void enqueue(int x);
    int dequeue();
    void display();
    bool isEmpty() { return front == rear ? true : false; }
    bool isFull() { return rear == size - 1 ? true : false; }
};

void Queue::enqueue(int x)
{
    if (isFull())
        cout << "Queue is Full\n";
    else
    {
        rear++;
        Q[rear] = x;
    }
}

int Queue::dequeue()
{
    int x = -1;
    if (isEmpty())
        cout << "Queue is Empty";
    else
    {
        front++;
        x = Q[front];
    }
    return x;
}

void Queue::display()
{
    for (int i = front + 1; i <= rear; i++)
        cout << Q[i] << " ";

    cout << endl;
}
int main()
{
    Queue q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.display();
    cout << q.dequeue() << endl;
    q.display();
    return 0;
}
