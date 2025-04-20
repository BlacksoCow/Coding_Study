#include "Point.h"
Point& Point::operator++()
{
	xpos++;
	ypos++;
	return *this;
}
const Point Point::operator++(int)
{
	const Point ret = *this;
	xpos++;
	ypos++;
	return ret;
}
Point Point::operator*(const int& times)
{
	Point pos(xpos * times, ypos * times);
	return pos;
}
void Point::ShowPoint() const
{
	cout << "[" << xpos << ", " << ypos <<  "]" << endl;
	return;
}