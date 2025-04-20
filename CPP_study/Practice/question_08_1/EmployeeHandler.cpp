#include <iostream>
#include "EmployeeHandler.h"
using std::cout;
using std::endl;
void EmployeeHandler::AddEmployee(Employee* emp)
{
	empList[index++] = emp;
	return;
}
void EmployeeHandler::ShowAllSalary() const
{
	for(int i = 0; i < index; i++)
		empList[i]->ShowSalaryInfo();
	return;
}
void EmployeeHandler::ShowTotalSalary() const
{
	int sum = 0;
	for(int i = 0; i < index; i++)
		sum += empList[i]->GetPay();
	cout << "Total salary: " << sum << endl;
}