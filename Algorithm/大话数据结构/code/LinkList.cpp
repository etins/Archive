#include <stdio.h>
#include <iostream>
#include <ctime>

#define MAXSIZE 20		/*存储空间初始分配量*/
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int ElemType;	/*int类型*/

typedef struct Node
{
	ElemType data;
	struct Node *next;
};
typedef struct Node *LinkList;

Status GetElem(LinkList L, int i, ElemType *e)
{
	int j;
	LinkList p;
	p = L->next;
	j = 1;
	while (p && j < i)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
		return ERROR;
	*e = p->data;
	return OK;
}

Status LinstInsert(LinkList *L, int i, ElemType e)
{
	int j;
	LinkList p, s;
	p = *L;
	j = 1;
	while (p && j < i)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
		return ERROR;
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

Status ListDelete(LinkList *L, int i, ElemType *e)
{
	int j;
	LinkList p, q;
	p = *L;
	j = 1;
	while (p->next && j < i)
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i)
		return ERROR;
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	return OK;
}

/* 随机产生 n 个元素的值，建立带头结点的单链线性表L（头插法）*/
void CreateListHead(LinkList *L, int n)
{
	LinkList p;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		p->next = (*L)->next;
		(*L)->next = p;
	}
}

/* 随机产生 n 个元素的值，建立带头结点的单链线性表L（尾插法）*/
void CreateListTail(LinkList *L, int n)
{
	LinkList p;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	for (i = 0; i < n; i++)
	{
		p = (Node *)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		(*L)->next = p;
		(*L) = p;
	}
	(*L)->next = NULL;
}

/* 初始条件：顺序线性表 L 已存在，操作结果：将 L 重置为空表 */
Status ClearList(LinkList *L)
{
	LinkList p, q;
	p = (*L)->next;
	while (p)
	{
		q = p->next;
		free(q);
		p = q;
	}
	(*L)->next = NULL;
	return OK;

}
