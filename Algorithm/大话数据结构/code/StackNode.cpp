#include <stdio.h>
#include <iostream>
#include <ctime>

#define MAXSIZE 20		/*�洢�ռ��ʼ������*/
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int SElemType; /* SElemType ���ʹ�������Ϊ int*/
typedef struct StackNode
{
	SElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef struct LinkStack
{
	LinkStackPtr top;
	int count;
}LinkStack;

/* ����Ԫ�� e Ϊ�µ�ջ��Ԫ��*/
Status Push(LinkStack *S, SElemType e)
{
	LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
	s->data = e;
	s->next = S->top;
	S->top = s;
	S->count++;
	return OK;
}

/* ��ջ����Ϊ�գ�ɾ��S��ջ��Ԫ�أ���e������ֵ*/
Status Pop(LinkStack *S, SElemType *e)
{
	LinkStackPtr p;
	if (S->count == 0)
		return ERROR;
	*e = S->top->data;
	p = S->top;
	S->top = S->top->next;
	free(p);
	S->count--;
	return OK;
}