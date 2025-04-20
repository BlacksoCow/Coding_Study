#include <iostream>
#include "BoundIntArray.h"
#include "BoundPointArray.h"
using namespace std;
ostream& operator<<(ostream& os, const Point& p)
{
	os << "[" << p.xpos << ", " << p.ypos << "]";
	return os;
}
int main(int argc, char** argv)
{
	BoundIntArray arr(5);
	for(int i = 0; i < 5; i++)
		arr[i] = (i + 1) * 11;
	arr.ShowAllData();
	BoundPointArray parr(5);
	for(int i = 0; i < 5; i++)
		parr[i] = new Point(i + 1, 2 * i + 2);
	parr.ShowAllData();
	for(int i = 0; i < 5; i++)
		delete parr[i];
	return 0;
}