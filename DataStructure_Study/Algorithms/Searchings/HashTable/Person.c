#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Person.h"
int GetSSN(Person* pp)
{
	return pp->ssn;
}
void ShowPersonInfo(Person* pp)
{
	if(pp == NULL)
	{
		puts("No information\n");
		return;
	}
	printf("SSN: %d\n", pp->ssn);
	printf("Name: %s\n", pp->name);
	printf("Address: %s\n\n", pp->address);
	return;
}
Person* MakePersonData(int ssn, char* name, char* address)
{
	Person* newPerson = (Person*)malloc(sizeof(Person));
	newPerson->ssn = ssn;
	strncpy(newPerson->name, name, MAXSTR);
	strncpy(newPerson->address, address, MAXSTR);
	return newPerson;
}