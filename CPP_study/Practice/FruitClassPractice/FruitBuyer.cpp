#include <iostream>
#include "FruitBuyer.h"
using std::cout;
using std::endl;
void FruitBuyer::BuyApples(FruitSeller& seller, const int& pay)
{
	int bought = seller.SellApples(pay);
	money -= seller.GetPrice() * bought;
	Current_Apples += bought;
	return;
}
void FruitBuyer::ShowBuyResult() const
{
	cout << "현재 사과: " << Current_Apples << endl;
	cout << "남은 잔액: " << money << endl;
	return;
}