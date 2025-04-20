#include <stdio.h>
void SelectionSort(int arr[], int len)
{
	int minIdx, temp;
	for(int i = 0; i < len - 1; i++)
	{
		minIdx = i;
		for(int j = i + 1; j < len; j++)
		{
			if(arr[minIdx] > arr[j])
				minIdx = j;
		}
		temp = arr[i];
		arr[i] = arr[minIdx];
		arr[minIdx] = temp;
	}
	return;
}
int main(int argc, char** argv)
{
	int arr[8] = {5, 2, 3, 7, 9 ,6 ,8, 10};
	SelectionSort(arr, sizeof(arr) / sizeof(int));
	for(int i = 0; i < 8; i++)
		printf("%d ", arr[i]);
	putchar('\n');
	return 0;
}