#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"
void DequeInit(Deque* pdeq)
{
	pdeq->head = NULL;
	pdeq->tail = NULL;
	return;
}
int DQIsEmpty(Deque* pdeq)
{
	return (pdeq->head == NULL) ? TRUE : FALSE;
}
void DQAddFirst(Deque* pdeq, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = pdeq->head; // Creating and inserting data in newNode
	if(DQIsEmpty(pdeq))
		pdeq->tail = newNode;
	else
		pdeq->head->prev = newNode;
	newNode->prev = NULL; 
	pdeq->head = newNode;
	return;
}
void DQAddLast(Deque* pdeq, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->prev = pdeq->tail; // Creating and inserting data in newNode
	if(DQIsEmpty(pdeq))
		pdeq->head = newNode;
	else
		pdeq->tail->next = newNode;
	newNode->next = NULL;
	pdeq->tail = newNode;
	return;
}
Data DQRemoveFirst(Deque* pdeq)
{
	if(DQIsEmpty(pdeq))
	{
		puts("Empty deque");
		return -1;
	}
	Node* rev = pdeq->head;
	Data ret = pdeq->head->data;
	pdeq->head = pdeq->head->next;
	free(rev);
	if(pdeq->head == NULL)
		pdeq->tail = NULL; // Initializing tail when result is empty
	else
		pdeq->head->prev = NULL;
	return ret;
}
Data DQRemoveLast(Deque* pdeq)
{
	if(DQIsEmpty(pdeq))
	{
		puts("Empty deque");
		return -1;
	}
	Node* rev = pdeq->tail;
	Data ret = pdeq->tail->data;
	pdeq->tail = pdeq->tail->prev;
	free(rev);
	if(pdeq->tail == NULL)
		pdeq->head = NULL; // Initializing head when result is empty
	else
		pdeq->tail->next = NULL;
	return ret;
}
Data DQPeekFirst(Deque* pdeq)
{
	if(DQIsEmpty(pdeq))
	{
		puts("Empty deque");
		return -1;
	}
	return pdeq->head->data;
}
Data DQPeekLast(Deque* pdeq)
{
	if(DQIsEmpty(pdeq))
	{
		puts("Empty deque");
		return -1;
	}
	return pdeq->tail->data;
}
void DQFree(Deque* pdeq)
{
	while(!DQIsEmpty(pdeq))
		DQRemoveFirst(pdeq);
	return;
}