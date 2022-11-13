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
public:
	Sprite(Position position, int value);
	//判断是否被消除
	bool is_valid();
	//自定消除状态
	void set_valid(bool valid);
	void draw();
	LPCTSTR image_name(int value);
	static const int VAL_MIN = 1;
	static const int VAL_MAX = 6;
};
