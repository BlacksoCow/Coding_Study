#include <stdio.h>
#include <stdlib.h>
#include "ListStack.h"
void StackInit(Stack* pstack)
{
	pstack->head = NULL;
	return;
}
int SIsEmpty(Stack* pstack)
{
	if(pstack->head == NULL)
		return 1;
	return 0;
}
void SPush(Stack* pstack, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = pstack->head;
	pstack->head = newNode;
	return;
}
Data SPop(Stack* pstack)
{
	if(SIsEmpty(pstack))
	{
		puts("Empty stack");
		return -1;
	}
	Data ret = pstack->head->data;
	Node* rev = pstack->head;
	pstack->head = pstack->head->next;
	free(rev);
	return ret;
}
Data SPeek(Stack* pstack)
{
	if(SIsEmpty(pstack))
	{
		puts("Empty stack");
		return -1;
	}
	return pstack->head->data;
}
void SFree(Stack* pstack)
{
	Node* rev;
	while(pstack->head != NULL)
	{
		rev = pstack->head;
		pstack->head = pstack->head->next;
		free(rev);
	}
	return;
}