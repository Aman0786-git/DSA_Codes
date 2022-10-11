#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

int Max(struct Node *p)
{
    int max_so_far = INT_MIN;
    while (p)
    {
        if (p->data > max_so_far)
            max_so_far = p->data;

        p = p->next;
    }
    return max_so_far;
}

int Rmax(struct Node *p)
{
    int x = 0;
    if (p == 0)
        return INT_MIN;

    x = Rmax(p->next);
    return x > p->data ? x : p->data;
}

// Liner Search -> Iterative Version
struct Node *Lsearch(struct Node *p, int key)
{
    while (p != NULL)
    {
        struct Node *q;
        if (key == p->data)
        {
            q->next = p->next; // Improving Linear Srch
            p->next = first;   // Moving to head
            first = p;         // code
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

// Linear Search
struct Node *RLsearch(struct Node *p, int key)
{
    if (p == NULL)
        return NULL;
    if (key == p->data)
        return p;
    return RLsearch(p->next, key);
}

void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;
    if (index < 0 || index > count(p))
        return;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (i = 0; i < index - 1 && p; i++)
            p = p->next;

        t->next = p->next;
        p->next = t;
    }
}
int main()
{
    int A[] = {3, 5, 7, 10, 15, 8, 12, 2};
    create(A, 8);

    /* int A[] = {3, 5, 7};
    create(A, 3);
 */
    // Display(first);
    // RDisplay(first);
    // printf("\nNumber of Nodes are : %d", count(first));
    // printf("\nSum of Nodes are : %d", sum(first));
    // printf("\nMaximum is : %d", max(first));
    /*  struct Node *temp;
     temp = Lsearch(first, 2);
     temp = Lsearch(first, 8);
     // temp = RLsearch(first, 23);
     if (temp)
         printf("\nKey is found %d\n", temp->data);
     else
         printf("\nKey Not Found\n");

     Display(first); */

    /* Insert(first, 2, 11);
    printf("\n");
    Display(first); */

    /* Insert(first, 0, 10);
    Insert(first, 1, 11);
    Insert(first, 2, 12);
    Insert(first, 3, 13);
    Insert(first, 4, 14); */
    Display(first);
    return 0;
}