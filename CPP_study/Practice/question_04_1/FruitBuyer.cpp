#include <iostream>
#include "FruitBuyer.h"
using std::cout;
using std::endl;
void FruitBuyer::InitMembers(const int& a)
{
	money = a;
	Current_Apples = 0;
	return;
}
bool FruitBuyer::BuyApples(FruitSeller& seller, const int& pay)
{
	if(pay < 0)
	{
		cout << "Pay cannot be under 0" << endl;
		return false;
	}
	const int bought = seller.SellApples(pay);
	money -= seller.GetPrice() * bought;
	Current_Apples += bought;
	return true;
}
void FruitBuyer::ShowBuyResult() const
{
	cout << "현재 사과: " << Current_Apples << endl;
	cout << "남은 잔액: " << money << endl;
	return;
}