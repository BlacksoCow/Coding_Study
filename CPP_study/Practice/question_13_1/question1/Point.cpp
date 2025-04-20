#include "Point.h"
Point& Point::operator=(const Point& pos)
{
	xpos = pos.xpos;
	ypos = pos.ypos;
	return *this;
}