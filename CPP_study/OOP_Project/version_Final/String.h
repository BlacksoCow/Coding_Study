#ifndef __STRING_H__
#define __STRING_H__

#include <iostream>
#include <cstring>
#define MAXLEN 1000
using std::cout;
using std::endl;
class String
{
private:
	char* string;
	int len;
public:
	String(); // Constructor
	String(const char*); // Constructor
	String(const String&); // Copy constructor
	String& operator=(const String&); // Assignment operator
	bool operator==(const String&) const; // Identical operator
	bool operator!=(const String&) const; // Inidentical operator
	String operator+(const String&) const; // Concatenate operator
	String& operator+=(const String&); // Self-concatenate operator
	inline int Length() const { return len; } // Length return function
	friend std::istream& operator>>(std::istream&, String&);
	friend std::ostream& operator<<(std::ostream&, const String&);
	~String(); // Destructor
};

#endif