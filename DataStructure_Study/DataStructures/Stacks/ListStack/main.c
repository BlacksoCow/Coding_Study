#include <stdio.h>
#include "ListStack.h"
int main(int argc, char** argv)
{
	Stack stack;
	StackInit(&stack);
	printf("Data: %d\n", SPop(&stack));
	printf("Data: %d\n", SPeek(&stack));
	for(int i = 0; i < 5; i++)
		SPush(&stack, i + 1);
	printf("Data: %d\n", SPop(&stack));
	printf("Data: %d\n", SPeek(&stack));
	printf("Result: %d\n", SIsEmpty(&stack));
	for(int i = 0; i < 4; i++)
		printf("Data: %d\n", SPop(&stack));
	printf("Result: %d\n", SIsEmpty(&stack));
	SFree(&stack);
	printf("Result: %d\n", SIsEmpty(&stack));
	return 0;
}