#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
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

void push(char x)
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

char pop()
{
    char x = -1;
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

int isBalanced(char *exp)
{
    int i;
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
            push(exp[i]);
        else if (exp[i] == ')')
        {
            if (isEmpty())
                return 0;
            pop();
        }
    }
    return isEmpty() ? 1 : 0;
}
int main()
{
    char *exp = "((a+b)*(c-d))";

    printf("%d ", isBalanced(exp));
    return 0;
}