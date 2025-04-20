#include <stdio.h>
#include "Heap.h"
int PriorityCompFunc(HData h1, HData h2)
{
	return h2 - h1;
} // Returns positive when h1's priority is higher than h2
int main(int argc, char** argv)
{
	Heap heap;
	HeapInit(&heap, PriorityCompFunc);
	for(int i = 'Z'; i >= 'A'; i--)
		HInsert(&heap, i);
	for(int i = 'A'; i <= 'G'; i++)
		HInsert(&heap, i);
	while(!HIsEmpty(&heap))
		printf("%c ", HDelete(&heap));
	putchar('\n');
	return 0;
}