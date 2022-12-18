#pragma once
#include"Map.h"
//״̬
//״̬�仯��
//Ĭ��ΪIdle״̬
//���ѡ��һ��ͼƬ����SelecOne״̬
//���ѡ������ͼƬ����SelectTwo״̬
//   ����ܹ������������������������������Idle״̬
//   �����������������Idle״̬
enum State
{
	//����
	Idle = 0,
	//ѡ����һ��ͼƬ
	SelectOne = 1,
	//ѡ��������ͼƬ
	SelectTwo = 2,
};

class StateMachine
{
private:
	//��ǰ״̬
	State m_State;
	//��ͼָ��
	Map* m;
public:
	StateMachine(Map* m);

	//����״̬
	void Set_State(State state);

	//�õ���ǰ״̬
	State Get_State();

	//����ѡ�еĵ�һ��ͼƬ
	void On_SelectOne();

	//����ѡ�еĵڶ���ͼƬ
	void On_SelectTwo();

	//��ո����е�ͼƬ
	void reset();
};