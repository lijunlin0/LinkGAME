#include"StateMachine.h"
StateMachine::StateMachine() {};
//����״̬��ʾ
void StateMachine::Set_State(State state)
{
	m_State = state;
	if (m_State == Idle)
	{
		relight();
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
void StateMachine::On_SelectOne() {};
//����ѡ�еĵڶ���ͼƬ
void StateMachine::On_SelectTwo() {};
//��ո����е�ͼƬ
void StateMachine::relight() {};
//��������
void StateMachine::OnAnimation() {};
//����
void StateMachine::Update() {};