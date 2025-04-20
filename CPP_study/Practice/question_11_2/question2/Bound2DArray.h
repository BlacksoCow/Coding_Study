#ifndef __BOUND2DARRAY_H__
#define __BOUND2DARRAY_H__

#include <iostream>
#include <cstdlib>
#include "BoundIntArray.h"
using std::cout;
using std::endl;
class Bound2DArray
{
private:
	BoundIntArray** arr;
	int hor, ver;
	Bound2DArray(const Bound2DArray& arr) { } // Copy & Assignment forbidden
	Bound2DArray& operator=(const Bound2DArray& arr) { return *this; }
public:
	Bound2DArray(const int& ver, const int& hor)
		:ver(ver), hor(hor)
	{
		arr = new BoundIntArray*[ver];
		for(int i = 0; i < ver; i++)
			arr[i] = new BoundIntArray(hor);
	} // Constructor
	BoundIntArray& operator[](const int& idx);
	BoundIntArray& operator[](const int& idx) const;
	void ShowAllInfo() const;
	~Bound2DArray()
	{
		for(int i = 0; i < ver; i++)
			delete arr[i];
		delete[] arr;
	} // Destructor
};

#endif