#include <iostream>
using namespace std;
class SoSimple
{
private:
	int num;
public:
	SoSimple(int n): num(n) 
	{
		cout << "New Object: " << this << endl;
	} // Constructor
	SoSimple(const SoSimple& copy): num(copy.num)
	{
		cout << "New copy object: " << this << endl;
	} // Copy Constructor
	~SoSimple()
	{
		cout << "Destroy object: " << this << endl;
	} // Destructor
};
SoSimple SimpleFuncObj(SoSimple ob)
{
	cout << "Parameter address: " << &ob << endl;
	return ob;
}
int main(int argc, char** argv)
{
	SoSimple obj(7);
	SimpleFuncObj(obj);
	cout << endl;
	SoSimple tempRef = SimpleFuncObj(obj);
	cout << "Return obj: " << &tempRef << endl;
	return 0;
}