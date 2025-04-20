#ifndef __PERMANENTWORKER_H__
#define __PERMANENTWORKER_H__

#include "Employee.h"
class PermanentWorker: public Employee
{
private:
	int salary;
public:
	PermanentWorker(const char* const name, const int& salary)
		:Employee(name), salary(salary)
	{ /* Empty constructor */ }
	PermanentWorker(const PermanentWorker& per)
		:Employee(per), salary(per.salary)
	{ /* Empty copy constructor */ }
	inline int GetPay() const override
	{ return salary; }
	void ShowSalaryInfo() const override
	{
		ShowName();
		cout << "Salary: " << GetPay() << endl;
		cout << endl;
		return;
	}
	virtual ~PermanentWorker()
	{ /* Empty destructor */ }
};

#endif