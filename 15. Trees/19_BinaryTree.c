#include <stdio.h>
#include <stdlib.h>
#include "queueC.h"
#include <stdbool.h>

int isEmpty(struct Queue q)
{
	return q.front == q.rear;
}

struct Node *root = NULL;

void treeCreate()
{
	struct Node *p, *t;
	int x;
	struct Queue q;
	create(&q, 100);
	printf("Enter Root Value: ");
	scanf("%d", &x);
	root = (struct Node *)malloc(sizeof(struct Node));
	root->data = x;
	root->lchild = root->rchild = NULL;
	enqueue(&q, root);

	while (!isEmpty(q))
	{
		p = dequeue(&q);
		printf("Enter Left Child of %d :", p->data);
		scanf("%d", &x);
		if (x != -1)
		{
			t = (struct Node *)malloc(sizeof(struct Node));
			t->data = x;
			t->lchild = t->rchild = NULL;
			p->lchild = t;
			enqueue(&q, t);
		}

		printf("Enter Right Child of %d : ", p->data);
		scanf("%d", &x);
		if (x != -1)
		{
			t = (struct Node *)malloc(sizeof(struct Node));
			t->data = x;
			t->lchild = t->rchild = NULL;
			p->rchild = t;
			enqueue(&q, t);
		}
	}
}

void prorder(struct Node *p)
{
	if (p)
	{
		printf("%d ", p->data);
		prorder(p->lchild);
		prorder(p->rchild);
	}
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

void postOrder(struct Node *p)
{
	if (p)
	{
		postOrder(p->lchild);
		postOrder(p->rchild);
		printf("%d ", p->data);
	}
}

int count(struct Node *root )
{
	if (root)
		return count(root->lchild) + count(root->rchild) + 1;
	return 0;
}

int height(struct Node *root)
{
	int x, y;
	x = y = 0;
	if (root == 0)return 0;
	x = height(root->lchild);
	y = height(root->rchild);
	if (x > y)
		return x + 1;
	else
		return y + 1;
}

int cntleafNode(struct Node *root )
{
	int x, y;
	x = y = 0;
	if (root)
	{
		x = cntleafNode(root->lchild);
		y = cntleafNode(root->rchild);
		if (root->lchild == NULL && root->rchild == NULL)
			return x + y + 1;
		else
			return x + y;
	}
	return 0;
}
int main()
{
	treeCreate();
	printf("PreOrder Traversal: ");
	prorder(root);
	printf("\nInOrder Traversal: ");
	Inorder(root);
	printf("\nPostOrder Traversal: ");
	postOrder(root);
	printf("\n");
	return 0;
}