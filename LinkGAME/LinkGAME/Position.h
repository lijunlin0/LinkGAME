#pragma once

//逻辑坐标
class Position
{
public:
	int x;
	int y;
	static const int LOGIC_TO_PIXEL_FACTOR = 64;
	Position() { x = 0; y = 0; }
	//像素坐标转逻辑坐标
	void from_plotting(int coordinatesX, int coordinatesY);
	//逻辑坐标转像素坐标
	void to_plotting(int& coordinatesX, int& coordinatesY,int offset=0);
	//是否被消除
	bool isvalid();
};