#include <iostream>
#include "NormalAccount.h"
using std::cout;
using std::endl;
void NormalAccount::Deposit(const int& deposit)
{
	Account::Deposit(int(deposit * (1 + percentage * 0.01)));
	return;
}
void NormalAccount::ShowInfo() const
{
	cout << "Account type: Normal Account" << endl;
	cout << "Interrate: " << percentage << "%" << endl;
	Account::ShowInfo();
	return;
}