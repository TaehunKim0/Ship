#include "stdafx.h"
#include"Enemy.h"
#include"Bullet.h"
#include"Item.h"

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

	this->AddChild(item);

}


Enemy::~Enemy()
{
	DropItem();
	
}

void Enemy::Attack()
{
	bullet = new Bullet();

	bullet->direction = bulletDirection::left;

	bulletList.push_back(bullet);
}

void Enemy::Move()
{
	this->position.x -= speed;
}

void Enemy::OnUpdate()
{
	//���� �ð�����
	if (GameTime::CurrentFrame % 180 == 0)
	{
		Attack();
	}
	
	for (auto bullet : bulletList)
		bullet->Update();



	//������� �̵��ϸ� ���� �Ѹ� ���.
	Move();
}

void Enemy::OnDraw()
{
	for (auto bullet : bulletList)
		bullet->Draw();
}

void Enemy::DropItem()
{	
	item = new Item(this->position.x, this->position.y);
}

