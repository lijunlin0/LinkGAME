#pragma once
#include"Map.h"
//状态
//状态变化：
//默认为Idle状态
//玩家选择一张图片进入SelecOne状态
//玩家选择两张图片进入SelectTwo状态
//   如果能够消除：播放消除动画，结束后进入Idle状态
//   如果不能消除：进入Idle状态
enum State
{
	//待机
	Idle = 0,
	//选择了一张图片
	SelectOne = 1,
	//选择了两张图片
	SelectTwo = 2,
};

class StateMachine
{
private:
	//当前状态
	State m_State;
	//地图指针
	Map* m;
public:
	StateMachine(Map* m);

	//设置状态
	void Set_State(State state);

	//得到当前状态
	State Get_State();

	//高亮选中的第一张图片
	void On_SelectOne();

	//高亮选中的第二张图片
	void On_SelectTwo();

	//清空高亮中的图片
	void reset();
};