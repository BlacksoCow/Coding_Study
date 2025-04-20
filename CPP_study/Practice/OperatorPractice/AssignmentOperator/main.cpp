#include "IOS.h"
#include "Point.h"
using mystd::cout;
using mystd::endl;
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
int main(int argc, char** argv)
{
	Point p1(1, 2);
	Point p2(3, 4);
	Point p3(10, 11);
	Point p4(12, 13);
	
	++(++(++p1));
	cout << "p1: ";
	p1.ShowPoint();
	
	p2++;
	cout << "p2: ";
	p2.ShowPoint();
	
	--(--(--p3));
	cout << "p3: ";
	p3.ShowPoint();
	
	p4--;
	cout << "p4: ";
	p4.ShowPoint();
	
	Point p5 = p1 * 5;
	Point p6 = 5 * p1;
	
	cout << "p5: ";
	p5.ShowPoint();
	cout << "p6: ";
	p6.ShowPoint();
	
	return 0;
}