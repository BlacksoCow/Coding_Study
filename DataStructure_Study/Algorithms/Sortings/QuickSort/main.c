#include <stdio.h>
int Median(int arr[], int left, int right)
{
	int mid = (left + right) / 2;
	if(arr[left] > arr[right])
	{
		if(arr[left] > arr[mid])
			return arr[mid] > arr[right] ? mid : right;
		else
			return left;
	}
	else
	{
		if(arr[right] > arr[mid])
			return arr[mid] > arr[left] ? mid : left;
		else
			return right;
	}
}
void Swap(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
	return;
}
int Partition(int arr[], int left, int right)
{
	int pIdx = Median(arr, left, right);
	int pivot = arr[pIdx];
	Swap(&arr[pIdx], &arr[left]);
	int low = left + 1;
	int high = right;
	printf("Pivot: %d\n", pivot);
	while(low <= high)
	{
		while(arr[low] <= pivot && low <= right)
			low++;
		while(arr[high] >= pivot && high >= (left + 1))
			high--;
		if(low <= high)
			Swap(&arr[low], &arr[high]);
	}
	Swap(&arr[left], &arr[high]); // Swaping pivot and high
	return high;
} // Determining pivot's position
void QuickSort(int arr[], int left, int right)
{
	if(left < right)
	{
		int pivot = Partition(arr, left, right); // Must be inside 'if' because right maybe less than left
		QuickSort(arr, left, pivot - 1);
		QuickSort(arr, pivot + 1, right);
	}
	return;
}
int main(int argc, char** argv)
{
	int arr[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	QuickSort(arr, 0, 14);
	for(int i = 0; i < 15; i++)
		printf("%d ", arr[i]);
	putchar('\n');
	return 0;
}