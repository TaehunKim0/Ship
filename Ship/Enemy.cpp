#include "stdafx.h"
#include"Unit.h"
#include"Enemy.h"

Enemy::Enemy(string type)
{
	life = 2;
	attack = 1;
	speed = 1.0f;

	//�ʿ� ���� ����� �ٲ�
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
	//���� �ð����� 
	Attack();

	//������� �̵��ϸ� ���� �Ѹ� ���.
	Move();
}

void Enemy::OnDraw()
{

}

