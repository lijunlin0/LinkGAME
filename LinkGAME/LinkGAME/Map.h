#pragma once
#include<map>
#include"Position.h"
#include"Sprite.h"
//��ͼ����
class Map
{
private:
	std::map<Position, Sprite> data;

public:
	static const int HEIGHT = 6;
	static const int WIDTH = 6;
	Map();
	//������ͼ
	void update();
	void Select(Position p);
};

