#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char** argv)
{
	char string[20];
	FILE* fp = fopen("mystory.txt", "rt");
	if(!fp)
	{
		puts("File loading failed");
		return -1;
	}
	fscanf(fp, "%s", string);
	printf("%s\n", string);
	printf("%d\n", string[strlen(string)]);
}