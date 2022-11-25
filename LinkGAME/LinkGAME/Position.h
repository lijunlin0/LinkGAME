#pragma once

//逻辑坐标
class Position
{
public:
	int x;
	int y;
	//像素坐标转逻辑坐标
	void from_plotting(int coordinatesX, int coordinatesY);
	//逻辑坐标转像素坐标
	void to_plotting(int& coordinatesX, int& coordinatesY);
	bool operator<(const Position& p)const;
	//是否被消除
	bool isvalid();


};