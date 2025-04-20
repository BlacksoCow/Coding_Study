#ifndef __ARRAYSTACK_H__
#define __ARRAYSTACK_H__

#define TRUE 1
#define FALSE 0
#define MAXLEN 100
#include "Vertex.h"

typedef Vertex Data;

typedef struct
{
	Data arr[MAXLEN];
	int cur;
} ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack* pstack);
int SIsEmpty(Stack* pstack);
void SPush(Stack* pstack, Data data);
Data SPop(Stack* pstack);
Data SPeek(Stack* pstack);

#endif