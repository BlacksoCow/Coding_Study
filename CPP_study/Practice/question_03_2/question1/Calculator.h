#ifndef __CALC_H__
#define __CALC_H__

class Calculator
{
private:
	int plus, minus, times, divide;
public:
	void Init();
	int Add(const int&, const int&);
	int Min(const int&, const int&);
	int Mul(const int&, const int&);
	int Div(const int&, const int&);
	double Add(const double&, const double&);
	double Min(const double&, const double&);
	double Mul(const double&, const double&);
	double Div(const double&, const double&);
	void ShowOpCount();
};
inline void Calculator::Init()
{
	plus = minus = times = divide = 0;
	return;
}

#endif