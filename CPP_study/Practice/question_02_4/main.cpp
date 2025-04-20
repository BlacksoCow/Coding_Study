#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main(int argc, char** argv)
{
	srand(int(time(NULL)));
	for(int i = 1; i <= 5; i++)
		cout << i << ". " << rand() % 100 << endl;
	return 0;
}