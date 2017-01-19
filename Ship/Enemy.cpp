#include "stdafx.h"
#include"Unit.h"
#include"Enemy.h"

Enemy::Enemy(string type)
{
	life = 2;
	attack = 1;
	speed = 1.0f;

	//맵에 따라 모습에 바뀜
	if (type == "")
	{

	}

	if (type == "")
	{

	}
}


Enemy::~Enemy()
{

}

void Enemy::Attack()
{

}

void Enemy::Move()
{
	this->position.x -= speed;
}

void Enemy::OnUpdate()
{
	//일정 시간마다 
	Attack();

	//어느정도 이동하면 멈춤 총만 쏜다.
	Move();
}

void Enemy::OnDraw()
{

}

