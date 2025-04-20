#ifndef __FRUITSELLER_H__
#define __FRUITSELLER_H__

class FruitSeller
{
private:
	int Apple_Price;
	int LeftApples;
	int money;
public:
	void InitMembers(const int&, const int&, const int&);
	int GetPrice() const
	{ return Apple_Price; }
	int GetLeftApples() const
	{ return LeftApples; }
	int GetMoney() const
	{ return money; }
	int SellApples(const int&);
	void ShowSalesResult() const;
};

#endif