#ifndef __RING_H__
#define __RING_H__

#include "Circle.h"
class Ring
{
private:
	Circle Inner, Outer;
public:
	Ring(const int& InX, const int& InY, const int& InR,
		 const int& OutX, const int& OutY, const int& OutR)
		:Inner(InX, InY, InR), Outer(OutX, OutY, OutR)
	{ /* empty constructor */ }
	Circle& GetInner() const
	{
		Circle* In = new Circle(Inner.GetCenter().GetX(), Inner.GetCenter().GetY(), Inner.GetRadius());
		return *In;
	}
	Circle& GetOuter() const
	{
		Circle* Out = new Circle(Outer.GetCenter().GetX(), Outer.GetCenter().GetY(), Outer.GetRadius());
		return *Out;
	}
	void ShowRingInfo() const
	{
		cout << "Inner Circle Info" << endl;
		cout << "Radius : " << Inner.GetRadius() << endl;
		cout << "Center : ";
		Inner.ShowCenter();
		cout << "Outer Circle Info" << endl;
		cout << "Radius : " << Outer.GetRadius() << endl;
		Outer.ShowCenter();
		return;
	}
};

#endif