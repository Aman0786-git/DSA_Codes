#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int stackTop()
{
    if (top == NULL)
        return -1;
    else
        return top->data;
}

int isAllBalanced(char *exp)
{
    int i;
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == 40 || exp[i] == 91 || exp[i] == 123)
            push(exp[i]);
        else if (exp[i] == 41 || exp[i] == 93 || exp[i] == 125)
        {
            if ((exp[i] > 39 && exp[i] < 42 && exp[i] - stackTop() == 1) || (exp[i] > 90 && exp[i] < 94 && exp[i] - stackTop() == 2) || (exp[i] > 122 && exp[i] < 126 && exp[i] - stackTop() == 2))
            {
                if (isEmpty())
                    return 0;
                pop();
            }
        }
    }
    return isEmpty() ? 1 : 0;
}

int pre(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '/' || x == '*')
        return 2;

    return 0;
}

int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}

char *InToPost(char *infix)
{
    int i = 0, j = 0;
    char *postfix;
    int len = strlen(infix);
    postfix = (char *)malloc((len + 2) * sizeof(char));

    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if (pre(infix[i]) > pre(top->data))
                push(infix[i++]);
            else
                postfix[j++] = pop();
        }
    }
    while (top != NULL)
        postfix[j++] = pop();
    postfix[j] = '\0';

    return postfix;
}

int main()
{
    /* // char *exp = "{([a+b]*[c-d])}";
    // printf("%d \n", '(');
    // printf("%d \n", isBalanced(exp));
    // printf("%d \n", isAllBalanced(exp)); */

    char *infix = "a+b-c*d-e+f/g";
    push('#');
    char *postfix = InToPost(infix);

    printf("%s\n", postfix);
    return 0;
}