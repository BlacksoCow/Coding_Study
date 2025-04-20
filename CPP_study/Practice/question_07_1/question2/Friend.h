#ifndef __FRIEND_H__
#define __FRIEND_H__

#include <iostream>
using std::cout;
using std::endl;
class MyFriendInfo
{
private:
	const char* name;
	const int age;
public:
	MyFriendInfo(const char* name, const int& age)
		:name(name), age(age)
	{
		cout << "Base constructor called" << endl;
	}
	void ShowMyFriendInfo() const;
	~MyFriendInfo()
	{
		cout << "Base destructor called" << endl;
	}
};

class MyFriendDetailInfo: public MyFriendInfo
{
private:
	const char* address;
	const char* phone;
public:
	MyFriendDetailInfo(const char* name, const int& age, const char* address, const char* phone)
		:MyFriendInfo(name, age), address(address), phone(phone)
	{
		cout << "Derived constructor called" << endl;
	}
	void ShowMyFriendDetailInfo() const;
	~MyFriendDetailInfo()
	{
		cout << "Derived destructor called" << endl;
	}
};

#endif