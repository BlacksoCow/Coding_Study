#ifndef __LISTSTACK_H__
#define __LISTSTACK_H__

typedef int Data;

typedef struct __node
{
	Data data;
	struct __node* next;
} Node;

typedef struct
{
	Node* head;
} ListStack;

typedef ListStack Stack;

void StackInit(Stack* pstack);
int SIsEmpty(Stack* pstack);
void SPush(Stack* pstack, Data data);
Data SPop(Stack* pstack);
Data SPeek(Stack* pstack);
void SFree(Stack* pstack);

#endif