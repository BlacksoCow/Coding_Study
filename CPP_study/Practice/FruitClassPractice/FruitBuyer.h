#ifndef __FRUITBUYER_H__
#define __FRUITBUYER_H__

#include "FruitSeller.h"
class FruitBuyer
{
private:
	int money;
	int Current_Apples;
public:
	FruitBuyer(const int& Money, const int& apple = 0)
		:money(Money), Current_Apples(apple)
	{ /* empty constructor */ }
	void BuyApples(FruitSeller&, const int&);
	void ShowBuyResult() const;
	~FruitBuyer()
	{ /* empty destructor */ }
};

#endif