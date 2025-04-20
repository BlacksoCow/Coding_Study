#ifndef __TABLE_H__
#define __TABLE_H__

#define MAXTBL 100 // Maximum number of slots
#include "SimpleLinkedList.h"

typedef int (*Hashfunc)(Key key);

typedef struct
{
	List table[MAXTBL]; // Lists of Slots
	Hashfunc hf; // Hash function to allocate slot's location
} Table;

void TableInit(Table* pt, Hashfunc hf);
void TInsert(Table* pt, Key k, Value v);
Value TDelete(Table* pt, Key k); // Deletes the target slot and returns its value
Value TSearch(Table* pt, Key k); // Returns value of target, NULL when searching failed
void TDestroy(Table* pt); // Destroys table

#endif