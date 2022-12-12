#include"Position.h"
#include"Map.h"

//��������ת�߼�����
void Position::from_plotting(int coordinatesX, int coordinatesY)
{
	int factor = LOGIC_TO_PIXEL_FACTOR;
	x = coordinatesX/ factor;
	y = coordinatesY/ factor;
}
//�߼�����ת��������
void Position::to_plotting(int& coordinatesX, int& coordinatesY,int offset)
{
	int factor = LOGIC_TO_PIXEL_FACTOR;
	coordinatesX = x* factor+offset;
	coordinatesY = y* factor+offset;
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