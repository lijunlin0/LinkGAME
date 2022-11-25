#include"Position.h"
#include"Map.h"

//ÏñËØ×ø±ê×ªÂß¼­×ø±ê
void Position::from_plotting(int coordinatesX, int coordinatesY)
{
	x = (coordinatesX-64)/ 64;
	y = (coordinatesY-64)/64;
}
//Âß¼­×ø±ê×ªÏñËØ×ø±ê
void Position::to_plotting(int& coordinatesX, int& coordinatesY)
{
	coordinatesX = (x+1)*64;
	coordinatesY = (y+1)*64;
}
bool Position::operator<(const Position& p)const
{
	int value1 = x + y * Map::WIDTH;
	int value2 = p.x + p.y * Map::WIDTH;
	return value1 < value2;
}

bool Position::isvalid()
{
	if (x < 0 || x >= Map::WIDTH || y < 0 || y >= Map::HEIGHT)
	{
		return false;
	}
	return true;
}