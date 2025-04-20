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
	Point() { } // Default constructor
	Point(const int& x, const int& y)
		:xpos(x), ypos(y)
	{ /* Empty constructor */ }
	Point(const Point& p)
		:xpos(p.xpos), ypos(p.ypos)
	{ /* Empty copy constructor */ }
	Point& operator++();
	const Point operator++(int);
	Point operator*(const int&);
	friend Point& operator--(Point&);
	friend const Point operator--(Point&, int);
	friend istream& operator>>(istream&, Point&);
	friend ostream& operator<<(ostream&, const Point&);
	void ShowPoint() const;
	~Point()
	{ /* Empty destructor */ }
};
	
#endif