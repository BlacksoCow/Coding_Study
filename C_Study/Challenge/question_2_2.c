#include <stdio.h>
void DecToBin(int num)
{
	int len = 0, sum = 0, printed = 0, adding = 1;
	while(sum < num)
	{
		sum += adding;
		adding *= 2;
		len++;
	}
	adding /= 2;
	if(!len)
	{
		printf("0\n");
		return;
	}
	int arr[len];
	while(num)
	{
		printf("%d", num / adding);
		num %= adding;
		adding /= 2;
		printed++;
	}
	for(int i = 0; i < len - printed; i++)
		printf("0");
	printf("\n");
	return;
}
int main(void)
{
	int num;
	printf("Input number: ");
	scanf("%d", &num);
	printf("Dec to Binary: ");
	DecToBin(num);
	return 0;
}