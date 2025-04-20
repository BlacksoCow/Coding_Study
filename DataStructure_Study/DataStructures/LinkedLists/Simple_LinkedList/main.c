#include <stdio.h>
#include "SimpleLinkedList.h"
int Arrange(int data1, int data2)
{
	return (data1 > data2 ? 1 : 0);
}
int main(int argc, char** argv)
{
	List list;
	int data;
	ListInit(&list);
	SetSortRule(&list, Arrange);
	for(int i = 0; i < 5; i++)
	{
		printf("Input data %d: ", i + 1);
		scanf("%d", &data);
		LInsert(&list, data);
	}
	if(LFirst(&list, &data))
	{
		int cnt = 1;
		do
		{
			printf("Data %d: %d\n", cnt, data);
		} while(LNext(&list, &data));
	}
	RemoveAll(&list);
	puts("End of journey");
	return 0;
}