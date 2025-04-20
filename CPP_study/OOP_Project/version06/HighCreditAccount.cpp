#include <iostream>
#include "HighCreditAccount.h"
using std::cout;
using std::endl;
void HighCreditAccount::Deposit(const int& deposit)
{
	int bonusRate;
	switch(GetRank())
	{
		case 1:
			bonusRate = RANK::A;
			break;
		case 2:
			bonusRate = RANK::B;
			break;
		case 3:
			bonusRate = RANK::C;
			break;
		default:
			cout << "Rank fetch error" << endl;
	}
	int dp = int(deposit * (1 + 0.01 * (GetRate() + bonusRate)));
	Account::Deposit(dp);
	return;
}
void HighCreditAccount::ShowInfo() const
{
	cout << "Account type: HighCreditAccount" << endl;
	switch(GetRank())
	{
		case 1:
			cout << "Rank: A" << endl;
			break;
		case 2:
			cout << "Rank: B" << endl;
			break;
		case 3:
			cout << "Rank: C" << endl;
			break;
		default:
			cout << "Rank error" << endl;
	}
	Account::ShowInfo();
	return;
}