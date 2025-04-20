#include <iostream>
#include "Bound2DArray.h"
using namespace std;
int main(int argc, char** argv)
{
	int ver = 3, hor = 4;
	Bound2DArray arr(ver, hor);
	for(int i = 0; i < ver; i++)
		for(int j = 0; j < hor; j++)
			arr[i][j] = (i + 1) * (j + 1);
	arr.ShowAllInfo();
	return 0;
}