#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAXLEN 50
typedef struct
{
	char name[MAXLEN + 1];
	char tel[14];
} Person;
enum {Insert = 1, Delete, Search, Modify, Print_All, Exit};
enum {Name = 1, Tel, Both};
void RemoveEnter(char string[], int maxlen)
{
	if(!(strlen(string) == maxlen - 1 && string[maxlen - 2] != '\n'))
		string[strlen(string) - 1] = '\0';
	else
		while(getchar() != '\n'); //Buffer clearance
	return;
}
bool CheckTel(char tel[])
{
	if(strlen(tel) != 13)
		return false;
	else if(tel[3] != '-' || tel[8] != '-')
		return false;
	for(int i = 0; i < 13; i++)
	{
		if(i == 3 || i == 8)
			continue;
		else if(!('0' <= tel[i] && tel[i] <= '9'))
			return false;
	}
	return true;
}
int InfoSearch(Person* people, char name[], int cnt)
{
	for(int i = 0; i < cnt; i++)
	{
		if(!strcmp(people[i].name, name))
			return i;
	}
	return -1;
}
int GetIndex(Person* people, char temp_name[], int cnt)
{
	int search_index;
	fgets(temp_name, MAXLEN + 1, stdin);
	RemoveEnter(temp_name, MAXLEN + 1);
	search_index = InfoSearch(people, temp_name, cnt);
	while(search_index == -1)
	{
		puts("No information found\nInput correct name\n");
		fputs("Input the name to search: ", stdout);
		fgets(temp_name, MAXLEN + 1, stdin);
		RemoveEnter(temp_name, MAXLEN + 1);
		search_index = InfoSearch(people, temp_name, cnt);
	}
	return search_index;
}
void CopyInfo(Person* dst, Person* src)
{
	strcpy(dst->name, src->name);
	strcpy(dst->tel, src->tel);
	return;
}
void PrintInfo(Person* people, int index)
{
	printf("Name: %s", people[index].name);
	printf("\tTel: %s\n", people[index].tel);
	return;
}
int FileRead(FILE* fp_read, Person** people, int* size)
{
	int cnt = 0;
	char trash1[10], trash2[10], trash3[10];
	if(fgetc(fp_read) == '<')
		return 0;
	while(!feof(fp_read))
	{
		fscanf(fp_read, "%s%s", trash1, trash2);
		fscanf(fp_read, "%s", (*people)[cnt].name);
		fscanf(fp_read, "%s", trash3);
		fscanf(fp_read, "%s", (*people)[cnt++].tel);
		if(cnt == *size)
		{
			*size += 5;
			*people = (Person*)realloc(*people, sizeof(Person) * (*size));
		}
	}
	return cnt;
}
void FileWrite(FILE* fp, Person* people, int cnt)
{
	if(!cnt)
	{
		fputs("<No information>", fp);
		return;
	}
	for(int i = 0; i < cnt - 1; i++)
	{
		fprintf(fp, "%d. Name: %s", i + 1, people[i].name);
		fprintf(fp, "\tTel: %s\n", people[i].tel);
	}
	fprintf(fp, "%d. Name: %s", cnt, people[cnt - 1].name);
	fprintf(fp, "\tTel: %s", people[cnt - 1].tel);
	return;
}
int main(int argc, char** argv)
{
	int menu, minimenu, search_index, cnt, size = 3;
	char temp_name[MAXLEN + 1], temp_tel[15], delete_name[MAXLEN + 1];
	FILE* fp_read = fopen("Telephone_book.txt", "rt");
	if(!fp_read)
	{
		puts("File reading failed");
		return -1;
	}
	Person* people = (Person*)malloc(sizeof(Person) * size); //Allocated in heap
	cnt = FileRead(fp_read, &people, &size);
	fclose(fp_read);
	FILE* fp_write = fopen("Telephone_book.txt", "wt");
	if(!fp_write)
	{
		puts("File opening failed");
		return -1;
	}
	puts("**********Telephone Book Program**********");
	while(true)
	{
		puts("*****MENU*****");
		puts("1. Insert");
		puts("2. Delete");
		puts("3. Search");
		puts("4. Modify");
		puts("5. Print All");
		puts("6. Exit");
		fputs("Choose the option: ", stdout);
		scanf("%d", &menu);
		putchar(getchar());
		switch(menu)
		{
			case Insert:
				puts("[INSERT](To exit, press ctrl + c)");
				printf("Input name(%d letters max): ", MAXLEN);
				fgets(temp_name, MAXLEN + 1, stdin);
				RemoveEnter(temp_name, MAXLEN + 1);
				strcpy(people[cnt].name, temp_name);
				temp_name[0] = 0;
				while(true)
				{
					fputs("Input tel number('-' is necessary): ", stdout);
					fgets(temp_tel, sizeof(temp_tel), stdin);
					RemoveEnter(temp_tel, sizeof(temp_tel));
					if(CheckTel(temp_tel))
					{
						strcpy(people[cnt++].tel, temp_tel);
						temp_tel[0] = 0;
						puts("**********DATA INSERTED**********\n");
						if(cnt == size)
						{
							size += 5;
							people = (Person*)realloc(people, sizeof(Person) * size);
						}
						break;
					}
					else
						puts("Wrong number format");
				}
				break;
			case Delete:
				if(!cnt)
				{
					puts("The book is empty");
					break;
				}
				puts("[DELETE](To exit, press ctrl + c)");
				fputs("Input the name to delete: ", stdout);
				search_index = GetIndex(people, temp_name, cnt);
				people[search_index].name[0] = 0;
				people[search_index].tel[0] = 0;
				cnt--;
				for(int i = search_index; i < cnt; i++)
					CopyInfo(&people[i], &people[i + 1]);
				people[cnt].name[0] = 0;
				people[cnt].tel[0] = 0;
				temp_name[0] = 0;
				puts("**********DATA DELETED**********\n");
				break;
			case Search:
				if(!cnt)
				{
					puts("The book is empty");
					break;
				}
				puts("[Search](To exit, press ctrl + c)");
				fputs("Input the name to search: ", stdout);
				search_index = GetIndex(people, temp_name, cnt);
				printf("[Data of %s]\n", temp_name);
				PrintInfo(people, search_index);
				temp_name[0] = 0;
				puts("**********DATA PRINTED**********\n");
				break;
			case Modify:
				if(!cnt)
				{
					puts("The book is empty");
					break;
				}
				puts("[Modify](To exit, press ctrl + c)");
				fputs("Input the name of data to modify: ", stdout);
				search_index = GetIndex(people, temp_name, cnt);
				while(true)	
				{	
					fputs("Select the option to modify(Name: 1, Tel: 2, Both: 3): ", stdout);
					scanf("%d", &minimenu);
					temp_name[0] = 0;
					putchar(getchar());
					switch(minimenu)
					{
						case Name:
							puts("[Modfiying name]");
							fputs("Input modified name: ", stdout);
							fgets(temp_name, MAXLEN + 1, stdin);
							RemoveEnter(temp_name, MAXLEN + 1);
							people[search_index].name[0] = 0;
							strcpy(people[search_index].name, temp_name);
							temp_name[0] = 0;
							puts("**********NAME MODIFIED**********\n");
							break;
						case Tel:
							puts("[Modifying tel number]");
							while(true)
							{
								fputs("Input modified tel number('-' is necessary): ", stdout);
								fgets(temp_tel, sizeof(temp_tel), stdin);
								RemoveEnter(temp_tel, sizeof(temp_tel));
								if(CheckTel(temp_tel))
								{	
									people[search_index].tel[0] = 0;
									strcpy(people[search_index].tel, temp_tel);
									temp_tel[0] = 0;
									puts("**********TEL MODIFIED**********\n");
									break;
								}
								else
									puts("Wrong number format\n");
							}
							break;
						case Both:
							puts("[Modifying name and tel number]");
							fputs("Input modified name: ", stdout);
							fgets(temp_name, MAXLEN + 1, stdin);
							RemoveEnter(temp_name, MAXLEN + 1);
							people[search_index].name[0] = 0;
							strcpy(people[search_index].name, temp_name);
							temp_name[0] = 0;
							while(true)
							{
								fputs("Input modified tel number('-' is necessary): ", stdout);
								fgets(temp_tel, sizeof(temp_tel), stdin);
								RemoveEnter(temp_tel, sizeof(temp_tel));
								if(CheckTel(temp_tel))
								{
									people[search_index].tel[0] = 0;
									strcpy(people[search_index].tel, temp_tel);
									temp_tel[0] = 0;
									break;
							}
								else
									puts("Wrong number format\n");
							}
							puts("**********DATA MODIFIED**********\n");
							break;
						default:
							puts("Wrong option selected");
							puts("Select option from 1 to 3");
							continue;
					}
					break;
				}
				break;
			case Print_All:
				if(!cnt)
				{
					puts("The book is empty");
					break;
				}
				puts("[Print All Data]");
				for(int i = 0; i < cnt; i++)
				{
					printf("%d. ", i + 1);
					PrintInfo(people, i);
				}
				puts("**********EVERY DATA PRINTED**********\n");
				break;
			case Exit:
				FileWrite(fp_write, people, cnt);
				fclose(fp_write);
				free(people);
				puts("**********EXIT PROGRAM**********");
				return 0;
			default:
				puts("Wrong option selected");
				puts("Select option from 1 to 6");
		}
	}
}