#ifndef __FRUITSELLER_H__
#define __FRUITSELLER_H__

class FruitSeller
{
private:
	const int Apple_Price;
	int LeftApples;
	int money;
public:
	FruitSeller(const int& a, const int& b, const int& c)
		:Apple_Price(a), LeftApples(b), money(c)
	{ /* empty constructor */ }
	int GetPrice() { return Apple_Price; }
	int SellApples(const int&);
	void ShowSalesResult();
	~FruitSeller()
	{  /* empty destructor */ }
};


#endif