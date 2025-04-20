#include <iostream>
#include "Gun.h"
#include "Police.h"
using namespace std;
int main(int argc, char** argv)
{
	Police pman1(1, 3);
	pman1.Shot();
	pman1.PutHandcuff();
	
	Police pman2(0, 2);
	pman2.Shot();
	pman2.PutHandcuff();
	
	Police temp = pman2;
	pman2 = pman1;
	pman1 = temp;
	
	pman1.Shot();
	pman1.PutHandcuff();
	
	pman2.Shot();
	pman2.PutHandcuff();
	
	return 0;
}