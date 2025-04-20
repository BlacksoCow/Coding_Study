#include <iostream>
#include "Rectangle.h"
#include "Square.h"
using namespace std;
int main(int argc, char** argv)
{
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();
	Square sqr(7);
	sqr.ShowAreaInfo();
	return 0;
}