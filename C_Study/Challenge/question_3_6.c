#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
bool Exist(int element, int answer[])
{
	for(int i = 0; i < 3; i++)
	{
		if(answer[i] == element)
			return true;
	}
	return false;
}
int CountStrike(int arr[], int answer[])
{
	int strike = 0;
	for(int i = 0; i < 3; i++)
	{
		if(arr[i] == answer[i])
			strike++;
	}
	return strike;
}
int CountBall(int arr[], int answer[])
{
	int ball = 0;
	for(int i = 0; i < 3; i++)
	{
		if(Exist(arr[i], answer))
			ball++;
	}
	ball -= CountStrike(arr, answer);
	return ball;
}
int Count(int arr[], int answer[], int(*func)(int*, int*))
{ return func(arr, answer); }
void BaseBall(int answer[])
{
	int arr[3], strike = 0, ball = 0, cnt = 1;
	while(strike != 3 && cnt++)
	{
		strike = ball = 0;
		printf("\nInput 3 numbers: ");
		scanf("%d%d%d", &arr[0], &arr[1], &arr[2]);
		strike = Count(arr, answer, CountStrike);
		ball = Count(arr, answer, CountBall);
		printf("%d strike, %d ball", strike, ball);
	}
	printf("\n\nGame Over!\n");
	printf("Attempts: %d\n", cnt);
}
int main(int argc, char** argv)
{
	int answer[3];
	printf("Start game!");
	srand((int)time(NULL));
	answer[0] = rand() % 10;
	srand(rand());
	do
	{
		answer[1] = rand() % 10;
	}while(answer[1] == answer[0]);
	srand((int)time(NULL) - rand());
	do{
		answer[2] = rand() % 10;
	}while(answer[2] == answer[1]
		 || answer[2] == answer[0]);
	BaseBall(answer);
	return 0;	
}