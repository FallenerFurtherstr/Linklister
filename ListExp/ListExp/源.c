#include <stdio.h>
#include <malloc.h>

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef struct {
	int* elem;
	int length;
	int listsize;
} SqList;

int main()
{
	SqList test;
	test.elem = (int)malloc(sizeof(LIST_INIT_SIZE));
	test.length = 5;
	test.listsize = LIST_INIT_SIZE;
	return 0;
}

void DeleteK(SqList* a, int i, int k)
{
	for (int j = 0; i + k + j < a->length; j++)
	{
		a->elem[i + j] = a->elem[i + k + j];
	}
	a->length -= k;
}

