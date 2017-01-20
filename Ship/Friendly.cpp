#include "stdafx.h"
#include"Friendly.h"
#include"Bullet.h"

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
	bullet = new Bullet();

	bullet->direction = bulletDirection::right;

	bulletList.push_back(bullet);
}

void Friendly::Move()
{
	this->position.x += speed;
}

void Friendly::OnUpdate()
{
	//일정시간마다
	if (GameTime::CurrentFrame % 180 == 0)
	{
		Attack();
	}

	for (auto bullet : bulletList)
		bullet->Update();
	//만약 어느정도 이동하면 멈춤
	Move();
	
}

void Friendly::OnDraw()
{
	for (auto bullet : bulletList)
		bullet->Draw();
}
