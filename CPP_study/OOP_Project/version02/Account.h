#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include <iostream>
#include <cstring>
using std::cout;
using std::endl;
namespace OPTION
{
	enum { MAKE = 1, DEPOSIT, WITHDRAW, PRINT, EXIT };
}
class Account
{
private:
	const int ID;
	int money;
	char* name;
public:
	Account(const int& ID, const int& Seedmoney, char* name)
		:ID(ID) // Constructor
	{
		this->money = Seedmoney;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	inline int GetID() const { return ID; }
	inline int GetMoney() const { return money; }
	inline char* GetName() const { return name; }
	void Deposit(const int&);
	void Withdraw(const int&);
	void ShowInfo() const;
	~Account()
	{
		delete[] name; //Destructor
	}
};

#endif