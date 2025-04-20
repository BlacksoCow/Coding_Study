#include <stdio.h>
int ISearch(int arr[], int left, int right, int target)
{
	int start = ((double)(target - arr[left])) / (arr[right] - arr[left])
				* (right - left) + left; // Making result double for accuracy
	if(target < arr[left] || target > arr[right])
		return -1; // No target when target is out of bounds
	else if(target == arr[start])
		return start;
	else if(target < arr[start])
		return ISearch(arr, left, start - 1, target);
	else
		return ISearch(arr, start + 1, right, target);
}
int main(int argc, char** argv)
{
	int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
	int idx;
	for(int i = -3; i < 20; i++)
	{
		idx = ISearch(arr, 0, sizeof(arr) / sizeof(int) - 1, i);
		if(idx == -1)
			puts("Search failed");
		else
			printf("Target index: %d\n", idx);
	}
	return 0;
}