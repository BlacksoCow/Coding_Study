#include <iostream>
using namespace std;
int main(int argc, char** argv)
{
	const int num = 12;
	const int* ptr = &num;
	const int*(&ref) = ptr;
	cout << "num: " << *ptr << endl;
	cout << "num: " << *ref << endl;
	return 0;
}