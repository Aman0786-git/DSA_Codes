#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

/* // Using While Loop
void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
 */

// Using Recursion
void Display(struct Node *p)
{
    if (p != NULL)
    {                           // 1st printing then recursive call
        printf("%d ", p->data); // 3 5 7 10 15
        Display(p->next);
    }
}

void RDisplay(struct Node *p)
{
    if (p != NULL)
    { // 1st recursive call then printing
        RDisplay(p->next);
        printf("%d ", p->data); // 15 10 7 5 3
    }
}

int count(struct Node *p)
{
    int x = 0;
    while (p)
    {
        x++;
        p = p->next;
    }
    return x;
}

int rcount(struct Node *p)
{
    if (!p)
        return 0;
    return 1 + rcount(p->next); // Using Recursion
}

int rsum(struct Node *p)
{
    if (p == 0)
        return 0;
    else
        return rsum(p->next) + p->data;
}

int sum(struct Node *p)
{
    int x = 0;
    while (p)
    {
        x += p->data;
        p = p->next;
    }
    return x;
}

int main()
{
    int A[] = {3, 5, 7, 10, 15};

    create(A, 5);
    Display(first);
    // RDisplay(first);
    printf("\nNumber of Nodes are : %d", count(first));
    printf("\nSum of Nodes are : %d", sum(first));
    return 0;
}