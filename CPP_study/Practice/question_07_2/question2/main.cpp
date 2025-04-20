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
	return 0;
}