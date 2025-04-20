#include <stdlib.h>
#include <string.h>
#include "InfixCalculator.h"
int Calculate(char exp[])
{
	int ret, len = strlen(exp);
	char* post = (char*)malloc(len + 1);
	strcpy(post, exp);
	ConvToPost(post);
	ret = EvaluatePost(post);
	free(post);
	return ret;
}