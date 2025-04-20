#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
bool JangGenBo(void)
{
	static int win = 0;
	static int draw = 0;
	int choice, computer = 0;
	printf("Rock: 1, Scissors: 2, Paper: 3\n");
	printf("Input your choice: ");
	scanf("%d", &choice);
	srand((int)time(NULL));
	while(!computer)
		computer = rand() % 4;
	switch(choice)
	{
		case 1:
			printf("Your choice: Rock, ");
			break;
		case 2:
			printf("Your choice: Scissors, ");
			break;
		case 3:
			printf("Your choice: Paper, ");
			break;
		default:
			printf("Wrong choice! Game over!\n");
			printf("%d wins %d draws\n", win, draw);
			return false;
	}
	switch(computer)
	{
		case 1:
			printf("Computer's choice: Rock\n");
			break;
		case 2:
			printf("Computer's choice: Scissors\n");
			break;
		case 3:
			printf("Computer's choice: Paper\n");
			break;
		default:
			printf("\nSystem error\n");
			return false;
	}
	if(choice == computer)
	{
		printf("Draw!\n\n");
		draw++;
		return true;
	}
	else if (  (choice == 1 && computer == 2)
			|| (choice == 2 && computer == 3)
			|| (choice == 3 && computer == 1)  )
	{
		printf("Win!\n\n");
		win++;
		return true;
	}
	else
	{
		printf("Lose! Game Over\n\nResult: ");
		printf("%d win %d draw\n", win, draw);
		return false;
	}
}
int main(int argc, char** argv)
{
	while(JangGenBo()) { }
	return 0;
}