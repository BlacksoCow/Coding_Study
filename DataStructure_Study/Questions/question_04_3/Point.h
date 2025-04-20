#ifndef __POINT_H__
#define __POINT_H__

#define TRUE 1;
#define FALSE 0;
typedef struct __point
{
	int xpos;
	int ypos;
} Point;

void SetPointPos(Point* pos, int x, int y);
void ShowPoint(Point* p);
int PointComp(Point* p1, Point* p2);

#endif