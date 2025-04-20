#include "BoundPointArray.h"
using std::cout;
using std::endl;
Point*& BoundPointArray::operator[](const int& idx)
{
	if(idx < 0 || idx > len - 1)
	{
		cout << "Index out of bounds" << endl;
		exit(1);
	}
	return arr[idx];
}
Point*& BoundPointArray::operator[](const int& idx) const
{
	if(idx < 0 || idx > len - 1)
	{
		cout << "Index out of bounds" << endl;
		exit(1);
	}
	return arr[idx];
}
void BoundPointArray::ShowAllData() const
{
	for(int i = 0; i < len; i++)
		cout << arr[i] << endl;
	return;
}