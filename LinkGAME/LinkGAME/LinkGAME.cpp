#include<iostream>
#include<graphics.h>
#include<map>
#include"Map.h"
#include"Position.h"
#include"Sprite.h"
using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	initgraph(512,512);
	Map m;
	ExMessage msg;
	setlinestyle(PS_SOLID, 3);
	while (true)
	{
		cout << "123";
		msg = getmessage(EX_MOUSE);
		if (msg.message == WM_LBUTTONDOWN)
		{
			int x = msg.x;
			int y = msg.y;
			cout << x << "," << y << endl;
			Position p(0, 0);
			p.from_plotting(x, y);
			if (p.isvalid())
			{
				m.Select(p);
			}
		}
		cleardevice();
		m.update();
	}
	getchar();
	closegraph();
	return 0;
}