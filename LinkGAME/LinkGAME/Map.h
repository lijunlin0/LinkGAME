#pragma once
#include<map>
#include"Position.h"
#include"Sprite.h"
//地图数据(一个逻辑位置对应一张图片)
class Map
{
private:
	std::map<Position, Sprite> data;
	Position p1;
	Position p2;

public:
	static const int HEIGHT = 6;//地图高度
	static const int WIDTH = 6;//地图宽度
	Map();
	//画出地图
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

