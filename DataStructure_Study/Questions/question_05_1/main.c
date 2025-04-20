#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CircularLinkedList.h"
#include "Company.h"
int InsertTail(Employee* emp1, Employee* emp2)
{
	return 1;
} // Always insert data at back
Employee* OnDuty(List* plist, char* name, int num)
{
	Employee* data;
	int repeat = num % (plist->numOfData);
	if(LFirst(plist, &data))
	{
		while(1)
		{
			if(strcmp(data->name, name) == 0)
				break;
			LNext(plist, &data);
		}
	}
	for(int i = 0; i < repeat; i++)
		LNext(plist, &data);
	return data;
} // Returns information of next duty
int main(int argc, char** argv)
{
	Employee* emp;
	List list;
	ListInit(&list);
	SetSortRule(&list, InsertTail);
	emp = (Employee*)malloc(sizeof(Employee));
	SetEmployee(emp, "Han", 162);
	LInsert(&list, emp);
	emp = (Employee*)malloc(sizeof(Employee));
	SetEmployee(emp, "Kim", 131);
	LInsert(&list, emp);
	emp = (Employee*)malloc(sizeof(Employee));
	SetEmployee(emp, "Ryu", 610);
	LInsert(&list, emp);
	emp = (Employee*)malloc(sizeof(Employee));
	SetEmployee(emp, "Lee", 1231);
	LInsert(&list, emp); // Inserting 4 employees
	if(LFirst(&list, &emp))
	{
		for(int i = 0; i < LCount(&list) * 3; i++)
		{
			ShowData(emp);
			LNext(&list, &emp);
		}
		putchar('\n');
	} // Printing list 3 times
	Employee* duty = OnDuty(&list, "Kim", 5);
	puts("<OnDuty info>");
	ShowData(duty);
	RemoveAll(&list);
	return 0;
}