#pragma once
#include<map>
#include"Position.h"
#include"Sprite.h"
//��ͼ����(һ���߼�λ�ö�Ӧһ��ͼƬ)
class Map
{
private:
	std::map<Position, Sprite> data;
	Position p1;
	Position p2;

public:
	static const int HEIGHT = 6;//��ͼ�߶�
	static const int WIDTH = 6;//��ͼ���
	Map();
	//������ͼ
	void update();
	void set_p1(Position p);
	void set_p2(Position p);
	Position get_p1()
	{
		return p1;
	}
	Position get_p2()
	{
		return p2;
	}
	void highlight(Position p,bool b);

};

