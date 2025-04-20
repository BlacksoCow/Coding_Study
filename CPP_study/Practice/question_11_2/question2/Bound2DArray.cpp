#include "Bound2DArray.h"
BoundIntArray& Bound2DArray::operator[](const int& idx)
{
	if(idx < 0 || idx > ver - 1)
	{
		cout << "Vertical index out of bounds" << endl;
		exit(1);
	}
	return *(arr[idx]);
}
BoundIntArray& Bound2DArray::operator[](const int& idx) const
{
	if(idx < 0 || idx > ver - 1)
	{
		cout << "Vertical index out of bounds" << endl;
		exit(1);
	}
	return *(arr[idx]);
}
void Bound2DArray::ShowAllInfo() const
{
	for(int i = 0; i < ver; i++)
	{
		arr[i]->ShowAllData();
		cout << endl;
	}
	return;
}