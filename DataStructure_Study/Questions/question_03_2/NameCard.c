#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NameCard.h"
#define TRUE 1
#define FALSE 0
NameCard* MakeNameCard(char* name, char* phone)
{
	NameCard* retNC = (NameCard*)malloc(sizeof(NameCard));
	strncpy(retNC->name, name, NAME_LEN - 1);
	retNC->name[NAME_LEN - 1] = 0;
	strncpy(retNC->phone, phone, PHONE_LEN - 1);
	retNC->phone[PHONE_LEN - 1] = 0;
	return retNC;
}

void ShowNameCardInfo(NameCard* pcard)
{
	printf("Name: %s\n", pcard->name);
	printf("Phone number: %s\n", pcard->phone);
	return;
}

int NameCompare(NameCard* pcard, char* name)
{
	if(!strcmp(pcard->name, name))
		return TRUE;
	else
		return FALSE;
}

void ChangePhoneNum(NameCard* pcard, char* phone)
{
	strncpy(pcard->phone, phone, PHONE_LEN - 1);
	pcard->phone[PHONE_LEN - 1] = 0;
	return;
}