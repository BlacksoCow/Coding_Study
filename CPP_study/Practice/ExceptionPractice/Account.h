#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include <iostream>
#include <string>
using namespace std;

class AccountException
{
private:
	// No private members
protected:
	int money;
public:
	AccountException(const int& balance)
		:money(balance)
	{ /* Empty constructor */ }
	AccountException(const AccountException& acc)
		:money(acc.money)
	{ /* Empty copy constructor */ }
	AccountException& operator=(const AccountException& acc) = delete;
	virtual void ShowError() const = 0; // Pure virtual function
	virtual ~AccountException()
	{ /* Empty destructor */ }
};

class DepositException: public AccountException
{
private:
	// No special private members
public:
	DepositException(const int& balance)
		:AccountException(balance)
	{ /* Empty constructor */ }
	inline void ShowError() const override
	{
		cout << "Balance cannot be " << money << endl;
		cout << "Re-enter the balance" << endl;
		return;
	}
	virtual ~DepositException()
	{ /* Empty destructor */ }
};

class WithdrawException: public AccountException
{
private:
	const int accamount;
public:
	WithdrawException(const int& balance, const int& amount)
		:AccountException(balance), accamount(amount)
	{ /* Empty constructor */ }
	inline void ShowError() const override
	{
		if(money <= 0)
		{
			cout << "Balance cannot be " << money << endl;
			cout << "Re-enter the balance" << endl;
		}
		else if(money > accamount)
		{
			cout << "Your balance is " << accamount << endl;
			cout << "Re-enter the withdraw amount" << endl;
		}
		else
			cout << "Unexpected error occured" << endl;
		return;
	}
	virtual ~WithdrawException()
	{ /* Empty destructor */ }
};

class Account
{
private:
	const string AccNum;
	int money;
public:
	Account(const string& num, const int& balance)
		:AccNum(num), money(balance)
	{ /* Empty constructor */ }
	Account(const Account& acc)
		:AccNum(acc.AccNum), money(acc.money)
	{ /* Empty copy constructor */ }
	inline string GetAccNum() const { return AccNum; }
	inline int GetMoney() const { return money; }
	void Deposit(const int& balance)
	{
		if(balance <= 0)
		{
			DepositException dexp(balance);
			throw dexp;
		}
		money += balance;
		return;
	}
	void Withdraw(const int& balance)
	{
		if(balance <= 0)
			throw WithdrawException(balance, money);
		else if(balance > money)
			throw WithdrawException(balance, money);
		money -= balance;
		return;
	}
	void ShowInfo() const
	{
		cout << "Account number: " << AccNum << endl;
		cout << "Balance: " << money << endl << endl;
		return;
	}
	~Account()
	{ /* Empty desturctor */ }
};

#endif