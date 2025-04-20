#ifndef __HYBRIDCAR_H__
#define __HYBRIDCAR_H__

#include "Car.h"
class HybridCar: public Car
{
private:
	int electricGauge;
public:
	HybridCar(const int& gas, const int& elec)
		:Car(gas), electricGauge(elec)
	{
		cout << "HybridCar constructor called" << endl;
	}
	int GetElecGauge() const;
	~HybridCar()
	{
		cout << "HybridCar destructor called" << endl;
	}
};

#endif