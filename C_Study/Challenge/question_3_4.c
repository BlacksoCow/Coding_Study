#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char** argv)
{
	int random1 = 0, random2 = 0;
	srand((int)time(NULL));
	while(!random1)
		random1 = rand() % 7;
	printf("The first dice: %d\n", random1);
	srand(rand());
	while(!random2)
		random2 = rand() % 7;
	printf("The second dice: %d\n", random2);
	return 0;
}