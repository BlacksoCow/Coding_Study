#include <iostream>
#include "FruitSeller.h"
#include "FruitBuyer.h"
using std::cout;
using std::endl;
int main(int argc, char** argv)
{
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	if(buyer.BuyApples(seller, 2000))
	{
		cout << "과일 판매자의 현황" << endl;
		seller.ShowSalesResult();
		cout << "과일 구매자의 현황" << endl;
		buyer.ShowBuyResult();
	}
	else
		cout << "Parameter error" << endl;
	return 0;
}