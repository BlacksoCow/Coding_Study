#ifndef __POINT_H__
#define __POINT_H__

#include <iostream>
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
	Point& operator=(const Point& p)
	{
		xpos = p.xpos;
		ypos = p.ypos;
		return *this;
	} // Assignment operator
	inline int GetX() const { return xpos; }
	inline int GetY() const { return ypos; }
	friend std::ostream& operator<<(std::ostream& os, const Point& p);
	~Point()
	{ /* Empty destructor */ }
};

#endif