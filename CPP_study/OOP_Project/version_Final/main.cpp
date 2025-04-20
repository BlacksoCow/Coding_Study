#include <iostream>
#include "String.h"
#include "AccountHandler.h"
using namespace std;
istream& operator>>(istream& is, String& str)
{
	char string[MAXLEN + 1];
	fgets(string, MAXLEN + 1, stdin);
	string[strlen(string) - 1] = 0;
	str = String(string);
	return is;
} // Custom >> overload for String
ostream& operator<<(ostream& os, const String& str)
{
	if(str.string == nullptr)
	{
		os << "";
		return os;
	}
	os << str.string;
	return os;
} // Custom << overload for String
int main(int argc, char** argv)
{
	int option;
	AccountHandler handler;
	while(true)
	{
		handler.PrintMenu();
		try
		{
			cin >> option;
			if(cin.fail())
				throw "\nOption should be a number";
		}
		catch(const char* error)
		{
			cout << error << endl;
			cout << "Option is 1 to 5" << endl << endl;
			cin.clear();
			cin.ignore(IGNORE, '\n');
			continue;
		}
		cin.ignore();
		cout << endl;
		switch(option)
		{
			case OPTION::MAKE:
				if(handler.GetIndex() >= MAXIMUM)
				{
					cout << "Account at maximum" << endl << endl;
					break;
				}
				handler.MakeAccount();
				break;
			case OPTION::DEPOSIT:
				handler.Deposit();
				break;
			case OPTION::WITHDRAW:
				handler.Withdraw();
				break;
			case OPTION::PRINT:
				handler.ShowAll();
				break;
			case OPTION::EXIT:
				cout << "Exit program" << endl;
				return 0;
			default:
				cout << "Wrong option selected" << endl;
				cout << "Option is 1 to 5" << endl << endl;
		}
	}
}