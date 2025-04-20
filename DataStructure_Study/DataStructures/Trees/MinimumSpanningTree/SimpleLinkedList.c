#include <stdio.h>
#include <stdlib.h>
#include "SimpleLinkedList.h"
void ListInit(List* plist)
{
	plist->head = (Node*)malloc(sizeof(Node)); // Need a dummy in order not to split
	plist->head->next = NULL;                  // cases in inserting
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
	plist->head->next = newNode;
	(plist->numOfData)++;
	return;
}
void SInsert(List* plist, Ldata data)
{
	Node* pred = plist->head;
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	while((pred->next != NULL) && (plist->comp(data, pred->next->data) != 0))
		pred = pred->next; // Finds newNode's postion until it matches
	newNode->next = pred->next;
	pred->next = newNode;
	(plist->numOfData)++;
	return;
}
int LFirst(List* plist, Ldata* data)
{
	if(plist->head->next == NULL)
		return FALSE;
	plist->cur = plist->head->next;
	plist->before = plist->head;
	*data = plist->cur->data;
	return TRUE;
}
int LNext(List* plist, Ldata* data)
{
	if(plist->cur->next == NULL)
		return FALSE;
	plist->before = plist->cur;
	plist->cur = plist->cur->next;
	*data = plist->cur->data;
	return TRUE;
}
Ldata LRemove(List* plist)
{	
	Node* rNode = plist->cur;
	Ldata rdata = rNode->data;
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
	plist->before = plist->head;
	plist->cur = plist->head->next;
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