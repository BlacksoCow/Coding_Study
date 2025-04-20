#include "Friend.h"
void MyFriendInfo::ShowMyFriendInfo() const
{
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	return;
}
void MyFriendDetailInfo::ShowMyFriendDetailInfo() const
{
	ShowMyFriendInfo();
	cout << "Address: " << address << endl;
	cout << "Tel number: " << phone << endl;
	return;
}