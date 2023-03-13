// #include <iostream>
#include <stdio.h>
#include "QueueCpp.h"
using namespace std;

class Tree
{
public:
    Node *root;
    Tree()
    {
        root = NULL;
    }
    void createTree();
    void PreOrder(Node *p);
    void InOrder(Node *p);
    void PostOrder(Node *p);
    void LevelOrder(Node *p);
    int Height(Node *root);
};

void Tree::createTree()
{
    Node *p, *t;
    int x;
    Queue q(10);
    cout << "Enter Root Value:";
    cin >> x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);

    while (!q.isEmpty())
    {
        p = q.dequeue();
        printf("Enter Left Child of %d :", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }

        printf("Enter Right Child of %d : ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void Tree::PreOrder(Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        PreOrder(p->lchild);
        PreOrder(p->rchild);
    }
}

void Tree::InOrder(Node *p)
{
    if (p)
    {
        InOrder(p->lchild);
        cout << p->data << " ";
        InOrder(p->rchild);
    }
}

void Tree::PostOrder(Node *p)
{
    if (p)
    {
        PostOrder(p->lchild);
        PostOrder(p->rchild);
        cout << p->data << " ";
    }
}

int Tree::Height(Node *root)
{
    int x = 0, y = 0;
    if (root == 0)
        return 0;
    x = Height(root->lchild);
    y = Height(root->rchild);

    if (x > y)
        return x + 1;
    else
        return y + 1;
}

void Tree::LevelOrder(Node *root)
{
    Queue q(100);

    cout << root->data << " ";
    q.enqueue(root);

    while (!q.isEmpty())
    {
        root = q.dequeue();
        if (root->lchild)
        {
            cout << root->lchild->data << " ";
            q.enqueue(root->lchild);
        }
        if (root->rchild)
        {
            cout << root->rchild->data << " ";
            q.enqueue(root->rchild);
        }
    }
}

int main()
{
    Tree t;
    t.createTree();
    t.PreOrder(t.root);
    // t.InOrder(t.root);
    // t.PostOrder(t.root);

    return 0;
}