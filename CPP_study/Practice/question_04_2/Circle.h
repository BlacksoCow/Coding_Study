#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "Point.h"
class Circle
{
private:
	Point center;
	int radius;
public:
	void Init(const int& x, const int& y, const int& r)
	{
		center.Init(x, y);
		radius = r;
		return;
	}
	Point& GetCenter() const
	{
		Point* temp = new Point;
		temp->Init(center.GetX(), center.GetY());
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