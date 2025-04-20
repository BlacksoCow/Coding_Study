#ifndef __POINT_H__
#define __POINT_H__

class Point
{
private:
	int xpos;
	int ypos;
public:
	Point(const int& x, const int& y)
		:xpos(x), ypos(y)
	{ /* empty constructor */ }
	int GetX() const { return xpos; }
	int GetY() const { return ypos; }
	bool SetX(const int&);
	bool SetY(const int&);
	void ShowPoint() const;
};

#endif