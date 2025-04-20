#include <iostream>
#include "FruitSeller.h"
#include "FruitBuyer.h"
using std::cout;
using std::endl;
int main(int argc, char** argv)
{
	FruitSeller seller(1000, 20, 0);
	FruitBuyer buyer(5000, 3);
	buyer.BuyApples(seller, 2000);
	cout << "과일 판매자의 현황" << endl;
	seller.ShowSalesResult();
	cout << "과일 구매자의 현황" << endl;
	buyer.ShowBuyResult();
	return 0;
}