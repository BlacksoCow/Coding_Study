#include <stdio.h>
#include "Heap.h"
int PriComp(int num1, int num2)
{
	return num2 - num1;
}
void HeapSort(int arr[], int len)
{
	Heap heap;
	HeapInit(&heap, PriComp);
	for(int i = 0; i < len; i++)
		HInsert(&heap, arr[i]);
	for(int i = 0; i < len; i++)
		arr[i] = HDelete(&heap);
	return;
}
int main(int argc, char** argv)
{
	int arr[8] = {5, 2, 3, 7, 9, 6, 8, 10};
	HeapSort(arr, sizeof(arr) / sizeof(int));
	for(int i = 0; i < 8; i++)
		printf("%d ", arr[i]);
	putchar('\n');
	return 0;
}