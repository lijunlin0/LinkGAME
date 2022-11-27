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
			p.x = j;
			p.y = i;
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
			if (j == p.x && i == p.y)
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
void Map::eliminate(Position p)
{
	data[p.y][p.x].set_valid(false);
}

bool Map::link(Position p1, Position p2, std::vector<Position>& ps)
{
	if (data[p1.y][p1.x].get_value() != data[p2.y][p2.x].get_value())
	{
		return false;
	}
	return link_0(p1, p2, ps) || link_1(p1, p2, ps) || link_2(p1, p2, ps);
}
//0折连接
bool Map::link_0(Position p1, Position p2, std::vector<Position>& ps)
{
	if (p1.x == p2.x)
	{
		int miny = (p1.y < p2.y ? p1.y : p2.y)+1;
		int maxy = (p1.y < p2.y ? p2.y : p1.y)-1;
		for (int y = miny; y <= maxy; y++)
		{
			if (data[y][p1.x].is_valid())
			{
				return false;
			}
		}
		ps.push_back(p1);
		ps.push_back(p2);
		return true;
	}
	else if (p1.y==p2.y)
	{
		int minx = (p1.x < p2.x ? p1.x : p2.x) + 1;
		int maxx = (p1.x < p2.x ? p2.x : p1.x) - 1;
		for (int x = minx; x <= maxx; x++)
		{
			if (data[p1.y][x].is_valid())
			{
				return false;
			}
		}
		ps.push_back(p1);
		ps.push_back(p2);
		return true;
	}
	else
	{
		return false;
	}

}

//1折连接
bool Map::link_1(Position p1, Position p2, std::vector<Position>& ps)
{
	return false;
}
//2折连接
bool Map::link_2(Position p1, Position p2, std::vector<Position>& ps)
{
	return false;
}