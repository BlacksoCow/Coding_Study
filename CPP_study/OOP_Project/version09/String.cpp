#include "String.h"
String::String()
	:len(0)
{
	string = nullptr;
} // Constructor
String::String(const char* str)
	:len(strlen(str))
{
	string = new char[strlen(str) + 1];
	strcpy(string, str);
} // Constructor
String::String(const String& str)
{
	if(!str.len)
	{
		len = 0;
		string = nullptr;
	}
	else
	{
		len = str.len;
		string = new char[len + 1];
		strcpy(string, str.string);
	}
} // Copy constructor
String& String::operator=(const String& str)
{
	if(len)
		delete[] string;
	len = str.len;
	string = new char[strlen(str.string) + 1];
	strcpy(string, str.string);
	return *this;
} // Assignment operator
bool String::operator==(const String& str) const
{
	if(!strcmp(string, str.string))
		return true;
	return false;
}
bool String::operator!=(const String& str) const
{
	if(!strcmp(string, str.string))
		return false;
	return true;
}
String String::operator+(const String& str) const
{
	int newlen = len + str.len;
	char* retstr = new char[newlen + 1];
	strcpy(retstr, string);
	strcat(retstr, str.string);
	String ret = retstr;
	delete[] retstr;
	return ret;
}
String& String::operator+=(const String& str)
{
	int newlen = len + str.len;
	char* temp = new char[len + 1];
	if(len)
	{
		strcpy(temp, string);
		delete[] string;
	}
	string = new char[newlen + 1];
	strcpy(string, temp);
	strcat(string, str.string);
	len = newlen;
	return *this;
}
String::~String()
{
	if(len)
		delete[] string;
} // Destructor