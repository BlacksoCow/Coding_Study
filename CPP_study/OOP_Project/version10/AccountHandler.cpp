#include <iostream>
#include "String.h"
#include "AccountHandler.h"
using namespace std;
void AccountHandler::PrintMenu() const
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
void AccountHandler::MakeAccount()
{
	int type, ID, money, per, rank;
	String name;
	cout << "[Select account type]" << endl;
	cout << "1. NormalAccount  2. HighCreditAccount" << endl;
	cout << "Option: ";
	cin >> type;
	if(cin.fail())
	{
		cout << "Inavailable option" << endl;
		cout << "Creation failed";
		cout << endl << endl;
		cin.clear();
		cin.ignore(IGNORE, '\n');
		return;
	}
	cin.ignore();
	switch(type)
	{
		case Normal:
			cout << "[NormalAccount]" << endl;
			cout << "Input account ID: ";
			cin >> ID;
			if(cin.fail())
			{
				cout << "ID should be composed of only numbers" << endl;
				cout << "Creation failed";
				cout << endl << endl;
				cin.clear();
				cin.ignore(IGNORE, '\n');
				return;
			}
			cin.ignore();
			for(int i = 0; i < index; i++)
			{
				if(account[i]->GetID() == ID)
				{
					cout << "Current ID already exists" << endl;
					cout << "Creation failed";
					cout << endl << endl;
					return;
				}
			}
			cout << "Input account owner's name: ";
			cin >> name;
			if(!name.Length())
			{
				cout << "Name should be at least 1 character" << endl;
				return;
			}
			cout << "Input seed money: ";
			cin >> money;
			if(cin.fail())
			{
				cout << "Inavailable input" << endl;
				cout << "Creation failed";
				cout << endl << endl;
				cin.clear();
				cin.ignore(IGNORE, '\n');
				return;
			}
			cin.ignore();
			if(money <= 0)
			{
				cout << "Inavailable seed money" << endl;
				cout << "Creation failed";
				cout << endl << endl;
				return;
			}
			cout << "Input interrate: ";
			cin >> per;
			if(cin.fail())
			{
				cout << "Inavailable input" << endl;
				cout << "Creation failed";
				cout << endl << endl;
				cin.clear();
				cin.ignore(IGNORE, '\n');
				return;
			}
			cin.ignore();
			if(per <= 0)
			{
				cout << "Inavailable interrate" << endl;
				cout << "Creation failed";
				cout << endl << endl;
				return;
			}
			account[index++] = new NormalAccount(ID, money, name, per);
			cout << "NormalAccount successfully created";
			cout << endl << endl;
			break;
		case HighCredit:
			cout << "[HighCreditAccount]" << endl;
			cout << "Input account ID: ";
			cin >> ID;
			if(cin.fail())
			{
				cout << "ID should be composed of only numbers" << endl;
				cout << "Creation failed";
				cout << endl << endl;
				cin.clear();
				cin.ignore(IGNORE, '\n');
				return;
			}
			cin.ignore();
			for(int i = 0; i < index; i++)
			{
				if(account[i]->GetID() == ID)
				{
					cout << "Current ID already exists" << endl;
					cout << "Creation failed";
					cout << endl << endl;
					return;
				}
			}
			cout << "Input account owner's name: ";
			cin >> name;
			if(!name.Length())
			{
				cout << "Name should be at least 1 character" << endl;
				return;
			}
			cout << "Input seed money: ";
			cin >> money;
			if(cin.fail())
			{
				cout << "Inavailable input" << endl;
				cout << "Creation failed";
				cout << endl << endl;
				cin.clear();
				cin.ignore(IGNORE, '\n');
				return;
			}
			cin.ignore();
			if(money <= 0)
			{
				cout << "Inavailable seed money" << endl;
				cout << "Creation failed";
				cout << endl << endl;
				return;
			}
			cout << "Input interrate: ";
			cin >> per;
			if(cin.fail())
			{
				cout << "Inavailable input" << endl;
				cout << "Creation failed";
				cout << endl << endl;
				cin.clear();
				cin.ignore(IGNORE, '\n');
				return;
			}
			cin.ignore();
			if(per <= 0)
			{
				cout << "Inavailable interrate" << endl;
				cout << "Creation failed";
				cout << endl << endl;
				return;
			}
			cout << "Credit Rank(1toA, 2toB, 3toC): ";
			cin >> rank;
			if(cin.fail())
			{
				cout << "Rank should be expressed with a number" << endl;
				cout << "Creation failed";
				cout << endl << endl;
				cin.clear();
				cin.ignore(IGNORE, '\n');
				return;
			}
			cin.ignore();
			if(!(1 <= rank && rank <= 3))
			{
				cout << "Inavailable rank" << endl;
				cout << "Creation failed";
				cout << endl << endl;
				return;
			}
			switch(rank)
			{
				case 1:
					account[index++] = new HighCreditAccount(ID, money, name, per, RANK::A);
					break;
				case 2:
					account[index++] = new HighCreditAccount(ID, money, name, per, RANK::B);
					break;
				case 3:
					account[index++] = new HighCreditAccount(ID, money, name, per, RANK::C);
					break;
				default:
					cout << "Unexpected error occurred" << endl;
					cout << "Creation failed";
					cout << endl << endl;
					return;
			}
			cout << "HighCreditAccount successfully created";
			cout << endl << endl;
			break;
		default:
			cout << "Wrong option selected";
			cout << endl << endl;
	}
	return;
}
void AccountHandler::Deposit()
{
	if(!index)
	{
		cout << "No accounts created" << endl;
		cout << "Deposit failed";
		cout << endl << endl;
		return;
	}
	int ID;
	cout << "[Deposit]" << endl;
	cout << "Input ID: ";
	cin >> ID;
	if(cin.fail())
	{
		cout << "Wrong ID" << endl;
		cout << "Deposit failed";
		cout << endl << endl;
		cin.clear();
		cin.ignore(IGNORE, '\n');
		return;
	}
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
	cout << "Inavailable ID" << endl;
	cout << "Deposit failed";
	cout << endl << endl;
	return;
}
void AccountHandler::Withdraw()
{
	if(!index)
	{
		cout << "No accounts created" << endl;
		cout << "Withdraw failed";
		cout << endl << endl;
		return;
	}
	int ID;
	cout << "[Withdraw]" << endl;
	cout << "Input ID: ";
	cin >> ID;
	if(cin.fail())
	{
		cout << "Wrong ID" << endl;
		cout << "Withdraw failed";
		cout << endl << endl;
		cin.clear();
		cin.ignore(IGNORE, '\n');
		return;
	}
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
	cout << "Inavailable ID" << endl;
	cout << "Withdraw failed";
	cout << endl << endl;
	return;
}
void AccountHandler::ShowAll() const
{
	if(!index)
	{
		cout << "No data" << endl << endl;
		return;
	}
	cout << "[Information]" << endl;
	for(int i = 0; i < index; i++)
		account[i]->ShowInfo();
	cout << "Total accounts: " << index << endl;
	cout << "All information printed";
	cout << endl << endl;
	return;
}