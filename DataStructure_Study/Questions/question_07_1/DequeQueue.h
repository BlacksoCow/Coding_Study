#ifndef __DEQUEQUEUE_H__
#define __DEQUEQUEUE_H__

#include "Deque.h"

typedef struct
{
	Deque* deq;
} DequeQueue;

typedef DequeQueue Queue;

void QueueInit(Queue* pq);
int QIsEmpty(Queue* pq);
void EnQueue(Queue* pq, Data data);
Data DeQueue(Queue* pq);
Data QPeek(Queue* pq);
void QFree(Queue* pq);

#endif