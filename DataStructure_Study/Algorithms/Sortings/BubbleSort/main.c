#include <stdio.h>
void BubbleSort(int arr[], int len)
{
	int temp;
	for(int i = 0; i < len - 1; i++)
	{
		for(int j = 0; j < len - i - 1; j++)
		{
			if(arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	return;
}
int main(int argc, char** argv)
{
	int arr[8] = {5, 2, 3, 7, 9, 6, 8, 10};
	BubbleSort(arr, sizeof(arr) / sizeof(int));
	for(int i = 0; i < 8; i++)
		printf("%d ", arr[i]);
	putchar('\n');
	return 0;
}