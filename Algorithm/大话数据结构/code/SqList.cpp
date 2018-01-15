#include <stdio.h>
#include <iostream>

#define MAXSIZE 20		/*存储空间初始分配量*/
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int ElemType;	/*int类型*/

typedef struct
{
	ElemType data[MAXSIZE];	/*数组存储数据元素的最大值*/
	int length;				/*线性表当前长度*/
}SqlList;

void InitList(SqlList *L)
{
	L->length = 0;
}
Status ListEmpty(SqlList L)
{
	if (L.length == 0)
		return TRUE;
	else
		return FALSE;
}
void ClearList(SqlList *L)
{
	L->length = 0;
}
Status GetElem(SqlList L, int i, ElemType *e)
{
	if (L.length == 0 || i < 1 || i > L.length) {
		return ERROR;
	}
	*e = L.data[i - 1];
	return OK;
}
Status ListInsert(SqlList *L, int i, ElemType e)
{
	int k;
	if (L->length == MAXSIZE)
		return ERROR;
	if (i<1 || i>L->length+1)
		return ERROR;
	if (i <= L->length)
	{
		for (k = L->length; k >= i - 1; k--)
			L->data[k + 1] = L->data[k];
	}
	L->data[i - 1] = e;
	L->length++;
	return OK;
}
Status ListDelete(SqlList *L, int i, ElemType *e)
{
	int k;
	if (L->length == 0)
		return ERROR;
	if (i<1 || i>L->length)
		return ERROR;
	*e = L->data[i - 1];
	if (i < L->length)
	{
		for (k = i; k < L->length; k++)
			L->data[k - 1] = L->data[k];
	}
	L->length--;
	return OK;
}
int ListLength(SqlList L)
{
	return L.length;
}

int main(void)
{
	SqlList linear;
	InitList(&linear);
	ElemType a = 2;
	int ret = ListInsert(&linear, 1, a);
	printf("%d", ret);
	int len = ListLength(linear);
	printf("%d", len);
	system("pause");
	return 0;
}