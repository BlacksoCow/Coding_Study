#include <iostream>
#include "Rectangle.h"
using std::cout;
void Rectangle::ShowRecInfo() const
{
	cout << "Upleft: ";
	UpLeft.ShowPoint();
	cout << "LowRight: ";
	LowRight.ShowPoint();
	return;
}