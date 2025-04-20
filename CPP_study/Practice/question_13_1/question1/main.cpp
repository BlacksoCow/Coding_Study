#include <iostream>
#include "Point.h"
using namespace std;
istream& operator>>(istream& is, Point& pos)
{
	is >> pos.xpos >> pos.ypos;
	return is;
}
ostream& operator<<(ostream& os, const Point& pos)
{
	os << "[" << pos.xpos << ", " << pos.ypos << "]";
	return os;
}
template <typename T>
void SwapData(T& var1, T& var2)
{
	T temp = var1;
	var1 = var2;
	var2 = temp;
	return;
}
int main(int argc, char** argv)
{
	Point pos1(5, 6);
	Point pos2(-6, -5);
	cout << pos1 << pos2 << endl;
	SwapData<Point>(pos1, pos2);
	cout << pos1 << pos2 << endl;
	return 0;
}