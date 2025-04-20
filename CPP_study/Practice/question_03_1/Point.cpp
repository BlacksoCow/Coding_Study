#include <iostream>
#include "Point.h"
using namespace std;
void Point::MovePos(int x, int y)
{
	xpos += x;
	ypos += y;
	return;
}
void Point::ShowPosition()
{
	cout << "Point: ";
	cout << "[" << xpos << ", " << ypos << "]";
	cout << endl;
	return;
}