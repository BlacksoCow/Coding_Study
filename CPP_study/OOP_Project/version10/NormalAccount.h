#ifndef __NORMALACCOUNT_H__
#define __NORMALACCOUNT_H__

#include "Account.h"
class NormalAccount: public Account
{
private:
	int percentage;
public:
	NormalAccount(const int& ID, const int& Seedmoney, String name, const int& per)
		:Account(ID, Seedmoney, name), percentage(per)
	{ /* Empty constructor */ }
	NormalAccount(const NormalAccount& nac)
		:Account(nac), percentage(nac.percentage)
	{ /* Empty copy constructor */ }
	NormalAccount& operator=(const NormalAccount& nac)
	{
		percentage = nac.percentage;
		Account::operator=(nac);
		return *this;
	} // Assignment operator
	inline int GetRate() const { return percentage; }
	virtual void Deposit(const int&) override;
	virtual void ShowInfo() const override;
	virtual ~NormalAccount()
	{ /* Empty destructor */ }
};

#endif