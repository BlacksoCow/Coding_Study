#ifndef __IOS_H__
#define __IOS_H__

#include <cstdio>
namespace mystd
{
class ostream
{
public:
	ostream& operator<<(const char* str)
	{
		printf("%s", str);
		return *this;
	}
	ostream& operator<<(char* str)
	{
		printf("%s", str);
		return *this;
	}
	ostream& operator<<(int num)
	{
		printf("%d", num);
		return *this;
	}
	ostream& operator<<(double num)
	{
		printf("%g", num);
		return *this;
	}
	ostream& operator<<(char c)
	{
		printf("%c", c);
		return *this;
	}
	ostream& operator<<(ostream&(*fp)(ostream&))
	{
		return (*fp)(*this);
	}
};
	static ostream& endl(ostream& ostm)
	{
		ostm << '\n';
		fflush(stdout);
		return ostm;
	}
	
	static ostream cout;

class istream
{
public:
	istream& operator>>(char* str)
	{
		scanf("%s", str);
		return *this;
	}
	istream& operator>>(char c)
	{
		scanf("%c", &c);
		return *this;
	}
	istream& operator>>(int num)
	{
		scanf("%d", &num);
		return *this;
	}
	istream& operator>>(double num)
	{
		scanf("%lf", &num);
		return *this;
	}
	
};
	static istream cin;
}

#endif