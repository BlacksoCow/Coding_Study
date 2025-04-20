#include <stdio.h>
#include "ArrayStack.h"
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
	return 0;
}