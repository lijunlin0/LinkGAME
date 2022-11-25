#pragma once
#include<map>
#include"Position.h"
#include"Sprite.h"
//��ͼ����(һ���߼�λ�ö�Ӧһ��ͼƬ)
class Map
{
public:
	static const int HEIGHT = 6;//��ͼ�߶�
	static const int WIDTH = 6;//��ͼ���
private:
	Sprite data[HEIGHT][WIDTH];
	Position p1;
	Position p2;
	//0������
	bool z_connection(Position p1, Position p2);
	//1������
	bool o_connection(Position p1, Position p2);
	//2������
	bool t_connection(Position p1, Position p2);

public:
	
	Map();
	//������ͼ
	void update();
	//����p1�߼�λ��
	void set_p1(Position p);
	//����p2�߼�λ��
	void set_p2(Position p);
	Position get_p1()
	{
		return p1;
	}
	Position get_p2()
	{
		return p2;
	}
	//�Ƿ����ͼƬ
	void highlight(Position p,bool b);
	//��ں���
	bool eliminate(Position p1, Position p2);


};

