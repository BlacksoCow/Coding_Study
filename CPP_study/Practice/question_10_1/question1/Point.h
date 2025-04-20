#ifndef __POINT_H__
#define __POINT_H__

#include <iostream>
using std::cout;
using std::endl;
class Point
{
private:
	int xpos;
	int ypos;
public:
	Point(const int& x, const int& y)
		:xpos(x), ypos(y)
	{ /* Empty constructor */ }
	Point(const Point& p)
		:xpos(p.xpos), ypos(p.ypos)
	{ /* Empty copy constructor */ }
	Point operator-(const Point& p) const
	{
		Point pos(xpos - p.xpos , ypos - p.ypos);
		return pos; // Copy constructor is not called because of NRVO
	}
	void ShowPoint() const
	{
		cout << "[" << xpos << ", " << ypos <<  "]" << endl;
		return;
	}
	// friend Point operator-(const Point& pos1, const Point& pos2);
	~Point()
	{ /* Empty destructor */ }
};
	
#endif