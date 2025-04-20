#include <stdio.h>
void PrintArray(int size, int arr[][size])
{
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
			printf("%-2d ", arr[i][j]);
		printf("\n");
	}
	return;
}
void SnailArray(int size, int arr[][size])
{
	int i = 0, start = 1, end = size * size;
	if(size % 2)
		arr[size / 2][size / 2] = end;
	do
	{
		for(int j = i; j < size - i - 1; j++)
			arr[i][j] = start++;
		for(int j = i; j < size - i - 1; j++)
			arr[j][size - i - 1] = start++;
		for(int j = size - i - 1; j > i; j--)
			arr[size - i - 1][j] = start++;
		for(int j = size - i - 1; j > i; j--)
			arr[j][i] = start++;
	} while(++i && start < end);
	return;
}
int main(int argc, char** argv)
{
	int size;
	printf("Input the array size(n * n): ");
	scanf("%d", &size);
	int arr[size][size];
	SnailArray(size, arr);
	PrintArray(size, arr);
	return 0;
}