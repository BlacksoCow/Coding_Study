#include <stdio.h>
#include <stdlib.h>
#include "SimpleLinkedList.h"
#include "Point.h"
int WhoPrecedes(Point* p1, Point* p2)
{
	if(p1->xpos > p2->xpos)
		return 1;
	else if (p1->xpos == p2->xpos)
	{
		if(p1->ypos > p2->ypos)
			return 1;
		else
			return 0;
	}
	else
		return 0;
}
int main(int argc, char** argv)
{
	List list;
	Point* compPos = (Point*)malloc(sizeof(Point));
	Point* pos;
	ListInit(&list);
	SetSortRule(&list, WhoPrecedes);
	pos = (Point*)malloc(sizeof(Point));
	SetPointPos(pos, 2, 1);
	LInsert(&list, pos);
	pos = (Point*)malloc(sizeof(Point));
	SetPointPos(pos, 4, 3);
	LInsert(&list, pos);
	pos = (Point*)malloc(sizeof(Point));
	SetPointPos(pos, 3, 4);
	LInsert(&list, pos);
	pos = (Point*)malloc(sizeof(Point));
	SetPointPos(pos, 9, 8);
	LInsert(&list, pos);
	pos = (Point*)malloc(sizeof(Point));
	SetPointPos(pos, 2, 3);
	LInsert(&list, pos);
	pos = (Point*)malloc(sizeof(Point));
	SetPointPos(pos, 2, 2);
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
	} // If list is empty, after code is meaningless
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
	} // Deleting specific points
	printf("Number of datas left: %d\n", LCount(&list));
	free(compPos);
	RemoveAll(&list);
	puts("Removed all data");
	return 0;
}