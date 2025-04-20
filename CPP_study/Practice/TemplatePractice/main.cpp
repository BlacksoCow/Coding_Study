#include <iostream>
#include "Point.h"
using namespace std;
ostream& operator<<(ostream& os, const Point<int>& pos)
{
	os << "[" << pos.xpos << ", " << pos.ypos << "]";
	return os;
}
ostream& operator<<(ostream& os, const Point<double>& pos)
{
	os << "[" << pos.xpos << ", " << pos.ypos << "]";
	return os;
}
ostream& operator<<(ostream& os, const Point<char*>& pos)
{
	os << "[" << pos.str1 << ", " << pos.str2 << "]";
	return os;
}
int main(int argc, char** argv)
{
	Point<int> pos1(2, 9), pos2(9, 2);
	Point<int> pos3;
	cout << "Static int: " << pos1.GetNum() << endl;
	pos3 = pos1 + pos2;
	cout << "pos3: " << pos3 << endl;
	
	Point<double> pos4(4.6, 2.7);
	Point<double> pos5;
	pos5 = pos4;
	cout << "pos5: " << pos5 << endl;
	
	Point<char*> p1("Han", "kwanwoo ");
	Point<char*> p2("Ryu", "Kyungmin");
	Point<char*> p3 = p1;
	Point<char*> p4, p5;
	p4 = p2;
	p5 = p3 + p4;
	cout << "p1 & p3: " << p1 << p3 << endl;
	cout << "p2 & p4: " << p2 << p4 << endl;
	cout << "p5; " << p5 << endl;
	cout << "Static int: " << pos1.GetNum() << endl;
	cout << "Static double: " << pos5.GetNum() << endl;
	cout << "Static char*: " << p3.GetNum() << endl;
	return 0;
}