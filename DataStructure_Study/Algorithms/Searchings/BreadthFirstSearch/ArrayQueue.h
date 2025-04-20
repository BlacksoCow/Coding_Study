#ifndef __ARRAYQUEUE_H__
#define __ARRAYQUEUE_H__

#define MAXLEN 100
#define TRUE 1
#define FALSE 0
#include "Vertex.h"

typedef Vertex Data;

typedef struct
{
	Data arr[MAXLEN + 1];
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