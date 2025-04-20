#include <iostream>
#include "Calculator.h"
using namespace std;
int Calculator::Add(const int& a, const int& b)
{
	plus++;
	return a + b;
}
int Calculator::Min(const int& a, const int& b)
{
	minus++;
	return a - b;
}
int Calculator::Mul(const int& a, const int& b)
{
	plus++;
	return a * b;
}
int Calculator::Div(const int& a, const int& b)
{
	if(!b)
	{
		cout << "0 division";
		return 0;
	}
	divide++;
	return a / b;
}
double Calculator::Add(const double& a, const double& b)
{
	plus++;
	return a + b;
}
double Calculator::Min(const double& a, const double& b)
{
	minus++;
	return a - b;
}
double Calculator::Mul(const double& a, const double& b)
{
	plus++;
	return a * b;
}
double Calculator::Div(const double& a, const double& b)
{
	if(!b)
	{
		cout << "0 division";
		return 0;
	}
	divide++;
	return a / b;
}
void Calculator::ShowOpCount()
{
	cout << "plus : " << plus << " ";
	cout << "minus : " << minus << " ";
	cout << "times : " << times << " ";
	cout << "divide : " << divide << endl;
	return;
}