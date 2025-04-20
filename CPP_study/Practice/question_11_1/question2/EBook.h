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
	EBook& operator=(const EBook& ebook)
	{
		Book::operator=(ebook);
		delete[] DRMKey;
		this->DRMKey = new char[strlen(ebook.DRMKey) + 1];
		strcpy(this->DRMKey, ebook.DRMKey);
		return *this;
	} // Assignment operator
	inline void ShowEBookInfo() const
	{
		ShowBookInfo();
		cout << "Configuration key: " << DRMKey << endl;
		return;
	}
	~EBook()
	{
		delete[] DRMKey;
	} // DEstructor
};

#endif