#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *top = NULL;

int isEmpty()
{
    return top ? 0 : 1;
}

int isFull()
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    int r = t ? 1 : 0;
    free(t);
    return r;
}

void push(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
        printf("\nStack Overflow\n");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop()
{
    int x = -1;
    struct Node *t;
    if (isEmpty())
        printf("\nStack Underflow\n");
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

void Display()
{
    struct Node *p;
    p = top;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);

    Display();
    printf("%d \n", pop());
    return 0;
}