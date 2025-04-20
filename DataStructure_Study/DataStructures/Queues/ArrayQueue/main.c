#include <stdio.h>
#include "ArrayQueue.h"
int main(int argc, char** argv)
{
	Queue queue;
	QueueInit(&queue);
	printf("Is queue empty? : %d\n", QIsEmpty(&queue));
	printf("DeQueue result: %d\n", DeQueue(&queue));
	printf("QPeek result: %d\n\n", QPeek(&queue));
	for(int i = 0; i < 10; i++)
		EnQueue(&queue, i);
	putchar('\n');
	while(!QIsEmpty(&queue))
	{
		printf("Is queue empty? : %d\n", QIsEmpty(&queue));
		printf("DeQueue result: %d\n", DeQueue(&queue));
		printf("QPeek result: %d\n\n", QPeek(&queue));
	}
	printf("Is queue empty? : %d\n", QIsEmpty(&queue));
	return 0;
}