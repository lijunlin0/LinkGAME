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
	//��ȡxֵ
	int get_x()const;
	//��ȡyֵ
	int get_y()const;
	bool operator<(const Position& p)const;
	//�Ƿ�����
	bool isvalid();


};