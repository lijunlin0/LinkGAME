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
	//ͼƬѡ��״̬
	bool m_select;
public:
	void init(Position position, int value);
	//�ж��Ƿ�����
	bool is_valid();

	//�Զ�����״̬
	void set_valid(bool valid);

	void draw();

	LPCTSTR image_name(int value);
	static const int VAL_MIN = 1;//ͼƬ��Сֵ
	static const int VAL_MAX = 6;//ͼƬ���ֵ

	//�����Ƿ�ѡ��
	void set_select(bool s);

	//ͼƬ�Ƿ�ѡ��
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
