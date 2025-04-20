#ifndef __POINT_H__
#define __POINT_H__

#include <iostream>
using std::cout;
using std::endl;
class Point
{
private:
	int xpos, ypos;
public:
	Point(const int& x, const int& y)
		:xpos(x), ypos(y)
	{ /* empty constructor */ }
	inline int GetX() const
	{
		return xpos;
	}
	inline int GetY() const
	{
		return ypos;
	}
	inline void ShowPointInfo() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
		return;
	}
};

#endif