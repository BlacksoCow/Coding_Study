#ifndef __TEST_H__
#define __TEST_H__

#include <iostream>
using std::cout;
using std::endl;
class Base
{
private:
	int num1;
public:
	Base(const int& num1)
		:num1(num1)
	{ /* Empty constructor */ }
	Base(const Base& base)
		:num1(base.num1)
	{ /* Empty copy constructor */ }
	/*virtual*/ void ShowNum() const
	{
		cout << "Num: " << num1 << endl;
		return;
	}
};

class Derived: public Base
{
private:
	int num2;
public:
	Derived(const int& num1, const int& num2)
		:Base(num1), num2(num2)
	{ /* Empty constructor */ }
	Derived(const Derived& der)
		:Base(der), num2(der.num2)
	{ /* Empty copy constructor */ }
	void ShowNum() const //override
	{
		Base::ShowNum();
		cout << "Num: " << num2 << endl;
		return;
	}
};

#endif