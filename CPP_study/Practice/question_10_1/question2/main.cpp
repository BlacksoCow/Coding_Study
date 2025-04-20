#include <iostream>
#include "Point.h"
using namespace std;
int main(int argc, char** argv)
{
	Point p1(3, 4);
	Point p2(10, 11);
	p1 += p2 += p1;
	p1.ShowPoint();
	return 0;
}