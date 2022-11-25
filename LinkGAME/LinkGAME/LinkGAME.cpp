#include<iostream>
#include<graphics.h>
#include<map>
#include"Map.h"
#include"Position.h"
#include"Sprite.h"
#include"StateMachine.h"
using namespace std;

int main()
{
	srand((unsigned)time(NULL));//����ϵͳʱ��ı���������
	initgraph(512,512);//���ڴ�С��512*512
	Map m;
	StateMachine s(&m);//����״̬��
	ExMessage msg;//������Ϣ����
	setlinestyle(PS_SOLID, 1);//�����߿�
	while (true)
	{
		bool b = peekmessage(&msg, EX_MOUSE);
		if (b && msg.message == WM_LBUTTONDOWN)
		{
			int x = msg.x;
			int y = msg.y;
			Position p;
			 p.from_plotting(x, y);
			if (p.isvalid())
			{
				if (s.Get_State() == State::Idle)//���״̬ΪĬ��
				{
					m.set_p1(p);
					s.Set_State(State::SelectOne);
				}
				else if(s.Get_State()==State::SelectOne)//���״̬Ϊѡ����һ��ͼƬ
				{
					m.set_p2(p);
					s.Set_State(State::SelectTwo);
				}
				else if (s.Get_State() == State::SelectTwo)//���״̬Ϊѡ��������ͼƬ
				{
					s.Set_State(State::Animation);
				}
			}
		}
		m.update();
		Sleep(1);
	}
	getchar();
	closegraph();
	return 0;
}