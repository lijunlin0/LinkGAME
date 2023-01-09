#include"Position.h"
#include"Map.h"

//ÏñËØ×ø±ê×ªÂß¼­×ø±ê
void Position::from_plotting(int coordinatesX, int coordinatesY)
{
	int factor = LOGIC_TO_PIXEL_FACTOR;
	x = coordinatesX/ factor;
	y = coordinatesY/ factor;
}
//Âß¼­×ø±ê×ªÏñËØ×ø±ê
void Position::to_plotting(int& coordinatesX, int& coordinatesY,int offset)
{
	int factor = LOGIC_TO_PIXEL_FACTOR;
	coordinatesX = x* factor+offset;
	coordinatesY = y* factor+offset;
}
