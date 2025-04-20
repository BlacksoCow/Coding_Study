#include <iostream>
#include "Account.h"
#include "AccountFunc.h"
#define MAXIMUM 100
using namespace std;
using namespace ACCOUNTFUNC;
inline void PrintMenu()
{
	cout << "-----Menu-----" << endl;
	cout << "1. Make Account" << endl;
	cout << "2. Deposit" << endl;
	cout << "3. Withdraw" << endl;
	cout << "4. Print Information" << endl;
	cout << "5. Exit Program" << endl;
	cout << "Option: ";
	return;
}
int main(int argc, char** argv)
{
	int option, index = 0;
	Account* account[MAXIMUM];
	while(true)
	{
		PrintMenu();
		cin >> option;
		cin.ignore();
		cout << endl;
		switch(option)
		{
			case OPTION::MAKE:
				if(index >= MAXIMUM)
				{
					cout << "Account at maximum";
					cout << endl << endl;
					break;
				}
				account[index++] = MakeAccount();
				break;
			case OPTION::DEPOSIT:
				Deposit(account, index);
				break;
			case OPTION::WITHDRAW:
				Withdraw(account, index);
				break;
			case OPTION::PRINT:
				ShowAll(account, index);
				break;
			case OPTION::EXIT:
				for(int i = 0; i < index; i++)
					delete account[i];
				cout << "Exit program" << endl;
				return 0;
			default:
				cout << "Wrong option selected\n";
				cout << "Option is 1 to 5";
				cout << endl << endl;
		}
	}
}