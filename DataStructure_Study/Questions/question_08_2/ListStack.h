#ifndef __LISTSTACK_H__
#define __LISTSTACK_H__

#include "BinaryTree.h"

typedef BTreeNode* SData;

typedef struct __node
{
	SData data;
	struct __node* next;
} Node;

typedef struct
{
	Node* head;
} ListStack;

typedef ListStack Stack;

void StackInit(Stack* pstack);
int SIsEmpty(Stack* pstack);
void SPush(Stack* pstack, SData data);
SData SPop(Stack* pstack);
SData SPeek(Stack* pstack);
void SFree(Stack* pstack);

#endif