#include <iostream>
using namespace std;
typedef struct
{
	int xpos;
	int ypos;
} Point;
Point& PntAdder(const Point&, const Point&);
int main(int argc, char** argv)
{
	Point* p1 = new Point;
	Point* p2 = new Point;
	cout << "Input first point: ";
	cin >> p1 -> xpos >> p1 -> ypos;
	cin.ignore();
	cout << "Input second point: ";
	cin >> p2 -> xpos >> p2 -> ypos;
	cin.ignore();
	Point &p3 = PntAdder(*p1, *p2);
	cout << "Add: " << p3.xpos << ", " << p3.ypos << endl;
	delete p1;
	delete p2;
	delete &p3;
	return 0;
}
Point& PntAdder(const Point& p1, const Point& p2)
{
	Point* point3 = new Point;
	point3->xpos = p1.xpos + p2.xpos;
	point3->ypos = p1.ypos + p2.ypos;
	return *point3;
}