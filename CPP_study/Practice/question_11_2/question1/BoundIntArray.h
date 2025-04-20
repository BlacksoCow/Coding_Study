#ifndef __BOUNDINTARRAY_H__
#define __BOUNDINTARRAY_H__

#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;
class BoundIntArray
{
private:
	int* arr;
	int len;
	BoundIntArray(const BoundIntArray& B) { } // Copy forbidden
	BoundIntArray& operator=(const BoundIntArray& B) { return *this; } // Assign forbidden
public:
	BoundIntArray(const int& len)
		:len(len)
	{
		arr = new int[len];
	} // Constructor
	inline int GetLen() const { return len; };
	int& operator[](const int& idx); // BoundCheck operator
	int& operator[](const int& idx) const; // BoundCheck operator const
	void ShowAllData() const;
	~BoundIntArray()
	{
		delete[] arr;
	} // Destructor
};

#endif