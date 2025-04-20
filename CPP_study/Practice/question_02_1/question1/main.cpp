#include <iostream>
#include "Function.h"
using namespace std;
int main(int argc, char** argv)
{
	int num;
	cout << "Input num: ";
	cin >> num;
	cin.ignore();
	PlusOne(num);
	PlusMinus(num);
	cout << "Result: " << num << endl;
	return 0;
}