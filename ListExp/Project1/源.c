#include <stdio.h>
#include <malloc.h>
#include "Status.h"

typedef struct LNode {
	ElemTyp data;
	struct LNode* next;
} LNode, *LinkList;

int main()
{

	return 0;
}

Status ListConnect(LinkList a, LinkList b, LinkList c)
{
	if (a == NULL || b == NULL || c == NULL) return Infeasible;
	c = a;
	for (; a->next!=NULL; a = a->next);
	a->next = b;
	return ok;
}

Status Insert(LinkList L, int i, ElemTyp e)
{
	LinkList cur = L;
	int count;
	for (count = 1; count <= i && cur->next != NULL; count++, cur = cur->next);
	if (cur->next == NULL && count != i)
	{
		return Infeasible;
	}
	else
	{
		LinkList cre = (LinkList)malloc(sizeof(LNode));
		cre->data = e;
		cre->next = cur->next;
		cur->next = cre;
		return ok;
	}
}

Status Delete(LinkList L, int i, ElemTyp* e)
{
	LinkList cur = L;
	int count;
	for (count = 1; count < i && cur->next != NULL; count++, cur = cur->next);
	if (cur->next == NULL || count != i || e == NULL)
	{
		return Infeasible;
	}
	else
	{
		LinkList del = cur->next;
		cur->next = del->next;
		*e = del->data;
		free(del);
		return ok;
	}
}

Status DeleteRange(LinkList L, ElemTyp mink, ElemTyp maxk)
{
	LinkList cur = L;
	for (; L->next->data < mink && L->next != NULL; L = L->next);
	if (L->next == NULL && L->data < mink) return Infeasible;
	LinkList curShadow = cur;
	for (; L->next->data <= maxk; L = L->next);
	if (L->next == NULL && L->data < maxk) return Infeasible;
	

}



