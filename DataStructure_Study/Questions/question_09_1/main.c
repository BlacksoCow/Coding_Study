#include <stdio.h>
#include <string.h>
#include "Heap.h"
int PriorityCompFunc(HData h1, HData h2)
{
	if(strlen(h1) == strlen(h2))
		return strcmp(h2, h1);
	else
		return strlen(h2) - strlen(h1);
} // Primary criteria is length, secondary critiera is alphabetical order
int main(int argc, char** argv)
{
	Heap heap;
	HeapInit(&heap, PriorityCompFunc);
	HInsert(&heap, "Han");
	HInsert(&heap, "kwanwoo");
	HInsert(&heap, "Maestro_and_Clash");
	HInsert(&heap, "Maestro_and_clash");
	HInsert(&heap, "Tom_Clancy");
	HInsert(&heap, "rainbow");
	HInsert(&heap, "six");
	HInsert(&heap, "kwanwoo");
	HInsert(&heap, "Seige");
	while(!HIsEmpty(&heap))
		printf("%s ", HDelete(&heap));
	putchar('\n');
	return 0;
}