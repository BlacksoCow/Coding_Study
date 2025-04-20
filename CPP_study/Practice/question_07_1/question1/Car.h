#ifndef __CAR_H__
#define __CAR_H__

#include <iostream>
using std::cout;
using std::endl;
class Car
{
private:
	int gasolineGauge;
public:
	Car(const int& gas)
		:gasolineGauge(gas)
	{
		cout << "Car constructor called" << endl;
	}
	int GetGasGauge() const;
	~Car()
	{
		cout << "Car destructor called" << endl;
	}
};

#endif