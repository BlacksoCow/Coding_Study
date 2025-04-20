#include "Ring.h"
int main(int argc, char** argv)
{
	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	Circle& c1 = ring.GetInner();
	cout << "c1 center: ";
	c1.ShowCenter();
	Point& p1 = c1.GetCenter();
	cout << "p1 : ";
	p1.ShowPointInfo();
	int r1 = ring.GetOuter().GetRadius();
	cout << "r1 : " << r1 << endl;
	delete &c1;
	delete &p1;
	return 0;
}