#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "Point.h"
class Circle
{
private:
	Point center;
	int radius;
public:
	Circle(const int& x, const int& y, const int& r)
		:center(x, y), radius(r)
	{ /* empty constructor */ }
	Point& GetCenter() const
	{
		Point* temp = new Point(center.GetX(), center.GetY());
		return *temp;
	}
	inline int GetRadius() const
	{
		return radius;
	}
	void ShowCenter() const
	{
		center.ShowPointInfo();
		return;
	}
};

#endif