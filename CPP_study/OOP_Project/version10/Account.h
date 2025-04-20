#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "String.h"
#include "CommonDeclare.h"
class Account
{
private:
	int ID;
	int money;
	String name;
public:
	Account(const int& ID, const int& Seedmoney, String name)
		:ID(ID), money(Seedmoney), name(name)
	{ /* Empty constructor */ }
	Account(const Account& account)
		:ID(account.ID), money(account.money), name(account.name)
	{ /* Empty copy constructor */ }
	Account& operator=(const Account& acc)
	{
		ID = acc.ID;
		money = acc.money;
		name = acc.name;
		return *this;
	} // Assignmnet operator
	inline int GetID() const { return ID; }
	inline int GetMoney() const { return money; }
	inline String GetName() const { return name; }
	virtual void Deposit(const int&);
	void Withdraw(const int&);
	virtual void ShowInfo() const;
	virtual ~Account()
	{ /* Empty destructor */ }
};

#endif