#ifndef __LISTQUEUE_H__
#define __LISTQUEUE_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct __node
{
	Data data;
	struct __node* next;
} Node;

typedef struct
{
	Node* front;
	Node* rear;
} ListQueue;

typedef ListQueue Queue;

void QueueInit(Queue* pqueue);
int QIsEmpty (Queue* pqueue);
void EnQueue(Queue* pqueue, Data data);
Data DeQueue(Queue* pqueue);
Data QPeek(Queue* pqueue);
void QFree(Queue* pqueue);

#endif