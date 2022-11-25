#include"Map.h"
#include<vector>
#include"Sprite.h"
#include<iostream>

Map::Map()
{
	std::vector<int> L;
	for (int i = Sprite::VAL_MIN; i <= Sprite::VAL_MAX; i++)//放6个1~6的数字到vector数组
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			L.push_back(i);
		}
	}
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			int index = rand() % L.size();
			Position p;
			p.x = i;
			p.y = j;
			data[i][j].init(p, L[index]);
			L[index] = L[L.size() - 1];
			L.pop_back();
		}
	}
}
//画出地图
void Map::update()
{
	for (int i=0;i<HEIGHT;i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			data[i][j].draw();
		}
	}

	//for (i = data.begin(); i != data.end(); i++)
	//{
	//	i->second.draw();
	//}
}


void Map::set_p1(Position p)
{
	p1.x = p.x;
	p1.y = p.y;
}

void Map::set_p2(Position p)
{
	p2.x = p.x;
	p2.y = p.y;
};

void Map::highlight(Position p,bool b)
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (i == p.x && j == p.y)
			{
				data[i][j].set_select(b);
			}
		}
	}

	/*for (std::map<Position, Sprite>::iterator i = data.begin(); i != data.end(); i++)
	{
		if (i->first.x == p.x && i->first.y == p.y)
		{
			i->second.set_select(b);
		}
	}*/
};

//入口函数
bool Map::eliminate(Position p1, Position p2)
{
	Sprite& s1 = data[p1.y][p1.x];
	Sprite& s2 = data[p2.y][p2.x];
	if (s1.get_value() == s2.get_value())
	{
		std::cout << "iawheifhiaoheoifhaw";
		s1.set_valid(false);
		s2.set_valid(false);
	}
	return true;
}