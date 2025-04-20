#include <stdio.h>
#include <stdlib.h>
void Merge(int arr[], int left, int mid, int right)
{
	int lIdx = left;
	int rIdx = mid + 1;
	int fIdx = left;
	int* copy = (int*)malloc(sizeof(int) * (right + 1));
	while(lIdx <= mid && rIdx <= right)
	{
		if(arr[lIdx] < arr[rIdx])
			copy[fIdx] = arr[lIdx++];
		else
			copy[fIdx] = arr[rIdx++];
		fIdx++;
	}
	while(lIdx <= mid)
	{
		copy[fIdx] = arr[lIdx++];
		fIdx++;
	}
	while(rIdx <= right)
	{
		copy[fIdx] = arr[rIdx++];
		fIdx++;
	}
	for(int i = left; i <= right; i++)
		arr[i] = copy[i];
	free(copy);
	return;
}
void MergeSort(int arr[], int left, int right)
{
	int mid = (left + right) / 2;
	if(left < right)
	{
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);
		Merge(arr, left, mid, right);
	}
	return;
}
int main(int argc, char** argv)
{
	int arr[8] = {5, 2, 3, 7, 9, 6, 8, 10};
	MergeSort(arr, 1, 5);
	for(int i = 0; i < 8; i++)
		printf("%d ", arr[i]);
	putchar('\n');
	return 0;
}