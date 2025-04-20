#ifndef __POLICE_H__
#define __POLICE_H__

#include "Gun.h"
class Police
{
private:
	int handcuffs;
	Gun* pistol;
public:
	Police(int bullet, int cuffs)
		:handcuffs(cuffs)
	{
		if(bullet > 0)
			pistol = new Gun(bullet);
		else
			pistol = nullptr;
	} // Constructor
	Police(const Police& pc)
		:handcuffs(pc.handcuffs)
	{
		if(pc.pistol)
		{
			int bullet = (pc.pistol)->GetBullet();
			pistol = new Gun(bullet);
		}
		else
			pistol = nullptr;
	} // Copy constructor
	Police& operator=(const Police& pc)
	{
		if(pistol)
			delete pistol;
		if(pc.pistol)
		{
			int bullet = (pc.pistol)->GetBullet();
			pistol = new Gun(bullet);
		}
		else
			pistol = nullptr;
		handcuffs = pc.handcuffs;
		return *this;
	}
	inline int GetHandcuff() const { return handcuffs; }
	void PutHandcuff()
	{
		cout << "SNAP!" << endl;
		handcuffs--;
	}
	void Shot()
	{
		if(!pistol)
			cout << "MISS!" << endl;
		else
			pistol->Shot();
		if(pistol && pistol->GetBullet() <= 0)
		{
			delete pistol;
			pistol = nullptr;
		}
	}
	~Police()
	{
		if(pistol)
			delete pistol;
	} // Destructor
};

#endif