#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2

#define MAXSIZE 100

typedef int Status;
typedef int ElemType;

typedef struct
{
	ElemType* elem;
	int length;
}SqList;

Status InitList(SqList* L)
{
	(*L).elem = (ElemType*)malloc(sizeof(ElemType)* MAXSIZE);
	if ((*L).elem == NULL)
		return ERROR;
	(*L).length = 0;
	return OK;
}

Status GetElem(SqList* L, int i,ElemType* e)
{
	if (i<1 || i>(*L).length)
		return ERROR;
	*e = (*L).elem[i - 1];
	return OK;
}

Status LocateList(SqList* L, ElemType e)
{
	for (int i = 1; i <= (*L).length-1; i++)
	{
		if ((*L).elem[i - 1] == e)
			return i - 1;
		else
			return ERROR;
	}
}

Status ListInsert(SqList* L, int i, ElemType e)
{
	if (i<1 || i>(*L).length)
		return ERROR;
	if ((*L).length == MAXSIZE)
		return ERROR;
	for (int j = (*L).length - 1; j >= i; j--)
	{
		(*L).elem[j + 1] = (*L).elem[j];
	}
	(*L).elem[i] = e;
	(*L).length++;
	return OK;
}

Status ListDelete(SqList* L, int i, ElemType* e)
{
	if (i<1 || i>(*L).length)
		return ERROR;
	for (int j = i; j <= (*L).length - 1; j++)
	{
		(*L).elem[j - 1] = (*L).elem[j];
	}
	*e = (*L).elem[i - 1];
	(*L).elem[(*L).length - 1] = 0;
	(*L).length--;
	return OK;
}

int main()
{
	SqList L;
	return 0;
}