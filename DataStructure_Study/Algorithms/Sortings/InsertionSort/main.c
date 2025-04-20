#include <stdio.h>
void InsertionSort(int arr[], int len)
{
	int temp, cIdx;
	for(int i = 1; i < len; i++)
	{
		temp = arr[i];
		cIdx = i;
		for(int j = i - 1; j >= 0; j--)
		{
			if(arr[j] > temp)
			{
				arr[j + 1] = arr[j];
				cIdx = j;
			}
			else
				break;
		}
		arr[cIdx] = temp;
	}
	return;
}
int main(int argc, char** argv)
{
	int arr[8] = {5, 2, 3, 7, 9, 6, 8, 10};
	InsertionSort(arr, sizeof(arr) / sizeof(int));
	for(int i = 0; i < 8; i++)
		printf("%d ", arr[i]);
	putchar('\n');
	return 0;
}