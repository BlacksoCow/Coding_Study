#include <stdio.h>
#include <stdlib.h>
#include "ListQueue.h"
void QueueInit(Queue* pqueue)
{
	pqueue->front = NULL;
	pqueue->rear = NULL;
	return;
}
int QIsEmpty(Queue* pqueue)
{
	return (pqueue->front == NULL) ? TRUE : FALSE;
}
void EnQueue(Queue* pqueue, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL; // Creating a newNode
	if(QIsEmpty(pqueue))
	{
		pqueue->front = newNode;
		pqueue->rear = newNode;
	}
	else
	{
		pqueue->rear->next = newNode;
		pqueue->rear = newNode;
	}
	return;
}
Data DeQueue(Queue* pqueue)
{
	if(QIsEmpty(pqueue))
	{
		puts("Empty Queue");
		return -1;
	}
	Data ret = pqueue->front->data;
	Node* rev = pqueue->front;
	pqueue->front = pqueue->front->next;
	free(rev);
	return ret;
}
Data QPeek(Queue* pqueue)
{
	if(QIsEmpty(pqueue))
	{
		puts("Empty Queue");
		return -1;
	}
	return pqueue->front->data;
}
void QFree(Queue* pqueue)
{
	while(!QIsEmpty(pqueue))
		DeQueue(pqueue);
	return;
}