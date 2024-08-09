#include <stdio.h>
#include<stdlib.h>
struct Node {
	struct Node *lchild;
	int data;
	struct Node *rchild;
}*root = NULL;


void Insert(int key)
{
	struct Node *t = root;
	struct Node *r, *p;

	if (root == NULL) {
		p = (struct Node *)malloc(sizeof(struct Node));
		p->data = key;
		p->lchild = p->rchild = NULL;
		root = p;
		return;
	}
	while (t != NULL)
	{
		r = t;
		if (key < t->data)
			t = t->lchild;
		else if (key > t->data)
			t = t->rchild;
		else
			return;
	}
	p = (struct Node *)malloc(sizeof(struct Node));
	p->data = key;
	p->lchild = p->rchild = NULL;

	if (key < r->data)r->lchild = p;
	else
		r->rchild = p;
}

struct Node *Search(int key)
{
	struct Node *t = root;
	while (t != NULL)
	{
		if (key == t->data)
			return t;
		else if (key < t->data)
			t = t->lchild;
		else
			t = t->rchild;
	}
	return NULL;
}

void Inorder(struct Node *p)
{
	if (p)
	{
		Inorder(p->lchild);
		printf("%d ", p->data);
		Inorder(p->rchild);

	}
}
int main()
{
	struct Node *p;
	Insert(10);
	Insert(5);
	Insert(11);
	Insert(9);
	Insert(22);
	Insert(20);
	Insert(2);

	Inorder(root);
	printf("\n");
	p = Search(222);
	if (p != NULL)
		printf("Element %d Found ", p->data);
	else
		printf("Element %d is not Found", p->data);

	return 0;
}