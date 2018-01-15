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
typedef struct
{
	SElemType data[MAXSIZE];
	int top1;	/* 用于栈1顶指针*/
	int top2;   /* 用于栈2顶指针*/
}SqDoubleStack;

/* 插入元素 e 为新的栈顶元素*/
Status Push(SqDoubleStack *S, SElemType e, int stackNumber)
{
	if (S->top1 + 1 == S->top2)
		return ERROR;
	if (stackNumber == 1)
		S->data[++S->top1] = e;
	else if (stackNumber == 2)
		S->data[++S->top2] = e;
	return OK;
}

/* 若栈顶不为空， 则删除 S 的栈顶元素， 用 e 返回其值， 并返回 OK； 否则返回 ERROR*/
Status Pop(SqDoubleStack *S, SElemType *e, int stackNumber)
{
	if (stackNumber == 1)
	{
		if (S->top1 == -1)
			return ERROR;
		*e = S->data[S->top1--];
	}
	else if (stackNumber == 2)
	{
		if (S->top2 = MAXSIZE)
			return ERROR;
		*e = S->data[S->top2++];
	}
}