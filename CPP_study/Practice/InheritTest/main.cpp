#include <iostream>
#include "test.h"
int main(int argc, char** argv)
{
	Base* b1 = new Base(20);
	Base* b2 = new Base(30);
	Derived* d1 = new Derived(1, 2);
	Derived* d2 = new Derived(3, 4);
	
	Base* arr[4] = {b1, b2, d1, d2};	
	for(int i = 0; i < 4; i++)
		arr[i]->ShowNum();
	for(int i = 0; i < 4; i++)
		delete arr[i];
	return 0;
}