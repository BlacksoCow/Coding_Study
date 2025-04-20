#ifndef __PERSON_H__
#define __PERSON_H__

#define MAXSTR 50
typedef struct
{
	int ssn;
	char name[MAXSTR + 1];
	char address[MAXSTR + 1];
} Person;

int GetSSN(Person* pp);
void ShowPersonInfo(Person* pp);
Person* MakePersonData(int ssn, char* name, char* address);

#endif