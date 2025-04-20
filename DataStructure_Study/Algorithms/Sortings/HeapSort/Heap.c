#include "Heap.h"
void HeapInit(Heap* hp, PriorityComp cpfunc)
{
	hp->numOfData = 0;
	hp->cp = cpfunc;
	return;
}
int HIsEmpty(Heap* hp)
{
	return (hp->numOfData == 0) ? TRUE : FALSE; 
}
int GetParentIdx(int idx)
{
	return idx / 2;
}
int GetLChildIdx(int idx)
{
	return idx * 2;
}
int GetRChildIdx(int idx)
{
	return idx * 2 + 1;
}
int GetHiPriChildIdx(Heap* hp, int idx)
{
	int left = GetLChildIdx(idx);
	int right = GetRChildIdx(idx);
	if(left > hp->numOfData)
		return 0; // When no child node exists
	else if (left == hp->numOfData)
		return left; // When only one child node exists
	else if(hp->cp(hp->heapArr[left], hp->heapArr[right]) >= 0)
		return left;
	else
		return right;
}
void HInsert(Heap* hp, HData data)
{
	int index = hp->numOfData + 1;
	HData compdata;
	while(index != 1)
	{
		compdata = hp->heapArr[GetParentIdx(index)];
		if(hp->cp(data, compdata) > 0)
		{
			hp->heapArr[index] = compdata;
			index = GetParentIdx(index);
		}
		else
			break;
	}
	hp->heapArr[index] = data;
	(hp->numOfData)++;
	return;
}
HData HDelete(Heap* hp)
{
	HData retData = hp->heapArr[1];
	HData last = hp->heapArr[hp->numOfData];
	int curIdx = 1;
	int childIdx;
	while(childIdx = GetHiPriChildIdx(hp, curIdx))
	{
		if(hp->cp(last, hp->heapArr[childIdx]) < 0)
		{
			hp->heapArr[curIdx] = hp->heapArr[childIdx];
			curIdx = childIdx;
		}
		else
			break;
	}
	hp->heapArr[curIdx] = last;
	(hp->numOfData)--;
	return retData;
}