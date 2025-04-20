#include <stdio.h>
#include "ListQueue.h"
#define BUCKET_NUM 10
void RadixSort(int arr[], int len, int maxsize)
{
	int radix, divfac = 1;
	Queue queue[BUCKET_NUM];
	for(int i = 0; i < BUCKET_NUM; i++)
		QueueInit(&queue[i]); // Initializing buckets
	for(int pos = 0; pos < maxsize; pos++)
	{
		for(int i = 0; i < len; i++)
		{
			radix = (arr[i] / divfac) % 10;
			EnQueue(&queue[radix], arr[i]);
		}
		for(int i = 0, index = 0; i < BUCKET_NUM; i++)
		{
			while(!QIsEmpty(&queue[i]))
				arr[index++] = DeQueue(&queue[i]);
		} // Copying buckets into arr
		divfac *= 10; // Enqueuing buckets
	}
	for(int i = 0; i < BUCKET_NUM; i++)
		QFree(&queue[i]);
	return;
}
int main(int argc, char** argv)
{
	int arr[8] = {523, 2801, 3, 6957, 79, 16, 238, 4};
	RadixSort(arr, sizeof(arr) / sizeof(int), 4);
	for(int i = 0; i < 8; i++)
		printf("%d ", arr[i]);
	putchar('\n');
	return 0;
}