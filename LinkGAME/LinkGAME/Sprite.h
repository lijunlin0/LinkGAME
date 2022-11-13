#pragma once
#include"Position.h"
#include<graphics.h>
//ͼƬ����
class Sprite
{
private:
	//ͼƬ
	IMAGE image;
	//ͼƬ��ֵ
	int m_value;
	//ͼƬ���߼�ֵ
	Position m_position;
	//ͼƬ�Ƿ�����
	bool m_valid;
	bool m_select;
public:
	Sprite(Position position, int value);
	//�ж��Ƿ�����
	bool is_valid();
	//�Զ�����״̬
	void set_valid(bool valid);
	void draw();
	LPCTSTR image_name(int value);
	static const int VAL_MIN = 1;
	static const int VAL_MAX = 6;
	void set_select(bool s);
	bool is_select()
	{
		return m_select;
	};
};
