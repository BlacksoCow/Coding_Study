#include <iostream>
#include "HybridWaterCar.h"
int main(int argc, char** argv)
{
	HybridWaterCar hwc(100, 200, 300);
	hwc.ShowCurrentGauge();
	return 0;
}