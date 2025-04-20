#include "Point.h"
int main(int argc, char** argv)
{
	Point pos1 = {12, 4};
	Point pos2 = {20, 30};
	pos1.MovePos(-7, 10);
	pos1.ShowPosition();
	pos1.AddPoint(pos2);
	pos1.ShowPosition();
	return 0;
}