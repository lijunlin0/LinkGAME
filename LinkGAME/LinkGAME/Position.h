#pragma once

//逻辑坐标
class Position
{
public:
	int x;
	int y;
	Position(int x, int y);
	Position();
	//像素坐标转逻辑坐标
	void from_plotting(int coordinatesX, int coordinatesY);
	//逻辑坐标转像素坐标
	void to_plotting(int& coordinatesX, int& coordinatesY);
	int get_x();
	int get_y();
	bool operator<(const Position& p)const;

};