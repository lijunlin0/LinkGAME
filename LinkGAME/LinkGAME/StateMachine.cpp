#include"StateMachine.h"
#include"Map.h"
#include<vector>
StateMachine::StateMachine(Map* mp)
{
	m = mp;
};
//����״̬��ʾ
void StateMachine::Set_State(State state)//���ݴ���״̬������Ӧ�Ĳ���
{
	m_State = state;
	if (m_State == Idle)
	{
		reset();
	}
	else if (m_State == SelectOne)
	{
		On_SelectOne();
	}
	else if (m_State == SelectTwo)
	{
		On_SelectTwo();
	}
	else
	{
		OnAnimation();
	}

};
//�õ���ǰ״̬
State StateMachine::Get_State() 
{
	return m_State;
};
//����ѡ�еĵ�һ��ͼƬ
void StateMachine::On_SelectOne()
{
	m->highlight(m->get_p1(),true);
};
//����ѡ�еĵڶ���ͼƬ
void StateMachine::On_SelectTwo()
{
	m->highlight(m->get_p2(),true);
	std::vector<Position> v;
	if (m->link(m->get_p1(), m->get_p2(), v))
	{
		m->eliminate(m->get_p1());
		m->eliminate(m->get_p2());
		Set_State(State::Animation);
	}
	else
	{
		reset();
		Set_State(State::Idle);
	}
	
};
//��ո����е�ͼƬ
void StateMachine::reset()
{
	m->highlight(m->get_p1(),false);
	m->highlight(m->get_p2(),false);
};
//��������
void StateMachine::OnAnimation()
{
	reset();
	Set_State(State::Idle);
};
//����
void StateMachine::Update() {};