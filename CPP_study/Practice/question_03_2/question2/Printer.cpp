#include <iostream>
#include <cstring>
#include "Printer.h"
using std::cout;
using std::endl;
void Printer::SetString(const char* temp)
{
	strncpy(string, temp, MAXLEN + 1);
	return;
}
void Printer::ShowString()
{
	cout << "Current String: " << string << endl;
	return;
}