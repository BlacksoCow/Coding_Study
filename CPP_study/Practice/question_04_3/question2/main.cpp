#include <iostream>
#include "Namecard.h"
int main(int argc, char** argv)
{
	Namecard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	Namecard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	Namecard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
	Namecard manManager("Han", "ROKARMY", "010-7777-8888", COMP_POS::MANAGER);
	manClerk.ShowNameCardInfo();
	cout << endl;
	manSenior.ShowNameCardInfo();
	cout << endl;
	manAssist.ShowNameCardInfo();
	cout << endl;
	manManager.ShowNameCardInfo();
	return 0;
}