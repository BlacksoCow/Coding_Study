#ifndef __SQUARE_H__
#define __SQUARE_H__

class Square: public Rectangle
{
private:
	// No private members
public:
	Square(const int& side)
		:Rectangle(side, side)
	{ /* Empty constructor */ }
	~Square()
	{ /* Empty destructor */ }
};

#endif