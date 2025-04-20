#include <iostream>
#include "Book.h"
#include "EBook.h"
int main(int argc, char** argv)
{
	Book book("Good C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;
	EBook ebook("Good C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();
	cout << endl;
	Book book2("A", "B", 1);
	EBook ebook2("C", "D", 2, "E");
	book2.ShowBookInfo();
	ebook2.ShowEBookInfo();
	cout << endl;
	book2 = book;
	ebook2 = ebook;
	book2.ShowBookInfo();
	ebook2.ShowEBookInfo();
	return 0;
}