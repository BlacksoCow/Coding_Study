#include <stdio.h>
#include "DoubleLinkedList.h"
int main(int argc, char** argv)
{
	List list;
	int data;
	ListInit(&list);
	for(int i = 0; i < 5; i++)
	{
		printf("Input data %d: ", i + 1);
		scanf("%d", &data);
		LInsert(&list, data);
	}
	if(LFirst(&list, &data))
	{
		do
		{
			printf("%d ", data);
		} while(LNext(&list, &data));
		do
		{
			printf("%d ", data);
		} while(LPrevious(&list, &data));
		do
		{
			printf("%d ", data);
		} while(LNext(&list, &data));
		do
		{
			printf("%d ", data);
		} while(LPrevious(&list, &data));
		putchar('\n');
	}
	if(LFirst(&list, &data))
	{
		do
		{
			if(data % 2 == 1)
				LRemove(&list);
		} while(LNext(&list, &data));
	}
	if(LFirst(&list, &data))
	{
		do
		{
			printf("%d ", data);
		} while(LNext(&list, &data));
		do
		{
			printf("%d ", data);
		} while(LPrevious(&list, &data));
		do
		{
			printf("%d ", data);
		} while(LNext(&list, &data));
		do
		{
			printf("%d ", data);
		} while(LPrevious(&list, &data));
		putchar('\n');
	}
	RemoveAll(&list);
	puts("End of journey");
	return 0;
}