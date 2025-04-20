#include <stdio.h>
#include "CircularLinkedList.h"
int Upper(int data1, int data2)
{
	return (data1 > data2 ? 1 : 0);
}
int main(int argc, char** argv)
{
	List list;
	int data;
	ListInit(&list);
	if(LFirst(&list, &data))
		printf("Not empty\n");
	SetSortRule(&list, Upper);
	for(int i = 0; i < 5; i++)
	{
		printf("Input data %d: ", i + 1);
		scanf("%d", &data);
		LInsert(&list, data);
	} // Inserting 5 datas
	if(LFirst(&list, &data))
	{
		printf("%d ", data);
		for(int i = 0; i < LCount(&list) * 3 - 1; i++)
		{
			if(LNext(&list, &data))
				printf("%d ", data);
		}
		putchar('\n');
	} //Printing datas 3 times
	int nodeNum = LCount(&list);
	if(LFirst(&list, &data))
	{
		for(int i = 0; i < nodeNum; i++)
		{ // Probably using nodeNum variable because LRemove alters LCount func
			if(data % 2 == 0)
				LRemove(&list);
			LNext(&list, &data);
		}
	} // Removing even numbers
	if(LFirst(&list, &data))
	{
		for(int i = 0; i < LCount(&list); i++)
		{
			printf("%d ", data);
			LNext(&list, &data);
		}
		putchar('\n');
	} // Printing all datas
	RemoveAll(&list);
	return 0;
}