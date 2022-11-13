#pragma once
#include<map>
#include"Position.h"
#include"Sprite.h"
//地图数据
class Map
{
private:
	std::map<Position, Sprite> data;

public:
	static const int HEIGHT = 6;
	static const int WIDTH = 6;
	Map();
	//画出地图
	void update();
	void Select(Position p);
};

