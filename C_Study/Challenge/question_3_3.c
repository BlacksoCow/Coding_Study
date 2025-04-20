#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv)
{
	printf("The range of random is 0 to 99\n");
	for(int i = 1; i <= 5; i++)
		printf("Random %d: %d\n", i, rand() % 100);
	return 0;
}