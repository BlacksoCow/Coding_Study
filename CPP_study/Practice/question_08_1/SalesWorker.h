#ifndef __SALESWORKER_H__
#define __SALESWORKER_H__

#include "PermanentWorker.h"
class SalesWorker: public PermanentWorker
{
private:
	int salesResult;
	double bonusRatio;
public:
	SalesWorker(const char* const name, const int& salary, const double& bonus)
		:PermanentWorker(name, salary), bonusRatio(bonus), salesResult(0)
	{ /* Empty constructor */ }
	SalesWorker(const SalesWorker& sw)
		:PermanentWorker(sw), salesResult(sw.salesResult), bonusRatio(sw.bonusRatio)
	{ /* Empty copy constructor */ }
	void AddSalesResult(const int& value)
	{
		salesResult += value;
		return;
	}
	int GetPay() const override
	{ return PermanentWorker::GetPay() + int(salesResult * bonusRatio); }
	inline double GetBonus() const
	{ return bonusRatio; }
	void ShowSalaryInfo() const override
	{
		ShowName();
		cout << "Salary: " << GetPay() << endl;
		cout << endl;
		return;
	}
	virtual ~SalesWorker()
	{ /* Empty destructor */ }
};

#endif