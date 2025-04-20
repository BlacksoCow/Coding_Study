#ifndef __FOREIGNWORKER_H__
#define __FOREIGNWORKER_H__

#include "SalesWorker.h"
namespace RISK_LEVEL
{
	enum{ RISK_A, RISK_B, RISK_C };
}
class ForeignSalesWorker: public SalesWorker
{
private:
	const int risk;
public:
	ForeignSalesWorker(const char* const name, const int& salary, const double& bonus, const int& risk)
		:SalesWorker(name, salary, bonus), risk(risk)
	{ /* Empty constructor */ }
	ForeignSalesWorker(const ForeignSalesWorker& fw)
		:SalesWorker(fw), risk(fw.risk)
	{ /* Empty copy constructor */}
	inline int GetRisk() const
	{ return risk; }
	int GetPay() const override
	{
		switch(risk)
		{
			case RISK_LEVEL::RISK_A:
				return SalesWorker::GetPay() * 1.3;
			case RISK_LEVEL::RISK_B:
				return SalesWorker::GetPay() * 1.2;
			default:
				return SalesWorker::GetPay() * 1.1;
		}
	}
	void ShowSalaryInfo() const override
	{
		ShowName();
		cout << "Salary: " << SalesWorker::GetPay() << endl;
		cout << "Risk pay: " << GetPay() -  SalesWorker::GetPay() << endl;
		cout << "Sum: " << GetPay() << endl;
		cout << endl;
		return;
	}
	virtual ~ForeignSalesWorker()
	{ /* Empty destructor */ }
};

#endif