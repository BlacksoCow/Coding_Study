#include <stdio.h>
#include <stdlib.h>
#include "SimpleLinkedList.h"
#include "Point.h"
int main(int argc, char** argv)
{
	List list;
	Point* compPos = (Point*)malloc(sizeof(Point));
	Point* pos;
	ListInit(&list);
	pos = (Point*)malloc(sizeof(Point));
	SetPointPos(pos, 2, 1);
	LInsert(&list, pos);
	pos = (Point*)malloc(sizeof(Point));
	SetPointPos(pos, 4, 3);
	LInsert(&list, pos);
	pos = (Point*)malloc(sizeof(Point));
	SetPointPos(pos, 2, 5);
	LInsert(&list, pos);
	pos = (Point*)malloc(sizeof(Point));
	SetPointPos(pos, 8, 7);
	LInsert(&list, pos);
	printf("Number of datas: %d\n", LCount(&list));
	if(LFirst(&list, &pos))
	{
		do
		{
			ShowPoint(pos);
		} while(LNext(&list, &pos));
	}
	else
	{
		puts("List is empty");
		return 0;
	}
	SetPointPos(compPos, 2, 5);
	if(LFirst(&list, &pos))
	{
		do
		{
			if(!(PointComp(pos, compPos)))
			{
				LRemove(&list);
				fputs("Removed data: ", stdout);
				ShowPoint(pos);
			}
		} while(LNext(&list, &pos));
	}
	printf("Number of datas left: %d\n", LCount(&list));
	free(compPos);
	return 0;
}