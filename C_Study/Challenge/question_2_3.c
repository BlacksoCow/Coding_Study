#include <stdio.h>
int main(void)
{
	int element, oddsave = 0, evensave = 9, arr[10];
	for(int i = 0; i < 10; i++)
	{
		printf("Input integer number %d: ", i);
		scanf("%d", &element);
		if(element % 2)
		{
			arr[oddsave] = element;
			oddsave++;
		}
		else
		{
			arr[evensave] = element;
			evensave--;
		}
	}
	printf("Printing out array: ");
	for(int j = 0; j < 10; j++)
		printf("%d ", arr[j]);
	printf("\n");
	return 0;
}