#ifndef __ACCOUNTARRAY_H__
#define __ACCOUNTARRAY_H__

#include <iostream>
#include <cstdlib>
#include "Account.h"
using std::cout;
using std::endl;
class AccountArray
{
private:
	Account** arr;
	int len;
	AccountArray(const AccountArray& arr) { } // Copy & Assignment forbidden
	AccountArray& operator=(const AccountArray& arr) { return *this; }
public:
	AccountArray()
		:len(MAXIMUM)
	{
		arr = new Account*[len];
	} // Constructor
	inline int GetLen() const { return len; } 
	Account*& operator[](const int&); // Assignment operator
	Account*& operator[](const int&) const; // Assignment operator const
	~AccountArray()
	{
		delete[] arr;
	} // Destructor
};

#endif
