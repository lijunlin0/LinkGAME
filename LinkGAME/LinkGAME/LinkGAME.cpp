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
	m.update();
	getchar();
	closegraph();

	return 0;
}