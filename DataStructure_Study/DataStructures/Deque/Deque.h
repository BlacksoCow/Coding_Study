#ifndef __DEQUE_H__
#define __DEQUE_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct __node
{
	Data data;
	struct __node* prev;
	struct __node* next;
} Node;

typedef struct
{
	Node* head;
	Node* tail;
} ListDeque;

typedef ListDeque Deque;

void DequeInit(Deque*);
int DQIsEmpty(Deque*);
void DQAddFirst(Deque*, Data);
void DQAddLast(Deque*, Data);
Data DQRemoveFirst(Deque*);
Data DQRemoveLast(Deque*);
Data DQPeekFirst(Deque*);
Data DQPeekLast(Deque*);
void DQFree(Deque*);

#endif