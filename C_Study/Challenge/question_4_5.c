#include <stdio.h>
int main(int argc, char** argv)
{
	FILE* fp1 = fopen("Song.txt", "rt");
	FILE* fp2 = fopen("Song2.txt", "rt");
	char word1 = fgetc(fp1), word2 = fgetc(fp2);
	if(!fp1 || !fp2)
	{
		puts("File loading failed");
		return -1;
	}
	while(!feof(fp1) && !feof(fp2))
	{
		if(word1 != word2)
		{
			puts("Files don't match");
			fclose(fp1);
			fclose(fp2);
			return 0;
		}
		word1 = fgetc(fp1);
		word2 = fgetc(fp2);
		printf("%c %c\n", word1, word2);
	}
	printf("%d %d", word1, word2);
	if(!(feof(fp1) * feof(fp2)))
	{
		puts("FIles don't match");
		fclose(fp1);
		fclose(fp2);
		return 0;
	}
	puts("Identical files");
	fclose(fp1);
	fclose(fp2);
	return 0;
}