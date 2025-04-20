#include <stdio.h>
#include "Table.h"
void TableInit(Table* pt, Hashfunc hf)
{
	for(int i = 0; i < MAXTBL; i++)
		ListInit(&(pt->table[i]));
	pt->hf = hf;
	return;
}
void TInsert(Table* pt, Key k, Value v)
{
	int hv = pt->hf(k); // Calculating hashvalue
	Slot newSlot = {k, v}; // Initializing struct in one line
	if(TSearch(pt, k) != NULL)
		puts("Insert failed: Key overlapping error"); // When same key already exists
	else
		LInsert(&(pt->table[hv]), newSlot); // Copying newSlot's members
	return;
}
Value TDelete(Table* pt, Key k)
{
	int hv = pt->hf(k);
	Slot dSlot; // Slot to be deleted
	if(LFirst(&(pt->table[hv]), &dSlot))
	{
		if(dSlot.key == k)
		{
			LRemove(&(pt->table[hv]));
			return dSlot.value;
		}
		else
			while(LNext(&(pt->table[hv]), &dSlot) && (dSlot.key == k))
			{
				LRemove(&(pt->table[hv]));
				return dSlot.value;
			}
	}
	return NULL; // Target doesn't exist
}
Value TSearch(Table* pt, Key k)
{
	int hv = pt->hf(k);
	Slot retSlot; // Slot to be returned
	if(LFirst(&(pt->table[hv]), &retSlot))
	{ // Attempting search in same hash value
		if(retSlot.key == k)
			return retSlot.value;
		else
		{
			while(LNext(&(pt->table[hv]), &retSlot) && (retSlot.key == k))
				return retSlot.value;
		} // Returns value when same key is found is same hash value list
	}
	return NULL; // Returns NULL when target doesn't exist
}
void TDestroy(Table* pt)
{
	for(int i = 0; i < MAXTBL; i++)
		RemoveAll(&(pt->table[i]));
	return;
}