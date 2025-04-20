#ifndef __NAMECARD_H__
#define __NAMECARD_H__

#include <iostream>
#include <cstring>
using std::cout;
using std::endl;
namespace COMP_POS
{ enum Rank { CLERK, SENIOR, ASSIST, MANAGER }; }
class Namecard
{
private:
	char* name;
	char* company;
	char* tel;
	int pos;
public:
	Namecard(const char* Name, const char* Com, const char* Tel, const int& rank)
		:pos(rank)
	{
		name = new char[strlen(Name) + 1];
		strcpy(name, Name);
		company = new char[strlen(Com) + 1];
		strcpy(company, Com);
		tel = new char[strlen(Tel) + 1];
		strcpy(tel, Tel);
	}
	void ShowNameCardInfo()
	{
		cout << "Name: " << name << endl;
		cout << "Company: " << company << endl;
		cout << "Tel: " << tel << endl;
		cout << "Position: ";
		switch(pos)
		{
			case COMP_POS::CLERK:
				cout << "Clerk" << endl;
				break;
			case COMP_POS::SENIOR:
				cout << "Senior" << endl;
				break;
			case COMP_POS::ASSIST:
				cout << "Assist" << endl;
				break;
			case COMP_POS::MANAGER:
				cout << "Manager" << endl;
				break;
			default:
				cout << "Wrong position" << endl;
		}
		return;
	}
	~Namecard()
	{
		delete[] name;
		delete[] company;
		delete[] tel;
	}
};

#endif