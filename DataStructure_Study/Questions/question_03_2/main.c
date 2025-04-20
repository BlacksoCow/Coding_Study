#include <stdio.h>
#include <stdlib.h>
#include "NameCard.h"
#include "ArrayList.h"
int main(int argc, char** argv)
{
	List list;
	LData data;
	ListInit(&list);
	LInsert(&list, MakeNameCard("Han", "010-5909-9897"));
	LInsert(&list, MakeNameCard("Ryu", "010-9573-5335"));
	LInsert(&list, MakeNameCard("Kim", "010-6614-7664"));
	if(LFirst(&list, &data))
	{
		do
		{
			if(NameCompare(data, "Ryu"))
			{
				puts("<Name found>");
				ShowNameCardInfo(data);
				ChangePhoneNum(data, "010-1234-5678");
				puts("<Changed data>");
				ShowNameCardInfo(data);
				data = LRemove(&list);
				free(data);
			}
		} while(LNext(&list, &data));
		
	}
	puts("<After data deleted>");
	if(LFirst(&list, &data))
	{
		do
		{
			ShowNameCardInfo(data);
		} while(LNext(&list, &data));
		printf("Total datas: %d\n", LCount(&list));
	}
	else
	{
		puts("No data in list");
		return 0;
	}
	return 0;
}