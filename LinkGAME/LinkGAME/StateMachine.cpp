#include"StateMachine.h"
#include"Map.h"
StateMachine::StateMachine(Map* mp)
{
	m = mp;
};
//根据状态显示
void StateMachine::Set_State(State state)//根据传入状态进行相应的操作
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
//得到当前状态
State StateMachine::Get_State() 
{
	return m_State;
};
//高亮选中的第一张图片
void StateMachine::On_SelectOne()
{
	m->highlight(m->get_p1(),true);
};
//高亮选中的第二张图片
void StateMachine::On_SelectTwo()
{
	m->highlight(m->get_p2(),true);
	Set_State(State::Animation);
};
//清空高亮中的图片
void StateMachine::reset()
{
	m->highlight(m->get_p1(),false);
	m->highlight(m->get_p2(),false);
};
//画线任务
void StateMachine::OnAnimation()
{
	reset();
	Set_State(State::Idle);
};
//画线
void StateMachine::Update() {};