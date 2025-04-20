#ifndef __CLSTACK_H__
#define __CLSTACK_H__

#include "CircularLinkedList.h"
typedef Ldata Data;

typedef struct
{
	List* list;
} CLSTACK;

typedef CLSTACK Stack;

void StackInit(Stack* pstack);
int SIsEmpty(Stack* pstack);
void SPush(Stack* pstack, Data data);
Data SPop(Stack* pstack);
Data SPeek(Stack* pstack);
void SFree(Stack* pstack);

#endif