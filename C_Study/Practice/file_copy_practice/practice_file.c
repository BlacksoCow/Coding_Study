#include <stdio.h>
#include <string.h>
int main(int argc, char** argv)
{
	FILE* src = fopen("HelloWorld.bin", "rb");
	FILE* des = fopen("destination_file.bin", "wb");
	char buf[100];
	int readCnt;
	if(!src || !des)
	{
		fputs("File loading failed\n", stdout);
		return -1;
	}
	while((readCnt = fread((void*)buf, 1, sizeof(buf), src)) == sizeof(buf))
		fwrite((void*)buf, 1, readCnt, des);
	if(feof(src) != 0)
	{
		fwrite((void*)buf, 1, readCnt, des);
		puts("Copy complete");
	}
	else
		puts("Copy failed");
	fclose(src);
	fclose(des);
	return 0;
}