//#include <stdio.h>
//#include <stdlib.h>
//#define ERROR 0
//#define OK 1
//#define OVERFLOW  -2
//
//#define MAXSIZE 100
//
//typedef int Status;
//typedef int ElemType;
//
//typedef struct
//{
//	ElemType* base;//栈底指针
//	ElemType* top;//栈顶指针
//	int stacksize;//栈最大容量
//}SqStack;
//
////1.初始化
//Status InitStack(SqStack* S)
//{
//    S->base = (ElemType*)malloc(MAXSIZE*sizeof(ElemType));
//	if (S->base == NULL)
//		return ERROR;
//	S->top = S->base;
//	S->stacksize = MAXSIZE;
//	return OK;
//}
//
////2.入栈
//Status Push(SqStack* S,int e)
//{
//	if (S->top - S->base == S->stacksize)//栈已满
//		return ERROR;
//	*S->top = e;
//	S->top++;
//	return OK;
//}
//
////3.出栈
//Status Pop(SqStack* S, int* e)
//{
//	if (S->base == S->top)//栈空
//		return ERROR;
//	--S->top;
//	*e = *S->top;
//	return OK;
//}
//
////4.取栈顶元素
//Status GetTop(SqStack S,ElemType* e)
//{
//	if (S.base != S.top)
//	{
//		*e = *(S.top - 1);
//		return OK;
//	}
//	else
//		return ERROR;
//}
//
////5.遍历
//Status Display(SqStack S)
//{
//	if (S.base == S.top)//栈空
//		return ERROR;
//	while (S.top!=S.base)
//	{
//		printf("%d ", *S.base);
//		S.base++;
//	}
//	return OK;
//}
//
////6.销毁栈
//Status DestroyStack(SqStack* S)
//{
//	free(S->base);              // 只 free 一次,base 是这块内存的唯一持有者
//	S->base = S->top = NULL;
//	S->stacksize = 0;
//	return OK;
//}
//
//int main()
//{
//	SqStack S;
//	InitStack(&S);
//	Push(&S, 3);
//	Push(&S, 4);
//	Push(&S, 5);
//	Display(S);
//	int e=0;
//	Pop(&S, &e);
//	Display(S);
//	free(S.base);
//	return 0;
//}