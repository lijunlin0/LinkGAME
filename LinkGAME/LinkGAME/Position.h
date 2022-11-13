#pragma once

//Âß¼­×ø±ê
class Position
{
public:
	int x;
	int y;
	Position(int x, int y);
	Position();
	//ÏñËØ×ø±ê×ªÂß¼­×ø±ê
	void from_plotting(int coordinatesX, int coordinatesY);
	//Âß¼­×ø±ê×ªÏñËØ×ø±ê
	void to_plotting(int& coordinatesX, int& coordinatesY);
	int get_x()const;
	int get_y()const;
	bool operator<(const Position& p)const;
	bool isvalid();


};