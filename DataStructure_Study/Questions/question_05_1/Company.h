#ifndef __COMPANY_H__
#define __COMPANY_H__

#include <stdio.h>
#include <string.h>
#define NAMELEN 50
typedef struct __employee
{
	char name[NAMELEN + 1];
	int empNum;
} Employee;
void SetEmployee(Employee* emp, char* Name, int num);
void ShowData(Employee* emp);

#endif