#pragma once

//Âß¼­×ø±ê
class Position
{
public:
	int x;
	int y;
	static const int LOGIC_TO_PIXEL_FACTOR = 64;
	Position() { x = 0; y = 0; }
	//ÏñËØ×ø±ê×ªÂß¼­×ø±ê
	void from_plotting(int coordinatesX, int coordinatesY);
	//Âß¼­×ø±ê×ªÏñËØ×ø±ê
	void to_plotting(int& coordinatesX, int& coordinatesY,int offset=0);
};