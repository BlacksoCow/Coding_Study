#include <stdio.h>
#include <stdlib.h>
#include "SimpleLinkedList.h"
void ListInit(List* plist)
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->numOfData = 0;
	plist->comp = NULL;
}
void LInsert(List* plist, Ldata data)
{
	if(plist->comp == NULL)
		FInsert(plist, data);
	else
		FInsert(plist, data); // Not a mistyping
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
int LFirst(List* plist, Ldata* data)
{
	if(plist->head->next == NULL)
	{
		puts("List is empty");
		return FALSE;
	}
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
	puts("Data successfully deleted");
	(plist->numOfData)--;
	return rdata;
}
int LCount(List* plist)
{
	return plist->numOfData;
}