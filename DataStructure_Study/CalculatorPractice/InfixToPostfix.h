#ifndef __INFIXTOPOSTFIX_H__
#define __INFIXTOPOSTFIX_H__

#include "ListStack.h"
#define TRUE 1
#define FALSE 0

int GetValue(char op);
int WhoPrecedes(char op1, char op2);
void ConvToPost(char exp[]); // Converges exp into postfix

#endif