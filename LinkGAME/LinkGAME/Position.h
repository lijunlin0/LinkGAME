#pragma once

//�߼�����
class Position
{
public:
	int x;
	int y;
	//��������ת�߼�����
	void from_plotting(int coordinatesX, int coordinatesY);
	//�߼�����ת��������
	void to_plotting(int& coordinatesX, int& coordinatesY);
	bool operator<(const Position& p)const;
	//�Ƿ�����
	bool isvalid();


};