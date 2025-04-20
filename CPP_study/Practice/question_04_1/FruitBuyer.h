#ifndef __FRUITBUYER_H__
#define __FRUITBUYER_H__

#include "FruitSeller.h"
class FruitBuyer
{
private:
	int money;
	int Current_Apples;
public:
	void InitMembers(const int&);
	bool BuyApples(FruitSeller&, const int&);
	void ShowBuyResult() const;
};

#endif