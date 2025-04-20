#include <iostream>
using namespace std;
int BoxVolume(int length, int width, int height)
{
	return length * width * height;
}
int BoxVolume(int length, int width)
{
	return length * width;;
}
int BoxVolume(int length)
{
	return length;
}
int BoxVolume(void)
{
	return 1;
}
int main(int argc, char** argv)
{
	cout << "[3, 3, 3]: " << BoxVolume(3, 3, 3) << endl;
	cout << "[5, 5, D]: " << BoxVolume(5, 5) << endl;
	cout << "[7, D, D]: " << BoxVolume(7) << endl;
	cout << "[D, D, D]: " << BoxVolume() << endl;
	return 0;
}