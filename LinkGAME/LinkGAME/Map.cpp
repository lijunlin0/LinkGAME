#include"Map.h"
#include<vector>
#include"Sprite.h"

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
			Position p(i, j);
			int index = rand() % L.size();
			Sprite s(p,L[index]);
			L[index] = L[L.size() - 1];
			L.pop_back();
			data.insert(std::pair<Position, Sprite>(p, s));
		}
	}
}
//画出地图
void Map::update()
{
	std::map<Position, Sprite>::iterator i;
	for (i = data.begin(); i != data.end(); i++)
	{
		i->second.draw();
	}
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
	for (std::map<Position, Sprite>::iterator i = data.begin(); i != data.end(); i++)
	{
		if (i->first.get_x() == p.get_x() && i->first.get_y() == p.get_y())
		{
			i->second.set_select(b);
		}
	}
};