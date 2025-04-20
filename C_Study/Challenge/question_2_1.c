#include <stdio.h>
#include <stdbool.h>
bool Exist(int arr[], int element)
{
	for(int i = 0; i < 10; i++)
	{
		if(arr[i] == element)
			return true;
	}
	return false;
}
void PrintOdd(int arr[])
{
	int oddarr[10] = { 0, };
	int checkpoint = 0;
	for(int i = 0; i < 10; i++)
	{
		if((arr[i] % 2) && !(Exist(oddarr, arr[i])))
			oddarr[checkpoint++] = arr[i];
	}
	if(oddarr[0] != 0)
		printf("Printing out add: %d", oddarr[0]);
	else
	{
		printf("No odd number\n");
		return;
	}
	for(int j = 1; j < checkpoint; j++)
		printf(", %d", oddarr[j]);
	printf("\n");
	return;
}
void PrintEven(int arr[])
{
	int evenarr[10], checkpoint = 0;
	for(int i = 0; i < 10; i++)
		evenarr[i] = 1;
	for(int i = 0; i < 10; i++)
	{
		if(!(arr[i] % 2) && !(Exist(evenarr, arr[i])))
			evenarr[checkpoint++] = arr[i];
	}
	if(evenarr[0] != 1)
		printf("Printing out even: %d", evenarr[0]);
	else
	{
		printf("No even number\n");
		return;
	}
	for(int j = 1; j < checkpoint; j++)
		printf(", %d", evenarr[j]);
	printf("\n");
	return;
}
int main(void)
{
	int arr[10];
	for(int i = 0; i < 10; i++)
	{
		printf("Input integer number %d: ", i + 1);
		scanf("%d", &(arr[i]));
	}
	PrintOdd(arr);
	PrintEven(arr);
	return 0;
}