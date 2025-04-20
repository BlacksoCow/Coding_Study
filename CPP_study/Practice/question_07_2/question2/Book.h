#ifndef __BOOK_H__
#define __BOOK_H__

#include <iostream>
#include <cstring>
using std::cout;
using std::endl;
class Book
{
private:
	char* title;
	char* isbn;
	int price;
public:
	Book(const char* title, const char* ISBN, const int& price)
		:price(price)
	{
		this->title = new char[strlen(title) + 1];
		strcpy(this->title, title);
		this->isbn = new char[strlen(ISBN) + 1];
		strcpy(this->isbn, ISBN);
	} // Constructor
	inline void ShowBookInfo() const
	{
		cout << "Title: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "Price: " << price << endl;
		return;
	}
	~Book()
	{
		delete[] title;
		delete[] isbn;
	} // Destructor
};

#endif