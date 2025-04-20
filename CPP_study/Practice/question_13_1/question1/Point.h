#ifndef __POINT_H__
#define __POINT_H__

#include <iostream>
using namespace std;
class Point
{
private:
	int xpos;
	int ypos;
public:
	Point(const int& x = 0, const int& y = 0)
		:xpos(x), ypos(y)
	{ /* Empty constructor */ }
	Point(const Point& p)
		:xpos(p.xpos), ypos(p.ypos)
	{ /* Empty copy constructor */ }
	Point& operator=(const Point&); // Assignment operator
	friend istream& operator>>(istream&, Point&);
	friend ostream& operator<<(ostream&, const Point&);
	~Point()
	{ /* Empty destructor */ }
};
	
#endif