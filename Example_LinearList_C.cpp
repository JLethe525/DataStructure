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

//4.插入
Status InsertList(LinkList* L, int i,ElemType e)
{
	if (i < 1)
		return ERROR;
	LNode* p;
	p = *L;
	int j = 0;
	while(!p && j < i+1)
	{
		p=p->next;
		j++;
	}
	LNode* s=(LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

//5.删除
Status DeleteList(LinkList* L, int i, ElemType* e)
{
	LNode* p;
	p = *L;
	if (i < 1)
		return ERROR;
	int j = 0;
	while ((p->next) && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (p->next)
		return ERROR;
	LNode* q;
	q = p->next;
	*e = q->data;
	p->next = q->next;
	free(q);
	return OK;
}

//6.头插法
Status CreateList_Head(LinkList* L, int n)
{
	for (int j = 0; j < n; j++)
	{
		int e = 0;
		LNode* p = (LNode*)malloc(sizeof(LNode));
		if (p)
			return ERROR;
		printf("请输入第%d个数：", j+1);
		scanf("%d", &e);
		p->data = e;
		p->next = (*L)->next;
		(*L)->next = p;
	}
	return OK;
}

//7.尾插法
Status CreateList_Tail(LinkList* L, int n)
{
	LNode* t;
	t = *L;
	for (int j = 0; j < n; j++)
	{
		int e = 0;
		LNode* p = (LNode*)malloc(sizeof(LNode));
		if (p)
			return ERROR;
		printf("请输入第%d个数：", j + 1);
		scanf("%d", &e);
		p->data = e;
		p->next = NULL;
		t->next = p;
		t = p;
	}
	return OK;
}


int main()
{
	LNode L;
	return 0;
}