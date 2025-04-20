#include <iostream>
#include "HighCreditAccount.h"
using std::cout;
using std::endl;
void HighCreditAccount::Deposit(const int& deposit)
{
	NormalAccount::Deposit(deposit);
	Account::Deposit(int(deposit * (rank * 0.01)));
	return;
}
void HighCreditAccount::ShowInfo() const
{
	cout << "Account type: HighCreditAccount" << endl;
	switch(rank)
	{
		case RANK::A:
			cout << "Rank: A" << endl;
			break;
		case RANK::B:
			cout << "Rank: B" << endl;
			break;
		case RANK::C:
			cout << "Rank: C" << endl;
			break;
		default:
			cout << "Rank error" << endl;
	}
	cout << "Interrate: " << GetRate() << " + " << rank << "%" << endl;
	Account::ShowInfo();
	return;
}