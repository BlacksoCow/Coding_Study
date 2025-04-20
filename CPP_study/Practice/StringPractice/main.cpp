#include <iostream>
#include "String.h"
using namespace std;
istream& operator>>(istream& is, String& str)
{
	char string[MAXLEN + 1];
	fgets(string, MAXLEN + 1, stdin);
	string[strlen(string) - 1] = '\0';
	str = String(string);
	return is;
}
ostream& operator<<(ostream& os, const String& str)
{
	if(str.string == nullptr)
	{
		os << "";
		return os;
	}
	os << str.string;
	return os;
}
int main(int argc, char** argv)
{
	String str1 = "String 1 ";
	String str2 = "String 2 ";
	cout << str1 << str2 << endl;
	String str3 = str1 + str2;
	cout << str3 << endl;
	
	String str4;
	str4 = str2 + str1;
	cout << str4 << endl;
	
	if(str3 != str4)
		cout << "Different" << endl;
	str3 += str1;
	str4 += str2;
	cout << "str3: " << str3 << endl;
	cout << "str4: " << str4 << endl;
	
	String temp;
	temp = str3;
	str3 = str4;
	str4 = temp;
	
	if(str3 != str4)
		cout << "str3: " << str3 << endl;
		cout << "str4: " << str4 << endl;
	
	String str5;
	cout << "str5: " << str5 << endl;
	str5 += "Added string";
	cout << "str5: " << str5 << endl;
	
	String str6;
	cin >> str6;
	String str7;
	cin >> str7;
	String str8 = str6 + str7;
	String str9 = str8 + " lol";
	cout << (str9 += str6) << endl;
	
	return 0;
}