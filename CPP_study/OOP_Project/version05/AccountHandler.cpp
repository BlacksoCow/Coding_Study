#include <iostream>
#include "AccountHandler.h"
#define MAXLEN 20
using namespace std;
void AccountHandler::MakeAccount()
{
	int ID, money;
	char name[MAXLEN + 1];
	cout << "[Create account]" << endl;
	cout << "Input account ID: ";
	cin >> ID;
	cin.ignore();
	cout << "Input account owner's name: ";
	cin.getline(name, MAXLEN + 1);
	cout << "Input seed money: ";
	cin >> money;
	cin.ignore();
	account[index++] = new Account(ID, money, name);
	cout << "Account successfully created";
	cout << endl << endl;
	return;
}
void AccountHandler::Deposit()
{
	int ID;
	cout << "[Deposit]" << endl;
	cout << "Input ID: ";
	cin >> ID;
	cin.ignore();
	for(int i = 0; i < index; i++)
	{
		if(account[i]->GetID() == ID)
		{
			int deposit;
			cout << "Input deposit amount: ";
			cin >> deposit;
			cin.ignore();
			if(deposit <= 0)
			{
				cout << "Inavailable deposit amount\n";
				cout << "Deposit failed";
				cout << endl << endl;
				return;
			}
			account[i]->Deposit(deposit);
			cout << "Deposit successful";
			cout << endl << endl;
			return;
		}
	}
	cout << "Inavailable ID\nDeposit failed";
	cout << endl << endl;
	return;
}
void AccountHandler::Withdraw()
{
	int ID;
	cout << "[Withdraw]" << endl;
	cout << "Input ID: ";
	cin >> ID;
	cin.ignore();
	for(int i = 0; i < index; i++)
	{
		if(account[i]->GetID() == ID)
		{
			int withdraw;
			cout << "Input withdraw amount: ";
			cin >> withdraw;
			cin.ignore();
			if(withdraw <= 0)
			{
				cout << "Inavailable withdraw amount\n";
				cout << "Withdraw failed";
				cout << endl << endl;
				return;
			}
			if(account[i]->GetMoney() < withdraw)
			{
				cout << "Your balance is ";
				cout << account[i]->GetMoney() << endl;
				cout << "Withdraw failed";
				cout << endl << endl;
				return;
			}
			account[i]->Withdraw(withdraw);
			cout << "Withdraw successful";
			cout << endl << endl;
			return;
		}
	}
	cout << "Inavailable ID\nWithdraw failed";
	cout << endl << endl;
	return;
}
void AccountHandler::ShowAll()
{
	if(!index)
	{
		cout << "No data" << endl << endl;
		return;
	}
	for(int i = 0; i < index; i++)
		account[i]->ShowInfo();
	cout << "All information printed";
	cout << endl << endl;
	return;
}