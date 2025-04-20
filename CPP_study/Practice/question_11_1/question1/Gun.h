#ifndef __GUN_H__
#define __GUN_H__

#include <iostream>
using std::cout;
using std::endl;
class Gun
{
private:
	int bullet;
public:
	Gun(int num)
		:bullet(num)
	{ /* Empty constructor */ }
	Gun(const Gun& gun)
		:bullet(gun.bullet)
	{ /* Empty copy constructor */ }
	inline int GetBullet() const { return bullet; }
	void Shot()
	{
		cout << "BANG!" << endl;
		bullet--;
	}
	~Gun()
	{ /* Empty destructor */ }
};

#endif