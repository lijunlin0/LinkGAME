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
	//获取x值
	int get_x()const;
	//获取y值
	int get_y()const;
	bool operator<(const Position& p)const;
	//是否被消除
	bool isvalid();


};