#include<iostream>
#include<graphics.h>
#include<map>
#include"Map.h"
#include"Position.h"
#include"Sprite.h"
#include"StateMachine.h"
#include <chrono>
#include <thread>

using namespace std;
int main()
{
	srand((unsigned)time(NULL));//根据系统时间改变的随机种子
	int screen_width = Position::LOGIC_TO_PIXEL_FACTOR * Map::WIDTH;
	int screen_height = Position::LOGIC_TO_PIXEL_FACTOR * Map::HEIGHT;
	initgraph(screen_width,screen_height);//设置窗口大小
	Map m;
	StateMachine s(&m);//创建状态机
	ExMessage msg;//创建消息变量
	while (true)
	{
		bool b = peekmessage(&msg, EX_MOUSE);
		if (b && msg.message == WM_LBUTTONDOWN)
		{
			int x = msg.x;
			int y = msg.y;
			Position p;
			 p.from_plotting(x, y);
			 if (m.get_sprite(p).is_valid())
			{
				if (s.Get_State() == State::Idle)//如果状态为默认
				{
					m.set_p1(p);
					s.Set_State(State::SelectOne);
				}
				else if(s.Get_State()==State::SelectOne)//如果状态为选择了一张图片
				{
					if (p.x == m.get_p1().x&&p.y==m.get_p1().y)
					{
						s.Set_State(State::Idle);
					}
					else
					{
						m.set_p2(p);
						s.Set_State(State::SelectTwo);
					}
				}
			}
			else
			{
				s.Set_State(State::Idle);
			}
		}
		this_thread::sleep_for(std::chrono::milliseconds(6));
	}
	closegraph();
	return 0;
}