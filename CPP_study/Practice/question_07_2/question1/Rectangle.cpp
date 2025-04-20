#include <iostream>
#include "Rectangle.h"
using std::cout;
using std::endl;
void Rectangle::ShowAreaInfo() const
{
	cout << "Area: " << horizontal * vertical << endl;
	return;
}