#pragma once

//�߼�����
class Position
{
public:
	int x;
	int y;
	Position(int x, int y);
	Position();
	//��������ת�߼�����
	void from_plotting(int coordinatesX, int coordinatesY);
	//�߼�����ת��������
	void to_plotting(int& coordinatesX, int& coordinatesY);
	int get_x();
	int get_y();
	bool operator<(const Position& p)const;

};