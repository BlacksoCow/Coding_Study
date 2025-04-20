#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#include <iostream>
#include <cstring>
using std::cout;
using std::endl;
class Employee
{
private:
	char* name;
public:
	Employee(const char* const name)
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	} // Constructor
	Employee(const Employee& emp)
	{
		this->name = new char[strlen(emp.name) + 1];
		strcpy(this->name, emp.name);
	} // Copy constructor
	inline const char* GetName() const
	{ return name; }
	void ShowName() const
	{
		cout << "Name: " << name << endl;
		return;
	}
	virtual int GetPay() const = 0;
	virtual void ShowSalaryInfo() const = 0;
	virtual ~Employee()
	{
		delete[] name;
	} // Destructor
};

#endif