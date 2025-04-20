#include <stdio.h>
void CopyArray(int arr[][4], int temp[][4])
{
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
			temp[i][j] = arr[i][j];
	}
	return;
}
void SpinArray(int arr[][4])
{
	int temp[4][4];
	CopyArray(arr, temp);
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
			arr[i][j] = temp[3 - j][i];
	}
	return;
}
void PrintArray(int array[][4])
{
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
			printf("%d ", array[i][j]);
		printf("\n");
	}
	return;
}
int main(int argc, char** argv)
{
	int arr[4][4], k = 1;
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
			arr[i][j] = k++;
	}
	PrintArray(arr);
	SpinArray(arr);
	SpinArray(arr);
	SpinArray(arr);
	SpinArray(arr);
	PrintArray(arr);
	return 0;
}
