#ifndef __SLOT_H__
#define __SLOT_H__

#include "Person.h"

typedef int Key; // Integer as key
typedef Person* Value; // Person* as value

typedef struct
{
	Key key;
	Value value;
} Slot; // Slot's structure

#endif