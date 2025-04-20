#include <iostream>
using namespace std;
int main(int argc, char** argv)
{
	int sales;
	cout << "Input sales price(-1 to exit): ";
	cin >> sales;
	while(sales != -1)
	{
		cout << "This month's pay: " << 50 + sales * 0.12 << endl;
		cout << "Input sales price(-1 to exit): ";
		cin >> sales;
	}
	cout << "Exit program" << endl;
	return 0;
}