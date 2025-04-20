#include "HybridWaterCar.h"
void HybridWaterCar::ShowCurrentGauge() const
{
	cout << "Remaining gasoline: " << GetGasGauge() << endl;
	cout << "Remaining electricity: " << GetElecGauge() << endl;
	cout << "Remaining gasoline: " << waterGauge << endl;
	return;
}