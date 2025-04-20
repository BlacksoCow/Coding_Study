#include <iostream>
#include "Point.h"
using namespace std;
/* Point operator-(const Point& pos1, const Point& pos2)
{
	Point pos(pos1.xpos - pos2.xpos, pos2.ypos - pos2.ypos);
	return pos;
} */
int main(int argc, char** argv)
{
	Point pos1(3, 4);
	Point pos2(5, 10);
	Point pos3 = pos1 - pos2;
	pos3.ShowPoint();
	return 0;
}