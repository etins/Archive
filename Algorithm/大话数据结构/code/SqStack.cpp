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
	int top;	/* 用于栈顶指针*/
}SqStack;

/* 插入元素 e 为新的栈顶元素*/
Status Push(SqStack *S, SElemType e)
{
	if (S->top == MAXSIZE - 1)
		return ERROR;
	S->top++;				/* 栈顶指针加1*/
	S->data[S->top] = e;    /* 将新元素赋值给栈定空间*/
	return OK;
}

/* 若栈顶不为空， 则删除 S 的栈顶元素， 用 e 返回其值， 并返回 OK； 否则返回 ERROR*/
Status Pop(SqStack *S, SElemType *e)
{
	if (S->top == -1)
		return ERROR;
	*e = S->data[S->top];
	S->top--;
	return OK;
}