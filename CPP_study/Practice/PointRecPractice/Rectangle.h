#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include "Point.h"
class Rectangle
{
private:
	Point UpLeft;
	Point LowRight;
public:
	Rectangle(const int& UpX, const int& UpY, const int& LowX, const int& LowY)
		:UpLeft(UpX, UpY), LowRight(LowX, LowY)
	{ /* empty constructor */ }
	void ShowRecInfo() const;
};

#endif