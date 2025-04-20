#include <stdio.h>
#include <stdlib.h>
#include "DoubleLinkedList.h"
void ListInit(List* plist)
{
	plist->head = (Node*)malloc(sizeof(Node)); // Needs 2 dummies in double linked list
	plist->tail = (Node*)malloc(sizeof(Node)); // in order not to split cases in insert
	plist->head->next = plist->tail;
	plist->head->prev = NULL;
	plist->tail->prev = plist->head;
	plist->tail->next = NULL;
	plist->numOfData = 0;
	plist->comp = NULL;
}
void LInsert(List* plist, Ldata data)
{
	if(plist->comp == NULL)
		FInsert(plist, data);
	else
		SInsert(plist, data);
}
void FInsert(List* plist, Ldata data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = plist->head->next;
	newNode->prev = plist->head;
	plist->head->next->prev = newNode;
	plist->head->next = newNode;
	(plist->numOfData)++;
	return;
}
void SInsert(List* plist, Ldata data)
{
	Node* pred = plist->head;
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	while((pred->next != plist->tail) && (plist->comp(data, pred->next->data) != 0))
		pred = pred->next; // Finds newNode's postion until it matches
	newNode->next = pred->next;
	newNode->prev = pred;
	pred->next->prev = newNode;
	pred->next = newNode;
	(plist->numOfData)++;
	return;
}
int LFirst(List* plist, Ldata* data)
{
	if(plist->head->next == plist->tail)
		return FALSE;
	plist->cur = plist->head->next;
	*data = plist->cur->data;
	return TRUE;
}
int LNext(List* plist, Ldata* data)
{
	if(plist->cur->next == plist->tail)
		return FALSE;
	plist->cur = plist->cur->next;
	*data = plist->cur->data;
	return TRUE;
}
int LPrevious(List* plist, Ldata* data)
{
	if(plist->cur->prev == plist->head)
		return FALSE;
	plist->cur = plist->cur->prev;
	*data = plist->cur->data;
	return TRUE;
}
Ldata LRemove(List* plist)
{
	Node* rNode = plist->cur;
	Ldata rdata = rNode->data;
	plist->cur->prev->next = plist->cur->next;
	plist->cur->next->prev = plist->cur->prev;
	plist->cur = plist->cur->prev;
	rNode->prev = NULL;
	rNode->next = NULL;
	free(rNode);
	puts("Data successfully deleted");
	(plist->numOfData)--;
	return rdata;
}
int LCount(List* plist)
{
	return plist->numOfData;
}
void SetSortRule(List* plist, int(*func)(Ldata data, Ldata compdata))
{
	plist->comp = func;
	return;
}
void RemoveAll(List* plist)
{
	plist->cur = plist->head->next;
	while(plist->cur->next != NULL) // stops when cur is tail
	{
		plist->cur->prev->prev = NULL;
		plist->cur->prev->next = NULL;
		free(plist->cur->prev);
		plist->cur = plist->cur->next;
	}
	plist->cur->prev->prev = NULL;
	plist->cur->prev->next = NULL;
	free(plist->cur->prev);
	plist->cur->prev = NULL;
	plist->cur->next = NULL;
	free(plist->cur);
	return;
}