#ifndef __ACCOUNTFUNC_H__
#define __ACCOUNTFUNC_H__

#include "Account.h"
namespace ACCOUNTFUNC
{
	Account* MakeAccount();
	void Deposit(Account**, const int&);
	void Withdraw(Account**, const int&);
	void ShowAll(Account**, const int&);
}

#endif