#include <iostream>
using namespace std;
template <typename T>
T SumArray(T arr[], int len)
{
	T sum = T(0);
	for(int i = 0; i < len; i++)
		sum += arr[i];
	return sum;
}
int main(int argc, char** argv)
{
	int arr1[5] = {1, 3, 5, 7, 9};
	double arr2[5] = {2.1, 4.2, 6.3, 8.4, 10.5};
	cout << SumArray<int>(arr1, 5) << endl;	
	cout << SumArray<double>(arr2, 5) << endl;
	return 0;
}