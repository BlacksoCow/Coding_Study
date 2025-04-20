#include <iostream>
using namespace std;
int main(int argc, char** argv)
{
	int arr[5], sum = 0;
	for(int i = 0; i < 5; i++)
	{
		cout << "Input number " << i + 1 << ": ";
		cin >> arr[i];
		sum += arr[i];
	}
	cout << "Sum: " << sum << endl;
	return 0;
}