#ifndef __POINT_H__
#define __POINT_H__

struct Point
{
	int xpos;
	int ypos;
	void MovePos(int, int);
	inline void AddPoint(const Point& pos)
	{
		xpos += pos.xpos;
		ypos += pos.ypos;
		return;
	}
	void ShowPosition();
};

#endif