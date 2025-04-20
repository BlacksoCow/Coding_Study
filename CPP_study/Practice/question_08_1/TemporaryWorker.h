#ifndef __TEMPORARYWORKER_H__
#define __TEMPORARYWORKER_H__

#include "Employee.h"
class TemporaryWorker: public Employee
{
private:
	int workTime;
	int payPerHour;
public:
	TemporaryWorker(const char* const name, const int& time, const int& pay)
		:Employee(name), workTime(time), payPerHour(pay)
	{ /* Empty constructor */ }
	TemporaryWorker(const TemporaryWorker& tmp)
		:Employee(tmp), workTime(tmp.workTime), payPerHour(tmp.payPerHour)
	{ /* Empty copy constructor */ }
	inline int GetWorkTime() const
	{ return workTime; }
	inline int GetPayPerHour() const
	{ return payPerHour; }
	int GetPay() const override
	{ return workTime * payPerHour; }
	void ShowSalaryInfo() const override
	{
		ShowName();
		cout << "Salary: " << GetPay() << endl;
		cout << endl;
		return;
	}
	virtual ~TemporaryWorker()
	{ /* Empty destructor */ }
};

#endif