#include "Company.h"
void SetEmployee(Employee* emp, char* Name, int num)
{
	strncpy(emp->name, Name, NAMELEN);
	emp->empNum = num;
	return;
}
void ShowData(Employee* emp)
{
	printf("Employee name: %s\n", emp->name);
	printf("Employee number: %d\n", emp->empNum);
	return;
}