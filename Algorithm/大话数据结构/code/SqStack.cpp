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
	int top;	/* ����ջ��ָ��*/
}SqStack;

/* ����Ԫ�� e Ϊ�µ�ջ��Ԫ��*/
Status Push(SqStack *S, SElemType e)
{
	if (S->top == MAXSIZE - 1)
		return ERROR;
	S->top++;				/* ջ��ָ���1*/
	S->data[S->top] = e;    /* ����Ԫ�ظ�ֵ��ջ���ռ�*/
	return OK;
}

/* ��ջ����Ϊ�գ� ��ɾ�� S ��ջ��Ԫ�أ� �� e ������ֵ�� ������ OK�� ���򷵻� ERROR*/
Status Pop(SqStack *S, SElemType *e)
{
	if (S->top == -1)
		return ERROR;
	*e = S->data[S->top];
	S->top--;
	return OK;
}