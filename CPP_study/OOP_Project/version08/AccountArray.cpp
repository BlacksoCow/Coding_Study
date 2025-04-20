#include "AccountArray.h"
Account*& AccountArray::operator[](const int& idx)
{
	if(idx < 0 || idx > len - 1)
	{
		cout << "Index out of bounds" << endl;
		cout << "System error occured" << endl;
		exit(1);
	}
	return arr[idx];
}
Account*& AccountArray::operator[](const int& idx) const
{
	if(idx < 0 || idx > len - 1)
	{
		cout << "Index out of bounds" << endl;
		cout << "System error occured" << endl;
		exit(1);
	}
	return arr[idx];
}