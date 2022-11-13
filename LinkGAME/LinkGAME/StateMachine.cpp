#include"StateMachine.h"
StateMachine::StateMachine() {};
//根据状态显示
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
//得到当前状态
State StateMachine::Get_State() 
{
	return m_State;
};
//高亮选中的第一张图片
void StateMachine::On_SelectOne() {};
//高亮选中的第二张图片
void StateMachine::On_SelectTwo() {};
//清空高亮中的图片
void StateMachine::relight() {};
//画线任务
void StateMachine::OnAnimation() {};
//画线
void StateMachine::Update() {};