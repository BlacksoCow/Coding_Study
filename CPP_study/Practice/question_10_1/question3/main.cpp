#include <iostream>
#include "Point.h"
using namespace std;
bool operator==(const Point& p1, const Point& p2)
{
	return (p1.xpos == p2.xpos && p1.ypos == p2.ypos);
}
bool operator!=(const Point& p1, const Point& p2)
{
	return (p1.xpos != p2.xpos || p1.ypos != p2.ypos);
}
int main(int argc, char** argv)
{
	Point p1(3, 5);
	Point p2(4, 5);
	Point p3(3, 5);
	if(p1 == p3)
		cout << "Same" << endl;
	if(p2 != p1)
		cout << "Different" << endl;
	if(p2 == p3)
		cout << "This should not be printed" << endl;
	return 0;
}