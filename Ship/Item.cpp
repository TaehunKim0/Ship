#include "stdafx.h"
#include "Item.h"


Item::Item(float x , float y)
{
	
	srand(GetTickCount());
	
	//if (rand() % 2 == 0)
		//체력 회복	이미지 
	//if (rand() % 2 == 1)
		//스코어 업 이미지

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
