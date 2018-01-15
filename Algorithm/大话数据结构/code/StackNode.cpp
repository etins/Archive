#include <stdio.h>
#include <iostream>
#include <ctime>

#define MAXSIZE 20		/*存储空间初始分配量*/
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int SElemType; /* SElemType 类型次数假设为 int*/
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

/* 插入元素 e 为新的栈顶元素*/
Status Push(LinkStack *S, SElemType e)
{
	LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
	s->data = e;
	s->next = S->top;
	S->top = s;
	S->count++;
	return OK;
}

/* 若栈顶不为空，删除S的栈顶元素，用e返回其值*/
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