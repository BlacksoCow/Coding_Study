#ifndef __NAMECARD_H__
#define __NAMECARD_H__

#define NAME_LEN 30
#define PHONE_LEN 30
typedef struct
{
	char name[NAME_LEN];
	char phone[PHONE_LEN];
} NameCard;

// Return struct's address after initializing and allocating memory
NameCard* MakeNameCard(char* name, char* phone);

// Print info of Namecard struct
void ShowNameCardInfo(NameCard* pcard);

// Return 0 if name unmatches, 1 if matches
int NameCompare(NameCard* pcard, char* name);

// Modify phone number
void ChangePhoneNum(NameCard* pcard, char* phone);

#endif