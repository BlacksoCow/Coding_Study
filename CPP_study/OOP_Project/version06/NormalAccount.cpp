#include <iostream>
#include "NormalAccount.h"
using std::cout;
using std::endl;
void NormalAccount::Deposit(const int& deposit)
{
	int dp = int(deposit * (1 + 0.01 * GetRate()));
	Account::Deposit(dp);
	return;
}
void NormalAccount::ShowInfo() const
{
	cout << "Account type: Normal Account" << endl;
	Account::ShowInfo();
	return;
}