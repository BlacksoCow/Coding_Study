#include <stdio.h>
#include <stdlib.h>
#include "CLStack.h"
void StackInit(Stack* pstack)
{
	pstack->list = (List*)malloc(sizeof(List));
	ListInit(pstack->list);
	return;
}
int SIsEmpty(Stack* pstack)
{
	if(LCount(pstack->list) == 0)
		return 1;
	return 0;
}
void SPush(Stack* pstack, Data data)
{
	LInsert(pstack->list, data);
	return;
}
Data SPop(Stack* pstack)
{
	Data ret;
	if(LFirst(pstack->list, &ret))
		return LRemove(pstack->list);
	puts("Empty stack");
	return -1;
}
Data SPeek(Stack* pstack)
{
	Data ret;
	if(LFirst(pstack->list, &ret))
		return ret;
	puts("Empty stack");
	return -1;
}
void SFree(Stack* pstack)
{
	RemoveAll(pstack->list);
	free(pstack->list);
	return;
}