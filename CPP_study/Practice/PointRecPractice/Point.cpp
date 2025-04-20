#include <iostream>
#include "Point.h"
using std::cout;
using std::endl;
bool Point::SetX(const int& x)
{
	if(x < 0 || x > 100)
	{
		cout << "x position is over bound" << endl;
		return false;
	}
	xpos = x;
	return true;
}
bool Point::SetY(const int& y)
{
	if(y < 0 || y > 100)
	{
		cout << "y position is over bound" << endl;
		return false;
	}
	ypos = y;
	return true;
}
void Point::ShowPoint() const
{
	cout << "[" << xpos << ", " << ypos << "]" << endl;
	return;
}