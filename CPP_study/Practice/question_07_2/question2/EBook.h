#ifndef __EBOOK_H__
#define __EBOOK_H__

#include <iostream>
#include <cstring>
using std::cout;
using std::endl;
class EBook: public Book
{
private:
	char* DRMKey;
public:
	EBook(const char* title, const char* ISBN, const int& price, const char* DRMKey)
		:Book(title, ISBN, price)
	{
		this->DRMKey = new char[strlen(DRMKey)+ 1];
		strcpy(this->DRMKey, DRMKey);
	} // Constructor
	inline void ShowEBookInfo() const
	{
		ShowBookInfo();
		cout << "Configuration key: " << DRMKey << endl;
		return;
	}
	~EBook()
	{
		delete[] DRMKey;
	} // Destructor
};

#endif