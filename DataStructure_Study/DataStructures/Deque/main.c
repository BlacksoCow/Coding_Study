#include <stdio.h>
#include "Deque.h"
int main(int argc, char** argv)
{
	Deque deq;
	DequeInit(&deq);
	if(DQIsEmpty(&deq))
		puts("Initialized empty deque\n");
	for(int i = 1; i <= 10; i++)
	{
		if(i % 2 == 1)
			DQAddFirst(&deq, i);
		else
			DQAddLast(&deq, i);
	}
	while(!DQIsEmpty(&deq))
	{
		printf("First removed: %d\n", DQRemoveFirst(&deq));
		printf("Last removed: %d\n", DQRemoveLast(&deq));
		printf("First peeking: %d\n", DQPeekFirst(&deq));
		printf("Last peeking: %d\n", DQPeekLast(&deq));
	}
	DQFree(&deq);
	return 0;
}