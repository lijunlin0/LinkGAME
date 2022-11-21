#include"Sprite.h"
#include"Map.h"

Sprite::Sprite(Position position, int value) :m_position(position.get_x(), position.get_y())
{
	m_value = value;
	m_valid = true;
	loadimage(&image, image_name(m_value));
	m_select = false;
			int x = m_position.x;
		int y = m_position.y;
		m_position.to_plotting(x, y);
		putimage(x, y, &image);
}
//判断是否被消除
bool Sprite::is_valid()
{
	return m_valid;
};
//设置消除状态
void Sprite::set_valid(bool valid)
{
	m_valid = valid;
}
void Sprite::draw()
{
	if (!is_valid())
	{
		return;
	}
}

//图片文件名
LPCTSTR Sprite::image_name(int value)
{
	switch (value)
	{
	case 1:return ".//images//apple.png";
	case 2:return ".//images//grape.png";
	case 3:return ".//images//mango.png";
	case 4:return ".//images//persimmon.png";
	case 5:return ".//images//pineapple.png";
	case 6:return ".//images//banana.png";
	default:return 0;
	}
}
//设置是否被选择
void Sprite::set_select(bool s)
{
	m_select = s;
	
	int x = m_position.x;
	int y = m_position.y;
	m_position.to_plotting(x, y);
	if (m_select)
	{
		rectangle(x, y, x + 64, y + 64);
	}
	else
	{
		clearrectangle(x, y, x + 64, y + 64);
		putimage(x, y, &image);
	}
}


