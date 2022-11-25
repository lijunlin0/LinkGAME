#pragma once
#include"Position.h"
#include<graphics.h>
//图片绘制
class Sprite
{
private:
	//图片
	IMAGE image;
	//图片的值
	int m_value;
	//图片的逻辑值
	Position m_position;
	//图片是否被消除
	bool m_valid;
	//图片选中状态
	bool m_select;
public:
	void init(Position position, int value);
	//判断是否被消除
	bool is_valid();

	//自定消除状态
	void set_valid(bool valid);

	void draw();

	LPCTSTR image_name(int value);
	static const int VAL_MIN = 1;//图片最小值
	static const int VAL_MAX = 6;//图片最大值

	//设置是否被选择
	void set_select(bool s);

	//图片是否被选择
	bool is_select()
	{
		return m_select;
	};
	int get_value()
	{
		return m_value;
	}

	void update_image();
    
};
