#include <string.h>
#include <ctype.h>
#include "PostCalculator.h"
int EvaluatePost(char exp[])
{
	Stack stack;
	StackInit(&stack);
	int ret, len = strlen(exp);
	char tok;
	for(int i = 0; i < len; i++)
	{
		tok = exp[i];
		if(isdigit(tok))
			SPush(&stack, tok - '0'); // Changing tok into integer
		else
		{
			int num2 = SPop(&stack);
			int num1 = SPop(&stack);
			switch(tok)
			{
				case '+':
					SPush(&stack, num1 + num2);
					break;
				case '-':
					SPush(&stack, num1 - num2);
					break;
				case '*':
					SPush(&stack, num1 * num2);
					break;
				case '/':
					SPush(&stack, num1 / num2);
					break;
			}
		}
	}
	ret = SPop(&stack);
	SFree(&stack);
	return ret;
}