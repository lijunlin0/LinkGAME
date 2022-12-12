#pragma once
#include<vector>
#include"Position.h"
#include"Sprite.h"
//��ͼ����(һ���߼�λ�ö�Ӧһ��ͼƬ)
class Map
{
public:
	static const int HEIGHT = 8;//��ͼ�߶�
	static const int WIDTH = 8;//��ͼ���
private:
	Sprite data[HEIGHT][WIDTH];
	Position p1;
	Position p2;
	//0������
	bool link_0(Position p1, Position p2, std::vector<Position>& ps);
	//1������
	bool link_1(Position p1, Position p2, std::vector<Position>& ps);
	//2������
	bool link_2(Position p1, Position p2, std::vector<Position>& ps);

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
	void eliminate(Position p);
	bool link(Position p1, Position p2, std::vector<Position>& ps);
	const Sprite& get_sprite(Position p)
	{
		return data[p.y][p.x];
	}
};

