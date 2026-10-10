#include <stdio.h>
#include <stdlib.h>
#define ERROR 0
#define OK 1
#define OVERFLOW -2

#define MAXSIZE 100

typedef int ElemType;
typedef int Status;

typedef struct LNode
{
	int data;
	struct LNode * next;
}LNode,*LinkList;

//1.初始化
Status InitList(LinkList* L)
{
	(*L)->next = (LNode*)malloc(sizeof(LNode));
	(*L)->next = NULL;
	if ((*L)->next != NULL)
		return ERROR;
	return OK;
}

//2.按位取值
Status GetElem(LinkList L, int i, ElemType* e)
{
	LNode* p;
	p = L->next;
	if (i < 1 || p==NULL)
		return ERROR;
	int j = 1;
	while (j != i)
	{
		p = p->next;
		j++;
	}
	*e = p->data;
	return OK;
}

//3.查找
LNode* LocateList(LinkList L, ElemType e)
{
	LNode* p;
	p = L->next;
	if (p)
		return ERROR;
	while (p && (p->data) != e)
	{
		p = p->next;
	}
	if ((p->data) != e)
		return ERROR;
	return p;
}



int main()
{
	LNode L;
	return 0;
}