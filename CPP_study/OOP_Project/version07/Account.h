#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "CommonDeclare.h"
class Account
{
private:
	const int ID;
	int money;
	char* name;
public:
	Account(const int& ID, const int& Seedmoney, const char* const name)
		:ID(ID), money(Seedmoney)
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	} // Constructor
	Account(const Account& account)
		:ID(account.ID), money(account.money)
	{
		name = new char[strlen(account.name) + 1];
		strcpy(name, account.name);
	} // Copy constructor
	inline int GetID() const { return ID; }
	inline int GetMoney() const { return money; }
	inline char* GetName() const { return name; }
	virtual void Deposit(const int&);
	void Withdraw(const int&);
	virtual void ShowInfo() const;
	virtual ~Account()
	{
		delete[] name;
	} // Destructor
};

#endif