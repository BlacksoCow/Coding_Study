#ifndef __BOUNDPOINTARRAY_H__
#define __BOUNDPOINTARRAY_H__

#include <iostream>
#include <cstdlib>
#include "Point.h"
using std::cout;
using std::endl;
class BoundPointArray
{
private:
	Point** arr;
	int len;
	BoundPointArray(const BoundPointArray& arr) { } // Copy & Assignment forbidden
	BoundPointArray& operator=(const BoundPointArray& arr) { return *this; };
public:
	BoundPointArray(const int& len)
		:len(len)
	{
		arr = new Point*[len];
	} // Constructor
	inline int GetLen() const { return len; }
	Point*& operator[](const int&); // Boundcheck operator
	Point*& operator[](const int&) const; // Boundcheck operator const
	void ShowAllData() const;
	~BoundPointArray()
	{
		delete[] arr;
	} // Destructor
};

#endif