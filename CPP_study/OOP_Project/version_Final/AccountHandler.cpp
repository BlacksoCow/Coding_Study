#include <iostream>
#include "String.h"
#include "AccountHandler.h"
using namespace std;
void AccountHandler::PrintMenu() const
{
	cout << "---------Menu---------" << endl;
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
	while(true)
	{
		cout << "[Select account type]" << endl;
		cout << "1. NormalAccount  2. HighCreditAccount 3. Back to menu" << endl;
		cout << "Option: ";
		try
		{
			cin >> type;
			if(cin.fail() || !(1 <= type && type <= 3))
				throw "\nOption must be a number between 1 to 3";
			break;
		}
		catch(const char* error)
		{
			cout << error << endl;
			cout << "Re-enter the option" << endl << endl;
			cin.clear();
			cin.ignore(IGNORE, '\n');
		}
		catch(...)
		{
			cout << "\nUnexpected error during option phase" << endl << endl;
			cin.clear();
			cin.ignore(IGNORE, '\n');
			exit(1);
		}
	}
	cin.ignore();
	switch(type)
	{
		case Normal:
			while(true)
			{
				cout << "[NormalAccount]" << endl;
				cout << "Input account ID: ";
				try
				{
					cin >> ID;
					if(cin.fail())
						throw "\nID should be composed of only numbers";
					else if(ID < 0)
						throw "\nID cannot be negative";
					else if(ID < 100)
						throw "\nID should be at least 3 chracters long";
					for(int i = 0; i < index; i++)
						if(account[i]->GetID() == ID)
							throw "\nCurrent ID already exists";
					break;
				}
				catch(const char* error)
				{
					cout << error << endl;
					cout << "Re-enter your ID" << endl << endl;
					cin.clear();
					cin.ignore(IGNORE, '\n');
				} // Exception when ID is not a number or has an identical ID
				catch(...)
				{
					cout << "\nUnexpected error while creating ID" << endl;
					cin.clear();
					cin.ignore(IGNORE, '\n');
					exit(1);
				}
			}
			cin.ignore();
			while(true)
			{
				cout << "Input account owner's name: ";
				try
				{
					cin >> name;
					if(!name.Length())
						throw "\nName should be at least 1 character long";
					break;
				}
				catch(const char* error)
				{
					cout << error << endl;
					cout << "Re-enter your name" << endl << endl;
					cin.clear();
					cin.ignore(IGNORE, '\n');
				} // Exception when name is empty
				catch(...)
				{
					cout << "\nUnexpected error while entering name" << endl;
					cin.clear();
					cin.ignore(IGNORE, '\n');
					exit(1);
				}
			}
			while(true)
			{
				cout << "Input seed money: ";
				try
				{
					cin >> money;
					if(cin.fail())
						throw "\nSeed money should be a number";
					else if(money < 0)
						throw "\nSeed money cannot be negative";
					else if(money < 1000)
						throw "\nSeed money should be at least 1000";
					break;
				}
				catch(const char* error)
				{
					cout << error << endl;
					cout << "Re-enter your seed money" << endl << endl;
					cin.clear();
					cin.ignore(IGNORE, '\n');
				} // Exception when seed money is inavailable
				catch(...)
				{
					cout << "\nUnexpected error while entering seed money" << endl << endl;
					cin.clear();
					cin.ignore(IGNORE, '\n');
					exit(1);
				}
			}
			cin.ignore();
			while(true)
			{
				cout << "Input interrate: ";
				try
				{
					cin >> per;
					if(cin.fail())
						throw "\nInavailable interrate";
					else if(per <= 0 || per >= 100)
						throw "\nInterrate cannot be below 0 or above 100";
					break;
				}
				catch(const char* error)
				{
					cout << error << endl;
					cout << "Re-enter your interrate" << endl << endl;
					cin.clear();
					cin.ignore(IGNORE, '\n');
				} // Exception when interrate is inavailable
				catch(...)
				{
					cout << "\nUnexpected error while entering interrate" << endl;
					cin.clear();
					cin.ignore(IGNORE, '\n');
					exit(1);
				}
			}
			cin.ignore();
			account[index++] = new NormalAccount(ID, money, name, per);
			cout << "\nNormalAccount successfully created" << endl << endl;
			break;
		case HighCredit:
			while(true)
			{
				cout << "[HighCreditAccount]" << endl;
				cout << "Input account ID: ";
				try
				{
					cin >> ID;
					if(cin.fail())
						throw "\nID should be composed of only numbers";
					else if(ID < 100)
						throw "\nID should be at least 3 chracters long";
					for(int i = 0; i < index; i++)
						if(account[i]->GetID() == ID)
							throw "\nCurrent ID already exists";
					break;
				}
				catch(const char* error)
				{
					cout << error << endl;
					cout << "Re-enter your ID" << endl << endl;
					cin.clear();
					cin.ignore(IGNORE, '\n');
					continue;
				} // Exception when ID is not a number or has an identical ID
				catch(...)
				{
					cout << "\nUnexpected error while creating ID" << endl;
					cin.clear();
					cin.ignore(IGNORE, '\n');
					exit(1);
				}
			}
			cin.ignore();
			while(true)
			{
				cout << "Input account owner's name: ";
				try
				{
					cin >> name;
					if(!name.Length())
						throw "\nName should be at least 1 character long";
					break;
				}
				catch(const char* error)
				{
					cout << error << endl;
					cout << "Re-enter your name" << endl << endl;
					cin.clear();
					cin.ignore(IGNORE, '\n');
				} // Exception when name is empty
				catch(...)
				{
					cout << "\nUnexpected error while entering name" << endl;
					cin.clear();
					cin.ignore(IGNORE, '\n');
					exit(1);
				}
			}
			while(true)
			{
				cout << "Input seed money: ";
				try
				{
					cin >> money;
					if(cin.fail())
						throw "\nSeed money should be a number";
					else if(money < 1000)
						throw "\nSeed money should be at least 1000";
					break;
				}
				catch(const char* error)
				{
					cout << error << endl;
					cout << "Re-enter your seed money" << endl << endl;
					cin.clear();
					cin.ignore(IGNORE, '\n');
				} // Exception when seed money is inavailable
				catch(...)
				{
					cout << "\nUnexpected error while entering seed money" << endl << endl;
					cin.clear();
					cin.ignore(IGNORE, '\n');
					exit(1);
				}
			}
			cin.ignore();
			while(true)
			{
				cout << "Input interrate: ";
				try
				{
					cin >> per;
					if(cin.fail())
						throw "\nInavailable interrate";
					else if(per <= 0 || per >= 100)
						throw "\nInterrate cannot be below 0 or above 100";
					break;
				}
				catch(const char* error)
				{
					cout << error << endl;
					cout << "Re-enter your interrate" << endl << endl;
					cin.clear();
					cin.ignore(IGNORE, '\n');
				} // Exception when interrate is inavailable
				catch(...)
				{
					cout << "\nUnexpected error while entering interrate" << endl;
					cin.clear();
					cin.ignore(IGNORE, '\n');
					exit(1);
				}
			}
			cin.ignore();
			while(true)
			{
				cout << "Credit Rank(1toA, 2toB, 3toC): ";
				try
				{
					cin >> rank;
					if(cin.fail())
						throw "\nRank should be expressed with a number";
					else if(!(1 <= rank && rank <= 3))
						throw "\nRank should be between 1 to 3";
					break;
				}
				catch(const char* error)
				{
					cout << error << endl;
					cout << "Re-enter your rank" << endl << endl;
					cin.clear();
					cin.ignore(IGNORE, '\n');
				} // Exception when rank is inavailable
				catch(...)
				{
					cout << "\nUnexpected error while entering rank" << endl;
					cin.clear();
					cin.ignore(IGNORE, '\n');
					exit(1);
				}
			}
			cin.ignore();
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
					cout << "\nUnexpected error occurred while inputting account" << endl;
					exit(1);
			}
			cout << "\nHighCreditAccount successfully created" << endl << endl;
			break;
		default:
			cout << "\nBack to menu" << endl << endl;
			return;
	}
	return;
}
void AccountHandler::Deposit()
{
	if(!index)
	{
		cout << "No accounts created" << endl;
		cout << "Deposit failed" << endl << endl;
		return;
	} // Exception when no accounts are created
	int ID;
	while(true)
	{
		cout << "[Deposit]" << endl;
		cout << "Input ID(Enter -1 to exit): ";
		try
		{
			cin >> ID;
			if(ID == -1)
			{
				cout << "\nBack to menu" << endl << endl;
				return;
			}
			else if(cin.fail())
				throw "\nID should be composed of numbers";
			else if(ID < 100)
				throw "\nID must be positive with at least 3 characters long";
			break;
		}
		catch(const char* error)
		{
			cout << error << endl;
			cout << "Re-enter the ID" << endl << endl;
			cin.clear();
			cin.ignore(IGNORE, '\n');
		} // Exception when ID is inavailable
		catch(...)
		{
			cout << "\nUnexpected error while entering ID" << endl;
			cin.clear();
			cin.ignore(IGNORE, '\n');
			exit(1);
		}
	}
	cin.ignore();
	for(int i = 0; i < index; i++)
	{
		if(account[i]->GetID() == ID)
		{
			int deposit;
			while(true)
			{
				cout << "Input deposit amount: ";
				try
				{
					cin >> deposit;
					if(cin.fail())
						throw "\nInavailable deposit value";
					else if(deposit <= 0)
						throw "\nDeposit amount should be greater than 0";
					break;
				}
				catch(const char* error)
				{
					cout << error << endl;
					cout << "Re-enter the deposit amount" << endl << endl;
					cin.clear();
					cin.ignore(IGNORE, '\n');
				} // Exception when deposit value is inavailable
				catch(...)
				{
					cout << "\nUnexpected error when checking deposit amount" << endl;
					cin.clear();
					cin.ignore(IGNORE, '\n');
					exit(1);
				}
			}
			cin.ignore();
			account[i]->Deposit(deposit);
			cout << "Deposit successful" << endl << endl;
			return;
		}
	}
	cout << "\nCurrent ID not found" << endl;
	cout << "Deposit failed" << endl << endl;
	return;
}
void AccountHandler::Withdraw()
{
	if(!index)
	{
		cout << "No accounts created" << endl;
		cout << "Withdraw failed" << endl << endl;
		return;
	} // Exception when no accounts are created
	int ID;
	while(true)
	{
		cout << "[Withdraw]" << endl;
		cout << "Input ID(Enter -1 to exit): ";
		try
		{
			cin >> ID;
			if(ID == -1)
			{
				cout << "\nBack to menu" << endl << endl;
				return;
			}
			else if(cin.fail())
				throw "\nID should be composed of numbers";
			else if(ID < 100)
				throw "\nID must be positive with at least 3 characters long";
			break;
		}
		catch(const char* error)
		{
			cout << error << endl;
			cout << "Re-enter the ID" << endl << endl;
			cin.clear();
			cin.ignore(IGNORE, '\n');
		} // Exception when ID is inavailable
		catch(...)
		{
			cout << "\nUnexpected error while entering ID" << endl;
			cin.clear();
			cin.ignore(IGNORE, '\n');
			exit(1);
		}
	}
	cin.ignore();
	for(int i = 0; i < index; i++)
	{
		if(account[i]->GetID() == ID)
		{
			int withdraw;
			while(true)
			{
				cout << "Input withdraw amount: ";
				try
				{
					cin >> withdraw;
					if(cin.fail())
						throw "\nInavailable withdraw value";
					else if(withdraw <= 0)
						throw "\nWithdraw amount should be greater than 0";
					else if(account[i]->GetMoney() < withdraw)
						throw account[i]->GetMoney();
					break;
				}
				catch(const char* error)
				{
					cout << error << endl;
					cout << "Re-enter the withdraw amount" << endl << endl;
					cin.clear();
					cin.ignore(IGNORE, '\n');
				} // Exception when withdraw value is inavailable
				catch(const int& balance)
				{
					cout << "\nYour balance is " << balance << endl;
					cout << "Re-enter the withdraw amount" << endl << endl;
					cin.clear();
					cin.ignore(IGNORE, '\n');
				} // Exception when withdraw value is greater than balance
				catch(...)
				{
					cout << "\nUnexpected error when checking withdraw amount" << endl;
					cin.clear();
					cin.ignore(IGNORE, '\n');
					exit(1);
				}
			}
			cin.ignore();
			account[i]->Withdraw(withdraw);
			cout << "Withdraw successful" << endl << endl;
			return;
		}
	}
	cout << "\nCurrent ID not found" << endl;
	cout << "Withdraw failed" << endl << endl;
	return;
}
void AccountHandler::ShowAll() const
{
	if(!index)
	{
		cout << "No data" << endl << endl;
		return;
	} // Exception when no accounts are created
	cout << "[Information]" << endl;
	for(int i = 0; i < index; i++)
		account[i]->ShowInfo();
	cout << "Total accounts: " << index << endl;
	cout << "All information printed" << endl << endl;
	return;
}