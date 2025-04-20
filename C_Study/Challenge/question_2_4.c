#include <stdio.h>
#include <stdbool.h>
int Length(char word[])
{
	int i = 0, length = 0;
	while(word[i++])
		length++;
	return length;
}
bool isPalindrome(char word[], int len)
{
	for(int i = 0; i < len / 2; i++)
	{
		if(word[i] != word[len - i - 1])
			return false;
	}
	return true;
}
int main(void)
{
	char word[100];
	int len = 0;
	printf("Input word: ");
	scanf("%s", word);
	len = Length(word);
	if(isPalindrome(word, len))
		printf("Palindrome\n");
	else
		printf("Not palindrome\n");
	return 0;
}