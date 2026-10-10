#include <stdio.h>
#include <stdlib.h>
#define ERROR 0
#define OK 1
#define OVERFLOW -2

#define MAXSIZE 100

typedef int Status;
typedef int ElemType;

typedef struct
{
	ElemType* elem;
	int length;
}SqList;

//1.
ElemType Delete_Min(SqList* L, int* e)
{
	if (L->length == 0)          /* 空表：边界必须先挡掉 */
		return ERROR;

	int num = 0;
	*e = L->elem[0];
	for (int i = 1; i <= L->length; i++)
	{
		if (L->elem[i - 1] < *e)
		{
			*e = L->elem[i - 1];
			num = i - 1;
		}
	}
	L->elem[num] = L->elem[L->length - 1];
	L->length--;

	return OK;
}


int main()
{
	SqList L;
	return 0;
}