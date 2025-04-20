#include <iostream>
#include "Account.h"
using namespace std;
void MakeAccount(Account* account)
{
	cout << "[Make Account]" << endl;
	cout << "Input account ID: ";
	cin >> account->ID;
	cin.ignore();
	cout << "Input account's name: ";
	cin.getline(account->name, MAXLEN + 1);
	cout << "Initial deposit amount: ";
	cin >> account->money;
	cin.ignore();
	return;
}
bool FindAccount(Account account[], int ID, int index)
{
	for(int i = 0; i < index; i++)
	{
		if(account[i].ID == ID)
			return true;
	}
	return false;
}
void Deposition(Account account[], int index)
{
	int ID, amount;
	cout << "[Deposit]" << endl;
	cout << "Input ID: ";
	cin >> ID;
	cin.ignore();
	if(!(FindAccount(account, ID, index)))
		cout << "Inavailable ID" << endl;
	else
	{
		cout << "Input deposit amount: ";
		cin >> amount;
		cin.ignore();
		for(int i = 0; i < index; i++)
		{
			if(account[i].ID == ID)
			{
				account[i].money += amount;
				cout << "Deposit success" << endl;
				break;
			}
		}
	}
	return;
}
void WithDraw(Account account[], int index)
{
	int ID, amount;
	cout << "[WithDraw]" << endl;
	cout << "Input ID: ";
	cin >> ID;
	cin.ignore();
	if(!(FindAccount(account, ID, index)))
	{
		cout << "Inavailable ID" << endl;
		return;
	}
	cout << "Input withdraw amount: ";
	cin >> amount;
	cin.ignore();
	for(int i = 0; i < index; i++)
	{
		if(account[i].ID == ID)
		{
			if(amount > account[i].money)
			{
				cout << "Your balance is ";
				cout << account[i].money << endl;
				cout << "Withdraw failed" << endl;
				return;
			}
			account[i].money -= amount;
			cout << "Withdraw success" << endl;
			return;
		}
	}
}
void PrintInfo(Account account[], int index)
{
	cout << "[Account information]" << endl;
	for(int i = 0; i < index; i++)
	{
		cout << "ID: " << account[i].ID << endl;
		cout << "Name: " << account[i].name << endl;
		cout << "Balance: " << account[i].money << endl;
		cout << endl;
	}
	cout << "All information printed" << endl;
	return;
}