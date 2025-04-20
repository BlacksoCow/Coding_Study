#include "DequeQueue.h"
void QueueInit(Queue* pq)
{
	return DequeInit(pq->deq);
}
int QIsEmpty(Queue* pq)
{
	return DQIsEmpty(pq->deq);
}
void EnQueue(Queue* pq, Data data)
{
	return DQAddLast(pq->deq, data);
}
Data DeQueue(Queue* pq)
{
	return DQRemoveFirst(pq->deq);
}
Data QPeek(Queue* pq)
{
	return DQPeekFirst(pq->deq);
}
void QFree(Queue* pq)
{
	return DQFree(pq->deq);
}