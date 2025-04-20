#ifndef __ACCOUNTHANDLER_H__
#define __ACCOUNTHANDLER_H__

#include "HighCreditAccount.h"
class AccountHandler
{
private:
	int index;
	Account* account[MAXIMUM];
public:
	AccountHandler()
		:index(0)
	{ /* Empty constructor */ }
	inline int GetIndex() const { return index; }
	void PrintMenu() const;
	void MakeAccount();
	void Deposit();
	void Withdraw();
	void ShowAll() const;
	~AccountHandler()
	{
		for(int i = 0; i < index; i++)
			delete account[i];
	} // Destructor
};

#endif