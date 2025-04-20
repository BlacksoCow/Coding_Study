#include <iostream>
#include "Account.h"
#include "AccountHandler.h"
using namespace std;
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
	int option;
	AccountHandler handler;
	while(true)
	{
		PrintMenu();
		cin >> option;
		cin.ignore();
		cout << endl;
		switch(option)
		{
			case OPTION::MAKE:
				if(handler.GetIndex() >= MAXIMUM)
				{
					cout << "Account at maximum";
					cout << endl << endl;
					break;
				}
				handler.MakeAccount();
				break;
			case OPTION::DEPOSIT:
				handler.Deposit();
				break;
			case OPTION::WITHDRAW:
				handler.Withdraw();
				break;
			case OPTION::PRINT:
				handler.ShowAll();
				break;
			case OPTION::EXIT:
				cout << "Exit program" << endl;
				return 0;
			default:
				cout << "Wrong option selected\n";
				cout << "Option is 1 to 5";
				cout << endl << endl;
		}
	}
}