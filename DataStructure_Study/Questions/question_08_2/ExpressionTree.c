#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ListStack.h"
#include "ExpressionTree.h"
#define MAXLEN 1000
BTreeNode* MakeExpTree(char exp[])
{
	Stack stack;
	BTreeNode* node;
	StackInit(&stack);
	for(int i = 0; i < strlen(exp); i++)
	{
		node = MakeBTreeNode();
		if(isdigit(exp[i]))
			SetData(node, exp[i] - '0');
		else
		{
			MakeRightSubTree(node, SPop(&stack));
			MakeLeftSubTree(node, SPop(&stack));
			SetData(node, exp[i]);
		}
		SPush(&stack, node);
	}
	node = SPop(&stack);
	SFree(&stack);
	return node;
}
int EvaluateExpTree(BTreeNode* bt)
{
	if(GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL)
		return GetData(bt);
	int res1 = EvaluateExpTree(GetLeftSubTree(bt));
	int res2 = EvaluateExpTree(GetRightSubTree(bt));
	switch(GetData(bt))
	{
		case '+':
			return res1 + res2;
		case '-':
			return res1 - res2;
		case '*':
			return res1 * res2;
		case '/':
			return res1 / res2;
		default:
			puts("Operator error");
			exit(-1);
	}
}
void ShowData(BTreeNode* bt)
{
	int data = GetData(bt);
	if(0 <= data && data <= 9)
		printf("%d", data);
	else
		printf("%c", data);
	return;
} // Action funtion
void ShowPrefixExp(BTreeNode* bt)
{
	TraverseAction(bt, PreOrder, ShowData);
	return;
}
void ShowInfixExp(BTreeNode* bt)
{
	if(GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL)
	{
		ShowData(bt);
		return;
	} // If terminal node, just ShowData
	putchar('(');
	ShowInfixExp(GetLeftSubTree(bt));
	ShowData(bt);
	ShowInfixExp(GetRightSubTree(bt));
	putchar(')');
	return;
}
void ShowPostfixExp(BTreeNode* bt)
{
	TraverseAction(bt, PostOrder, ShowData);
	return;
}