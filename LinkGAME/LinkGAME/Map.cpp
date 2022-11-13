#include"Map.h"
#include<vector>
#include"Sprite.h"

Map::Map()
{
	std::vector<int> L;
	for (int i = Sprite::VAL_MIN; i <= Sprite::VAL_MAX; i++)
	{
		for (int j = 0; j < 6; j++)
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
//»­³öµØÍ¼
void Map::update()
{
	std::map<Position, Sprite>::iterator i;
	for (i = data.begin(); i != data.end(); i++)
	{
		i->second.draw();
	}
}

void Map::Select(Position p)
{
	data.find(p);
	for (std::map<Position, Sprite>::iterator i = data.begin(); i != data.end(); i++)
	{
		if (i->first.get_x() == p.get_x() && i->first.get_y() == p.get_y())
		{
			bool n = i->second.is_select();
			i->second.set_select(!n);
		}
	}
}