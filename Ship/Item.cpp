#include "stdafx.h"
#include "Item.h"


Item::Item(float x , float y)
{
	
	srand(GetTickCount());
	
	//if (rand() % 2 == 0)
		//ü�� ȸ��	�̹��� 
	//if (rand() % 2 == 1)
		//���ھ� �� �̹���

	item->position.x = x;
	item->position.y = y;
}

Item::~Item()
{

}

void Item::OnUpdate()
{

}

void Item::OnDraw()
{

}
