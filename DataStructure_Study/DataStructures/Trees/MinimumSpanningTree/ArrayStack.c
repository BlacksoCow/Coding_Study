#include <stdio.h>
#include "ArrayStack.h"
void StackInit(Stack* pstack)
{
	pstack->cur = -1;
	for(int i = 0; i < MAXLEN; i++)
		pstack->arr[i] = 0;
	return;
}
int SIsEmpty(Stack* pstack)
{
	return (pstack->cur < 0) ? TRUE : FALSE;
}
void SPush(Stack* pstack, Data data)
{
	pstack->arr[++(pstack->cur)] = data;
	return;
}
Data SPop(Stack* pstack)
{
	if(SIsEmpty(pstack))
	{
		puts("Empty stack");
		return -1;
	}
	Data ret = pstack->arr[(pstack->cur)--];
	return ret;
}
Data SPeek(Stack* pstack)
{
	if(SIsEmpty(pstack))
	{
		puts("Empty stack");
		return -1;
	}
	return pstack->arr[pstack->cur];
}