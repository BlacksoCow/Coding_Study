#include <stdio.h>
#include "Point.h"
void SetPointPos(Point* pos, int x, int y)
{
	pos->xpos = x;
	pos->ypos = y;
	return;
}
void ShowPoint(Point* p)
{
	printf("[%d, %d]\n", p->xpos, p->ypos);
	return;
}
int PointComp(Point* p1, Point* p2)
{
	if((p1->xpos == p2->xpos) && (p1->ypos == p2->ypos))
		return TRUE;
	return FALSE;
}