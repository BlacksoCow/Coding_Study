#ifndef __CIRCULARLINKEDLIST_H__
#define __CIRCULARLINKEDLIST_H__

#include "Company.h"
#define TRUE 1
#define FALSE 0

typedef Employee* Ldata;

typedef struct __node
{
	Ldata data;
	struct __node* next;
} Node;

typedef struct __c_linkedlist
{
	Node* tail;
	Node* cur;
	Node* before;
	int numOfData;
	int (*comp)(Ldata d1, Ldata d2);
} CircularLinkedList;

typedef CircularLinkedList List;

void ListInit(List* plist);
void LInsert(List* plist, Ldata data);
void FInsert(List* plist, Ldata data);
void SInsert(List* plist, Ldata data);
int LFirst(List* plist, Ldata* pdata);
int LNext(List* plist, Ldata* pdata);
Ldata LRemove(List* plist);
int LCount(List* plist);
void SetSortRule(List* plist, int(*func)(Ldata data, Ldata compdata));
void RemoveAll(List* plist);

#endif