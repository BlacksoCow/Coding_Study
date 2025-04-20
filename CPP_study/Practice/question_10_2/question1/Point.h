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
	friend Point operator-(const Point&);
	void ShowPoint() const
	{
		cout << "[" << xpos << ", " << ypos <<  "]" << endl;
		return;
	}
	~Point()
	{ /* Empty destructor */ }
};
	
#endif