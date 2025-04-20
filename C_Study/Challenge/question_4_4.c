#include <stdio.h>
int main(int argc, char** argv)
{
	int astart = 0, pstart = 0;
	char word[51];
	FILE* fp = fopen("Song.txt", "rt");
	if(!fp)
	{
		puts("File loading failed");
		return -1;
	}
	while(fscanf(fp, "%s", word) != EOF)
	{
		if(word[0] == 'A' || word[0] == 'a')
		{
			puts(word);
			astart++;
		}
		else if(word[0] == 'P' || word[0] == 'p')
		{
			puts(word);
			pstart++;
		}
	}
	printf("A start: %d\n", astart);
	printf("P start: %d\n", pstart);
	fclose(fp);
	return 0;
	/* char word;
	int astart = 0, pstart = 0;
	FILE* fp = fopen("Song.txt", "rt");
	if(!fp)
	{
		puts("FIle read failed");
		return -1;
	}
	while(!feof(fp))
	{
		word = fgetc(fp);
		if(word == 'A' || word == 'a')
			astart++;	
		else if(word == 'P' || word == 'p')
			pstart++;
		while((word != ' ' && word != '\n') && word != EOF)
			word = fgetc(fp);
	}
	printf("A start: %d\n", astart);
	printf("P start: %d\n", pstart);
	fclose(fp);
	return 0; */
}