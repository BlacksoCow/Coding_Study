#ifndef __NAMECARD_H__
#define __NAMECARD_H__

#include <iostream>
#include <cstring>
using std::cout;
using std::endl;
namespace COMP_POS
{
	enum { CLERK, SENIOR, ASSIST, MANAGER };
}
class Namecard
{
private:
	char* name;
	char* company;
	char* tel;
	int pos;
public:
	Namecard(const char* Name, const char* Com, const char* Tel, const int& rank)
		:pos(rank) // Constructor
	{
		name = new char[strlen(Name) + 1];
		strcpy(name, Name);
		company = new char[strlen(Com) + 1];
		strcpy(company, Com);
		tel = new char[strlen(Tel) + 1];
		strcpy(tel, Tel);
	}
	Namecard(const Namecard& NC)
		:pos(NC.pos) //Copy constructor
	{
		name = new char[strlen(NC.name) + 1];
		strcpy(name, NC.name);
		company = new char[strlen(NC.company) + 1];
		strcpy(company, NC.company);
		tel = new char[strlen(tel) + 1];
		strcpy(tel, NC.tel);
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
	~Namecard() // Destructor
	{
		delete[] name;
		delete[] company;
		delete[] tel;
	}
};

#endif