#pragma once

//�߼�����
class Position
{
public:
	int x;
	int y;
	static const int LOGIC_TO_PIXEL_FACTOR = 64;
	Position() { x = 0; y = 0; }
	//��������ת�߼�����
	void from_plotting(int coordinatesX, int coordinatesY);
	//�߼�����ת��������
	void to_plotting(int& coordinatesX, int& coordinatesY,int offset=0);
	//�Ƿ�����
	bool isvalid();
};