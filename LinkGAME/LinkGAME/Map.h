#pragma once
#include<vector>
#include"Position.h"
#include"Sprite.h"
//地图数据(一个逻辑位置对应一张图片)
class Map
{
public:
	static const int HEIGHT = 8;//地图高度
	static const int WIDTH = 8;//地图宽度
private:
	Sprite data[HEIGHT][WIDTH];
	Position p1;
	Position p2;
	//0折连接
	bool link_0(Position p1, Position p2, std::vector<Position>& ps);
	//1折连接
	bool link_1(Position p1, Position p2, std::vector<Position>& ps);
	//2折连接
	bool link_2(Position p1, Position p2, std::vector<Position>& ps);

public:
	
	Map();
	//画出地图
	void update();
	//设置p1逻辑位置
	void set_p1(Position p);
	//设置p2逻辑位置
	void set_p2(Position p);
	Position get_p1()
	{
		return p1;
	}
	Position get_p2()
	{
		return p2;
	}
	//是否高亮图片
	void highlight(Position p,bool b);
	//入口函数
	void eliminate(Position p);
	bool link(Position p1, Position p2, std::vector<Position>& ps);
	const Sprite& get_sprite(Position p)
	{
		return data[p.y][p.x];
	}
};

