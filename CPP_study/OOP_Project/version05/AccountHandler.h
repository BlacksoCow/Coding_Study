#ifndef __ACCOUNTHANDLER_H__
#define __ACCOUNTHANDLER_H__

#include "Account.h"
#define MAXIMUM 100
class AccountHandler
{
private:
	int index;
	Account* account[MAXIMUM];
public:
	AccountHandler()
		:index(0)
	{ /* Empty constructor */ }
	void MakeAccount();
	inline int GetIndex() const
	{ return index; }
	void Deposit();
	void Withdraw();
	void ShowAll();
	~AccountHandler()
	{
		for(int i = 0; i < index; i++)
			delete account[i];
	}
};

#endif