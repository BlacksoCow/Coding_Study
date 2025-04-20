#ifndef __HEAP_H__
#define __HEAP_H__

#define HEAPLEN 100
#define TRUE 1
#define FALSE 0

typedef int HData;
typedef int (*PriorityComp)(HData h1, HData h2); // Priority comparing function
// -> Return positive when left has, negative when right has higher priority and 0 when equal priority
typedef struct
{
	int numOfData;
	PriorityComp cp;
	HData heapArr[HEAPLEN + 1]; // Index 0 is empty in heap
} Heap;

void HeapInit(Heap* hp, PriorityComp cpfunc);
int HIsEmpty(Heap* hp);
int GetParentIdx(int idx);
int GetLChildIdx(int idx);
int GetRChildIdx(int idx);
int GetHiPriChildIdx(Heap* hp, int idx);
void HInsert(Heap* hp, HData data);
HData HDelete(Heap* hp);

#endif