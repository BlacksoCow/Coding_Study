#ifndef __HYBRIDWATERCAR_H__
#define __HYBRIDWATERCAR_H__

#include "HybridCar.h"
class HybridWaterCar: public HybridCar
{
private:
	int waterGauge;
public:
	HybridWaterCar(const int& gas, const int& elec, const int& water)
		:HybridCar(gas, elec), waterGauge(water)
	{
		cout << "HybridWaterCar constructor called" << endl;
	}
	void ShowCurrentGauge() const;
	~HybridWaterCar()
	{
		cout << "HybridWaterCar desturctor called" << endl;
	}
};

#endif