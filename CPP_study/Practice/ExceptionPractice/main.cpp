#include <iostream>
#include "Account.h"
using namespace std;
int main(int argc, char** argv)
{
	Account acc("010-3735-9897", 10000);
	acc.ShowInfo();
	try
	{
		acc.Deposit(-100); // Exception occured: Ignore below code
		acc.Deposit(3500);
	}
	catch(AccountException& aexp) // Copy constructor called
	{
		aexp.ShowError();
	}
	catch(...)
	{
		cout << "Unexpected error occured" << endl;
	}
	acc.ShowInfo();
	try
	{
		acc.Withdraw(2500);
		acc.Withdraw(-10000);
	}
	catch(AccountException& aexp) // Copy constructor called
	{
		aexp.ShowError();
	}
	catch(...)
	{
		cout << "Unexpected error occured" << endl;
	}
	acc.ShowInfo();
	return 0;
}