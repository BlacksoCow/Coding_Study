#include <iostream>
#include <cstring>
#include "Account.h"
#define MAXIMUM 100
using namespace std;
enum {Make = 1, Deposit, Withdraw, Print, Exit};
int main(int argc, char** argv)
{
	int option, index = 0;
	Account account[MAXIMUM];
	while(true)
	{
		cout << "-----Menu-----" << endl;
		cout << "1. Make Account" << endl;
		cout << "2. Deposit" << endl;
		cout << "3. Withdraw" << endl;
		cout << "4. Print Information" << endl;
		cout << "5. Exit Program" << endl;
		cout << "Option: ";
		cin >> option;
		cin.ignore();
		switch(option)
		{
			case Make:
				if(index >= MAXIMUM)
				{
					cout << "Maximun accounts\n" << endl;
					break;
				}
				MakeAccount(&(account[index++]));
				cout << endl;
				break;
			case Deposit:
				Deposition(account, index);
				cout << endl;
				break;
			case Withdraw:
				WithDraw(account, index);
				cout << endl;
				break;
			case Print:
				PrintInfo(account, index);
				break;
			case Exit:
				cout << "End Program" << endl;
				return 0;
			default:
				cout << "Wrong option selcted" << endl;
				cout << endl;
		}
	}
}