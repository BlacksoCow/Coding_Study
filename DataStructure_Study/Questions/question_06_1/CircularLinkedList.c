#include <stdlib.h>
#include "CircularLinkedList.h"
void ListInit(List* plist)
{
	plist->tail = (Node*)malloc(sizeof(Node)); // Beware that circular's dummy should
	plist->tail->next = plist->tail;           // point itself unlike SimpleLinkedList
	plist->numOfData = 0;
	plist->comp = NULL;
}
void LInsert(List* plist, Ldata data)
{
	if(plist->comp == NULL || plist->numOfData == 0)
		FInsert(plist, data);
	else
		SInsert(plist, data);
}
void FInsert(List* plist, Ldata data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data; // Initializing the data of newNode
	newNode->next = plist->tail->next; // problem here!!!!! p.173!!!!
	plist->tail->next = newNode;
	(plist->numOfData)++;
	return;
}
void SInsert(List* plist, Ldata data)
{
	Node* pred = plist->tail;
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	while((pred->next != plist->tail) && plist->comp(data, pred->next->data) != 0)
		pred = pred->next; // Finds newNode's postion until it matches
	// Note that checking pred->next is dummy should be in front
	// if pred->next == plist->tail, it means that insert data is largest
	newNode->next = pred->next;
	pred->next = newNode;
	(plist->numOfData)++;
	return;
}
int LFirst(List* plist, Ldata* data)
{
	if(plist->tail->next == plist->tail)
		return FALSE; // When list is empty
	plist->cur = plist->tail->next;
	plist->before = plist->tail;
	*data = plist->cur->data;
	return TRUE;
}
int LNext(List* plist, Ldata* data)
{
	if(plist->tail->next == plist->tail)
		return FALSE; // When list is empty
	plist->before = plist->cur;
	plist->cur = plist->cur->next;
	if((plist->cur) == (plist->tail))
	{
		plist->before = plist->cur;
		plist->cur = plist->cur->next;
	}
	*data = plist->cur->data;
	return TRUE;
}
Ldata LRemove(List* plist)
{
	Node* rNode = plist->cur;
	Ldata rdata = rNode->data; // problem here
	plist->before->next = plist->cur->next;
	plist->cur = plist->before;
	rNode->next = NULL;
	free(rNode);
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
	if(plist->numOfData == 0)
		return;
	plist->before = plist->tail;
	plist->cur = plist->tail->next;
	while(plist->cur->next != NULL)
	{
		plist->before->next = NULL;
		free(plist->before);
		plist->before = plist->cur;
		plist->cur = plist->cur->next;
	}
	plist->before->next = NULL;
	free(plist->before);
	free(plist->cur);
	return;
}