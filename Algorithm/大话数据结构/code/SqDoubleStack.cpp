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
typedef struct
{
	SElemType data[MAXSIZE];
	int top1;	/* ����ջ1��ָ��*/
	int top2;   /* ����ջ2��ָ��*/
}SqDoubleStack;

/* ����Ԫ�� e Ϊ�µ�ջ��Ԫ��*/
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

/* ��ջ����Ϊ�գ� ��ɾ�� S ��ջ��Ԫ�أ� �� e ������ֵ�� ������ OK�� ���򷵻� ERROR*/
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