#ifndef __SIMPLELINKEDLIST_H__
#define __SIMPLELINKEDLIST_H__

#include "Point.h"
#define TRUE 1;
#define FALSE 0;
typedef Point* Ldata;

typedef struct __node
{
	Ldata data;
	struct __node* next;
} Node;

typedef struct __linkedlist
{
	Node* head;
	Node* cur;
	Node* before;
	int numOfData;
	int (*comp)(Ldata d1, Ldata d2);
} SimpleLinkedList;

typedef SimpleLinkedList List;

void ListInit(List* plist);
void LInsert(List* plist, Ldata data);
void FInsert(List* plist, Ldata data);
int LFirst(List* plist, Ldata* pdata);
int LNext(List* plist, Ldata* pdata);
Ldata LRemove(List* plist);
int LCount(List* plist);

#endif