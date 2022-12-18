#include"StateMachine.h"
#include"Map.h"
#include<vector>
#include <chrono>
#include <thread>

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
	auto draw_line = [&](std::vector<Position> v)
	{
		for (int i = 0; i < v.size() - 1; i++)
		{
			int x1 = 0;
			int y1 = 0;
			int x2 = 0;
			int y2 = 0;
			v[i].to_plotting(x1, y1, Position::LOGIC_TO_PIXEL_FACTOR / 2);
			v[i + 1].to_plotting(x2, y2, Position::LOGIC_TO_PIXEL_FACTOR / 2);
			line(x1, y1, x2, y2);
		}
	};
	m->highlight(m->get_p2(),true);
	std::vector<Position> v;
	if (m->link(m->get_p1(), m->get_p2(), v))
	{
		m->eliminate(m->get_p1());
		m->eliminate(m->get_p2());
        Set_State(State::Idle);
		setlinestyle(PS_SOLID, 4);
		setlinecolor(WHITE);
		draw_line(v);

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		setlinecolor(BLACK);
		draw_line(v);
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