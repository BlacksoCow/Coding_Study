#include <stdio.h>
#include <stdlib.h>
#include "Person.h"
#include "Table.h"
int HashFunc(Key k)
{
	return k % 100;
}
int main(int argc, char** argv)
{
	Person* np; // For making person data
	Person* sp; // For searching person data
	Person* rp; // For removing person data
	Table tbl;
	TableInit(&tbl, HashFunc);
	// Data insertion
	np = MakePersonData(900254, "Han", "Bundang");
	TInsert(&tbl, GetSSN(np), np);
	np = MakePersonData(900139, "Lee", "Seoul");
	TInsert(&tbl, GetSSN(np), np);
	np = MakePersonData(900827, "Ryu", "Earth");
	TInsert(&tbl, GetSSN(np), np);
	np = MakePersonData(900705, "Kim", "Mars");
	TInsert(&tbl, GetSSN(np), np);
	// Data searching
	sp = TSearch(&tbl, 900254);
	ShowPersonInfo(sp);
	sp = TSearch(&tbl, 900123);
	ShowPersonInfo(sp); // No infomation
	sp = TSearch(&tbl, 900139);
	ShowPersonInfo(sp);
	sp = TSearch(&tbl, 900800);
	ShowPersonInfo(sp); // No information
	sp = TSearch(&tbl, 900705);
	ShowPersonInfo(sp);
	sp = TSearch(&tbl, 900827);
	ShowPersonInfo(sp);
	// Data removing
	rp = TDelete(&tbl, 900139);
	ShowPersonInfo(rp);
	free(rp);
	rp = TDelete(&tbl, 900523);
	ShowPersonInfo(rp);
	free(rp); // No information
	TDestroy(&tbl);
	return 0;
}