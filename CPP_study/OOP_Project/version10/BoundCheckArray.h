#ifndef __ACCOUNTARRAY_H__
#define __ACCOUNTARRAY_H__

#include <iostream>
#include <cstdlib>
#include "Account.h"
using std::cout;
using std::endl;
template <typename T>
class BoundCheckArray
{
private:
	T* arr;
	int len;
	BoundCheckArray(const BoundCheckArray& arr) { } // Copy & Assignment forbidden
	BoundCheckArray& operator=(const BoundCheckArray& arr) { return *this; }
public:
	BoundCheckArray()
		:len(MAXIMUM)
	{
		arr = new T[len];
	} // Constructor
	inline int GetLen() const { return len; }
	T& operator[](const int&); // Assignment operator
	T& operator[](const int&) const; // Assignment operator const
	~BoundCheckArray()
	{
		delete[] arr;
	} // Destructor
};

// Below are the class functions
template <typename T>
T& BoundCheckArray<T>::operator[](const int& idx)
{
	if(idx < 0 || idx > len - 1)
	{
		cout << "Index out of bounds" << endl;
		cout << "System error occured" << endl;
		exit(1);
	}
	return arr[idx];
} // Bound check operator
template <typename T>
T& BoundCheckArray<T>::operator[](const int& idx) const
{
	if(idx < 0 || idx > len - 1)
	{
		cout << "Index out of bounds" << endl;
		cout << "System error occured" << endl;
		exit(1);
	}
	return arr[idx];
} // Bound check operator const

#endif