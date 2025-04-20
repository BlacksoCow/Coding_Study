#include <stdio.h>
void Swap(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
	return;
}
void DesSort(int arr[])
{
	for(int i = 0; i < 7; i++)
	{
		for(int j = 0; j < 6 - i; j++)
		{
			if(arr[j] < arr[j + 1])
				Swap(&(arr[j]), &(arr[j + 1]));
		}
	}
	printf("Sorted result: ");
	for(int k = 0; k < 7; k++)
		printf("%d ", arr[k]);
	printf("\n");
	return;
}
int main(void)
{
	int arr[7];
	for(int i = 0; i < 7; i++)
	{
		printf("Input integer number %d: ", i + 1);
		scanf("%d", &(arr[i]));
	}
	DesSort(arr);
	return 0;
}