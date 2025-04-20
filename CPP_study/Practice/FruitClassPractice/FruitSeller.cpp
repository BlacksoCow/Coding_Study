#include <iostream>
#include "FruitSeller.h"
using std::cout;
using std::endl;
int FruitSeller::SellApples(const int& pay)
{
	if(!LeftApples)
	{
		cout << "No apples left" << endl;
		return 0;
	}
	int give = pay / Apple_Price;
	if (LeftApples < give)
		give = LeftApples;
	LeftApples -= give;
	money += (Apple_Price * give);
	return give;
}
void FruitSeller::ShowSalesResult()
{
	cout << "사과 가격: " << Apple_Price << endl;
	cout << "남은 사과: " << LeftApples << endl;
	cout << "남은 잔액: " << money << endl;
	return;
}