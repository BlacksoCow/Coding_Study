#include <iostream>
#include "Point.h"
using namespace std;
Point operator-(const Point& p)
{
	Point pos(-p.xpos, -p.ypos);
	return pos;
}
int main(int argc, char** argv)
{
	Point p1(10, 12);
	Point p2 = -p1;
	Point p3 = -(-p1);
	p1.ShowPoint();
	p2.ShowPoint();
	p3.ShowPoint();
	return 0;
}