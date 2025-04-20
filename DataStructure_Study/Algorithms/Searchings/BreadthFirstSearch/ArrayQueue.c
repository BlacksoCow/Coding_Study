#include <stdio.h>
#include "ArrayQueue.h"
int NextPosIdx(int pos)
{
	if(pos == MAXLEN)
		return 0;
	return pos + 1;
}
void QueueInit(Queue* pqueue)
{
	pqueue->front = 0;
	pqueue->rear = 0;
	return;
}
int QIsEmpty(Queue* pqueue)
{
	return (pqueue->front == pqueue->rear) ? TRUE : FALSE;
}
void EnQueue(Queue* pqueue, Data data)
{
	if(NextPosIdx(pqueue->rear) == pqueue->front)
	{
		puts("Queue is full");
		return;
	}
	pqueue->rear = NextPosIdx(pqueue->rear);
	pqueue->arr[pqueue->rear] = data;
	return;
}
Data DeQueue(Queue* pqueue)
{
	if(QIsEmpty(pqueue))
	{
		puts("Empty queue");
		return -1;
	}
	pqueue->front = NextPosIdx(pqueue->front);
	Data ret = pqueue->arr[pqueue->front];
	return ret;
}
Data QPeek(Queue* pqueue)
{
	if(QIsEmpty(pqueue))
	{
		puts("Empty queue");
		return -1;
	}
	return pqueue->arr[NextPosIdx(pqueue->front)];
}