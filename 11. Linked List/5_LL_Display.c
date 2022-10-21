#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

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
void create2(int A[], int n)
{
    int i;
    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;

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

// Inserting in a sorted Linked List
void SortedInsert(struct Node *p, int x)
{
    struct Node *t, *q = NULL;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (first == NULL)
        first = t;
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

/// Deleting from a linked list
int Delete(struct Node *p, int index)
{
    struct Node *q;
    int x = -1, i;
    if (index < 1 || index > count(p))
        return -1;
    if (index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }
}

int isSorted(struct Node *p)
{
    int x = INT_MIN;
    while (p != NULL)
    {
        if (p->data < x)
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}

void removeDuplicate(struct Node *p)
{
    struct Node *q = p->next;
    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

void Reverse1(struct Node *p)
{
    int *A, i = 0;
    struct Node *q = p;
    A = (int *)malloc(sizeof(int) * count(p));

    while (q != NULL)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;
    while (q != NULL)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }
}

void Reverse2(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;

    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void Reverse3(struct Node *q, struct Node *p)
{
    if (p != NULL)
    {
        Reverse3(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

void Concat(struct Node *p, struct Node *q)
{
    third = p;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
}

void Merge(struct Node *p, struct Node *q)
{
    struct Node *last;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }

    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p)
        last->next = p;
    if (q)
        last->next = q;
}
int main()
{
    /* int A[] = {3, 5, 7, 10, 15, 8, 12, 2};
    create(A, 8); */

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

     */

    /* Insert(first, 2, 11);
    printf("\n");
     */

    /* Insert(first, 0, 10);
    Insert(first, 1, 11);
    Insert(first, 2, 12);
    Insert(first, 3, 13);
    Insert(first, 4, 14); */

    /*  int A[] = {10, 20, 20, 20, 30, 40, 50, 50, 50};
     create(A, 9);
     Display(first);

     removeDuplicate(first); */

    /*  SortedInsert(first, 39);
     SortedInsert(first, 9); */
    // printf("Deleted Element : %d\n", Delete(first, 4));
    /*if (isSorted(first))
        printf("Sorted\n");
    else
        printf("Not Sorted\n"); */

    // int A[] = {10, 20, 30, 40, 50};
    // Reverse1(first);
    // Reverse2(first);
    // Reverse3(NULL, first);

    int A[] = {10, 20, 20, 40, 50};
    int B[] = {5, 15, 25, 35, 45};
    create(A, 5);
    create2(B, 5);
    /* Concat(second, first);
    printf("Concatinated\n");
    Display(third); */
    Merge(first, second);
    Display(third);
    return 0;
}