int count(struct Node *p)
{
    if (!p)
        return 0;
    return 1 + count(p->next); // Using Recursion
}