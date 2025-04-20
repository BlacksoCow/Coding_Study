#include <iostream>
#include "Account.h"
using std::cout;
using std::endl;
void Account::Deposit(const int& deposit)
{
	money += deposit;
	return;
}
void Account::Withdraw(const int& withdraw)
{
	money -= withdraw;
	return;
}
void Account::ShowInfo() const
{
	cout << "Account owner: " << name << endl;
	cout << "Account ID: " << ID << endl;
	cout << "Balance: " << money << endl;
	cout << endl;
	return;
}