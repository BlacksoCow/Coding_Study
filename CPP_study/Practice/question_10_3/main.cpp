#include <iostream>
#include "Point.h"
using namespace std;
Point& operator--(Point& pos)
{
	pos.xpos--;
	pos.ypos--;
	return pos;
}
const Point operator--(Point& pos, int)
{
	const Point ret(pos.xpos, pos.ypos);
	pos.xpos--;
	pos.ypos--;
	return ret;
}
Point operator*(int times, Point& pos)
{
	return pos * times;
}
ostream& operator<<(ostream& ostm, const Point& pos)
{
	pos.ShowPoint();
	return ostm;
}
istream& operator>>(istream& istm, Point& pos)
{
	istm >> pos.xpos >> pos.ypos;
	return istm;
}
int main(int argc, char** argv)
{
	Point pos1;
	cout << "Input xpos, ypos: ";
	cin >> pos1;
	cout << pos1;
	
	Point pos2;
	cout << "Input xpos, ypos: ";
	cin >> pos2;
	cout << pos2;
	
	return 0;
}