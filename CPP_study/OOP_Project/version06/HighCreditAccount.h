#ifndef __HIGHCREDITACCOUNT_H__
#define __HIGHCREDITACCOUNT_H__

#include "NormalAccount.h"
namespace RANK
{
	enum { A = 7, B = 4, C = 2 };
}
class HighCreditAccount: public NormalAccount
{
private:
	int rank;
public:
	HighCreditAccount(const int& ID, const int& Seedmoney, const char* const name, const int& per, const int& rank)
		:NormalAccount(ID, Seedmoney, name, per), rank(rank)
	{ /* Empty constructor */ }
	HighCreditAccount(const HighCreditAccount& hca)
		:NormalAccount(hca), rank(hca.rank)
	{ /* Empty copy constructor */ }
	inline int GetRank() const { return rank; }
	void Deposit(const int&) override;
	void ShowInfo() const override;
	~HighCreditAccount()
	{ /* Empty destructor */ }
};

#endif