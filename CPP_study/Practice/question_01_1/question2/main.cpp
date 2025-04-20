#include <iostream>
using namespace std;
int main(int argc, char** argv)
{
	char name[50], tel[14];
	cout << "Input your name: ";
	cin.getline(name, sizeof(name) - 1, '\n');
	cout << "Input your tel number(including -): ";
	cin.getline(tel, sizeof(tel) - 1, '\n');
	cout << "Name: " << name << endl;
	cout << "Tel: " << tel << endl;
	return 0;
}