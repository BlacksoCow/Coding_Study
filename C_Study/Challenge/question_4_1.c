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
void ShowInfo(Book book[])
{
	for(int i = 0; i < 3; i++)
	{
		printf("Book %d\n", i + 1);
		printf("Author: %s\n", book[i].author);
		printf("Title: %s\n", book[i].title);
		printf("Pages: %d\n\n", book[i].page);
	}
	return;
}
int main(int argc, char** argv)
{
	puts("Input book inforamtion");
	Book book[3];
	for(int i = 0; i < 3; i++)
	{
		fputs("Author: ", stdout);
		fgets(book[i].author, 50 ,stdin);
		RemoveEnter(book[i].author, strlen(book[i].author));
		fputs("Title: ", stdout);
		fgets(book[i].title, 50, stdin);
		RemoveEnter(book[i].title, strlen(book[i].title));
		fputs("Pages: ", stdout);
		scanf("%d", &(book[i].page));
		getchar();
	}
	putchar('\n');
	ShowInfo(book);
	return 0;
}