#ifndef __EMPLOYEEHANDLER_H__
#define __EMPLOYEEHANDLER_H__

#include "Employee.h"
#define MAXIMUM 100
class EmployeeHandler
{
private:
	Employee* empList[MAXIMUM];
	int index;
public:
	EmployeeHandler()
		:index(0)
	{ /* Empty constructor */ }
	void AddEmployee(Employee*);
	void ShowAllSalary() const;
	void ShowTotalSalary() const;
	~EmployeeHandler()
	{
		for(int i = 0; i < index; i++)
			delete empList[i];
	}
};

#endif
