#include "stdafx.h"
#include"Unit.h"
#include"Friendly.h"


Friendly::Friendly(string type)
{
	life = 2;
	attack = 1;
	speed = 1.0f;

	//맵에 따라 모습이 바뀜
	if (type == "")
	{

	}

	if (type == "")
	{

	}
}

Friendly::~Friendly()
{

}

void Friendly::Attack()
{
	
}

void Friendly::Move()
{
	this->position.x += speed;
}

void Friendly::OnUpdate()
{
	//일정시간마다
	Attack();

	//만약 어느정도 이동하면 멈춤
	Move();
	
}

void Friendly::OnDraw()
{

}
