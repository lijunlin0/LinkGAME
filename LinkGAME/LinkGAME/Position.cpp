#include"Position.h"
#include"Map.h"

Position::Position(int x, int y)
{
	this->x = x;
	this->y = y;
}
Position::Position()
{
	this->x = 0;
	this->y = 0;
}
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
int Position::get_x()const
{
	return x;
}
int Position::get_y()const
{
	return y;
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