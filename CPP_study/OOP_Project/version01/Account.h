#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#define MAXLEN 20
typedef struct
{
	int ID, money;
	char name[MAXLEN + 1];
} Account;
void MakeAccount(Account*);
bool FindAccount(Account[], int, int);
void Deposition(Account[], int);
void WithDraw(Account[], int);
void PrintInfo(Account[], int);

#endif