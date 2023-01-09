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
