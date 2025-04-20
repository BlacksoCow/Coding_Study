#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

class Rectangle
{
private:
	int horizontal;
	int vertical;
public:
	Rectangle(const int& hor, const int& ver)
		:horizontal(hor), vertical(ver)
	{ /* Empty constructor */ }
	void ShowAreaInfo() const;
	~Rectangle()
	{ /* Empty destructor */ }
};
#endif