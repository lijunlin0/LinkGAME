#include"Map.h"
#include<vector>
#include"Sprite.h"
#include<iostream>
#include<windows.h>
#include<Mmsystem.h>
#pragma comment(lib,"winmm.lib")


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
	
	if (data[p1.y][p1.x].get_value() != data[p2.y][p2.x].get_value())//如果选中的图片不同，直接退出
	{
		return false;
	}
	bool result = link_0(p1, p2, ps) || link_1(p1, p2, ps) || link_2(p1, p2, ps);
	if (result)
	{
		PlaySound(("C:/D/GitHub/LinkGAME/LinkGAME/LinkGAME/sound/boom.wav"), NULL, SND_FILENAME | SND_ASYNC);
		return result;
	}
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

//一折连接
bool Map::link_1(Position p1, Position p2, std::vector<Position>& ps)
{
	auto FX = [&](int start_x, int end_x, int y)
	{
		if (start_x > end_x)
		{
			int temp = start_x;
			start_x = end_x;
			end_x = temp;
		}
		for (int x = start_x + 1; x < end_x; x++)
		{
			if (data[y][x].is_valid())
			{
				return false;
			}
		}
		return true;
	};

	auto FY = [&](int start_y, int end_y, int x)
	{
		if (start_y > end_y)
		{
			int temp = start_y;
			start_y = end_y;
			end_y = temp;
		}
		for (int y = start_y + 1; y < end_y; y++)
		{
			if (data[y][x].is_valid())
			{
				return false;
			}
		}
		return true;
	};

	Position L = p1.x < p2.x ? p1 : p2;
	Position R = p1.x < p2.x ? p2 : p1;
	Position C1;
	C1.x = L.x;
	C1.y = R.y;
	Position C2;
	C2.x = R.x;
	C2.x = L.y;

	//L -> C1 -> R;
	if (FX(C1.x,R.x,C1.y) && FY(C1.y,L.y,C1.x) && !data[C1.y][C1.x].is_valid())
	{
		ps.push_back(L);
		ps.push_back(C1);
		ps.push_back(R);
		return true;
	}
	//L -> C2 -> R;
	if (FX(C2.x, L.x, C2.y) && FY(C2.y, R.y, C2.x) && !data[C2.y][C2.x].is_valid())
	{
		ps.push_back(L);
		ps.push_back(C2);
		ps.push_back(R);
		return true;
	}
	return false;
}

//2折连接
bool Map::link_2(Position p1, Position p2, std::vector<Position>& ps)
{


	return false;
}