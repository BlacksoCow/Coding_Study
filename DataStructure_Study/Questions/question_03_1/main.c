#include <stdio.h>
#include "ArrayList.h"
int main(int argc, char** argv)
{
	List arr;
	LData data, sum = 0, d = 1;
	ListInit(&arr);
	puts("<Before removal>");
	for(int i = 1; i <= 9; i++)
		LInsert(&arr, i);
	if(LFirst(&arr, &data))
	{
		do
		{
			printf("Data %d: %d\n", d++, data);
			sum += data;
		} while(LNext(&arr, &data));
	}
	printf("Sum: %d\n", sum);
	d = 1; sum = 0;
	puts("<After removal>");
	if(LFirst(&arr, &data))
	{
		while(LNext(&arr, &data))
		{
			if(!((data % 2) && (data % 3)))
				LRemove(&arr);
		}
	}
	if(LFirst(&arr, &data))
	{
		do
		{
			printf("Data %d: %d\n", d++, data);
			sum += data;
		} while(LNext(&arr, &data));
	}
	else
	{
		puts("No data in list");
		return 0;
	}
	printf("Sum: %d\n", sum);
	printf("Total datas: %d\n", LCount(&arr));
	return 0;
}