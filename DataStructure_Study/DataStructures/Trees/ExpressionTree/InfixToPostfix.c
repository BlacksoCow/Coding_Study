#include <stdlib.h>
#include <string.h>
#include "InfixToPostfix.h"
int GetValue(char op)
{
	switch(op)
	{
		case '(':
			return 0;
		case '+': case '-':
			return 1;
		case '*': case '/':
			return 2;
		default:
			return -1;
	}
}
int WhoPrecedes(char op1, char op2)
{
	int OP1 = GetValue(op1);
	int OP2 = GetValue(op2);
	return OP1 >= OP2 ? TRUE : FALSE;
}
void ConvToPost(char exp[])
{
	Stack stack;
	StackInit(&stack);
	int retidx = 0, len = strlen(exp);
	char* ret = (char*)calloc(sizeof(char), len + 1);
	char tok;
	for(int i = 0; i < len; i++)
	{
		tok = exp[i];
		if(isdigit(tok))
			ret[retidx++] = tok;
		else
		{
			switch(tok)
			{
				case '(':
					SPush(&stack, tok);
					break;
				case ')':
					while(SPeek(&stack) != '(')
						ret[retidx++] = SPop(&stack);
					SPop(&stack);
					break;
				case '+': case '-':
				case '*': case '/':
					while(!SIsEmpty(&stack) && WhoPrecedes(SPeek(&stack), tok) == TRUE)
						ret[retidx++] = SPop(&stack);
					SPush(&stack, tok);
					break;
			}
		}
	}
	while(!SIsEmpty(&stack))
		ret[retidx++] = SPop(&stack);
	strcpy(exp, ret);
	free(ret);
	SFree(&stack);
	return;
}