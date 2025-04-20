#include <stdio.h>
#include "InfixCalculator.h"
int main(int argc, char** argv)
{
	char arr1[] = "((1-2)+3)*(5-2)";
	char arr2[] = "(1+2)*3";
	char arr3[] = "2+8*5/4";
	/*ConvToPost(arr1);
	printf("Post result: %s = %d\n", arr1, EvaluatePost(arr1));
	ConvToPost(arr2);
	printf("Post result: %s = %d\n", arr2, EvaluatePost(arr2));
	ConvToPost(arr3);
	printf("Post result: %s = %d\n", arr3, EvaluatePost(arr3));*/
	printf("Result: %s = %d\n", arr1, Calculate(arr1));
	printf("Result: %s = %d\n", arr2, Calculate(arr2));
	printf("Result: %s = %d\n", arr3, Calculate(arr3));
	return 0;
}