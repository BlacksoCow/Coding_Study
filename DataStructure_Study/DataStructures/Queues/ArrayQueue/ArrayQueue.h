#ifndef __ARRAYQUEUE_H__
#define __ARRAYQUEUE_H__

#define QLEN 5
#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct
{
	Data arr[QLEN + 1];
	int front;
	int rear;
} ArrayQueue;

typedef ArrayQueue Queue;

void QueueInit(Queue* pqueue);
int QIsEmpty(Queue* pqueue);
void EnQueue(Queue* pqueue, Data data);
Data DeQueue(Queue* pqueue);
Data QPeek(Queue* pqueue);

#endif