#include <stdio.h>
#include "ExpressionTree.h"
int main(int argc, char** argv)
{
	char exp[] = "134-/73*+";
	BTreeNode* expTree = MakeExpTree(exp);
	printf("Prefix expression: ");
	ShowPrefixExp(expTree);
	putchar('\n');
	printf("Infix expression: ");
	ShowInfixExp(expTree);
	putchar('\n');
	printf("Postfix expression: ");
	ShowPostfixExp(expTree);
	putchar('\n');
	printf("Evaluation result: %d\n", EvaluateExpTree(expTree));
	DestroyTree(expTree);
	return 0;
}