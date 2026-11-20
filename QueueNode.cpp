//#include <stdio.h>
//#include <stdlib.h>
//#define ERROR 0
//#define OK 1
//#define OVERFLOW -2
//#define MAXSIZE 100
//
//typedef int ElemType;
//typedef int Status;
//
//typedef struct QNode
//{
//	ElemType data;
//	struct QNode* next;
//}QNode;
//
//typedef struct
//{
//	QNode* front;
//	QNode* rear;
//}LinkQueue;
//
////1.初始化
//Status InitQueue(LinkQueue* Q)
//{
//	Q->rear = (QNode*)malloc(sizeof(QNode));
//	Q->front = Q->rear;
//	if (!Q->front)
//		return ERROR;
//	Q->front->next = NULL;
//	return OK;
//}
//
////2.入队
//Status EnQueue(LinkQueue* Q,ElemType e)
//{
//	QNode* p;
//	p = (QNode*)malloc(sizeof(QNode));
//	p->data = e;
//	Q->rear->next = p;
//	p->next = NULL;
//	Q->rear = p;
//	return OK;
//}
//
////3.出队
//Status DeQueue(LinkQueue* Q, ElemType* e)
//{
//	if (Q->front == Q->rear)
//		return ERROR;
//	QNode* p = Q->front->next;
//	*e = p->data;
//	Q->front->next = p->next;
//	if (Q->rear == p)
//		Q->rear = Q->front;
//	free(p);
//	return OK;
//}
//
////4.取队头元素
//Status GetHead(LinkQueue Q, ElemType* e)
//{
//	if (Q.front == Q.rear)
//		return ERROR;
//	*e = Q.front->next->data;
//	return OK;
//}
//
////5.遍历
//Status Display(LinkQueue Q)
//{
//	if (Q.front == Q.rear)
//		return ERROR;
//	QNode* p;
//	p = Q.front->next;
//	while (p)
//	{
//		printf("%d ", p->data);
//		p = p->next;
//	}
//	return OK;
//}
//
//int main()
//{
//	LinkQueue Q;
//	InitQueue(&Q);
//	EnQueue(&Q, 3);
//	EnQueue(&Q, 4);
//	EnQueue(&Q, 5);
//	Display(Q);
//	int e = 0;
//	DeQueue(&Q, &e);
//	Display(Q);
//	return 0;
//}