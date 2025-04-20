#include <stdio.h>
#include <string.h>
typedef struct
{
	char title[50], author[50];
	int page;
} Book;
void RemoveEnter(char string[], int len)
{
	string[len - 1] = '\0';
	return;
}
void GetInfo(Book* book)
{
	fputs("Author: ", stdout);
	fgets(book->author, 50 ,stdin);
	RemoveEnter(book->author, strlen(book->author));
	fputs("Title: ", stdout);
	fgets(booktitle, 50, stdin);
	RemoveEnter(book->title, strlen(book->title));
	fputs("Pages: ", stdout);
	scanf("%d", &(book->page));
	getchar();
	return;
}
void ShowInfo(Book** book)
{
	for(int i = 0; i < 3; i++)
	{
		printf("Book %d\n", i + 1);
		printf("Author: %s\n", book[i]->author);
		printf("Title: %s\n", book[i]->title);
		printf("Pages: %d\n\n", book[i]->page);
	}
	return;
}
int main(int argc, char** argv)
{
	puts("Input book inforamtion");
	Book** book = (Book**)malloc(3 * sizeof(Book*));
	for(int i = 0; i < 3; i++)
		GetInfo(book[i]);
	putchar('\n');
	ShowInfo(book);
	return 0;
}