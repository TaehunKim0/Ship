#include "stdafx.h"
#include"Enemy.h"
#include"Bullet.h"
#include"Item.h"

Enemy::Enemy(string type)
{
	life = 2;
	attack = 1;
	speed = 1.0f;

	//¸Ê¿¡ µû¶ó ¸ð½À¿¡ ¹Ù²ñ
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
	//ÀÏÁ¤ ½Ã°£¸¶´Ù
	if (GameTime::CurrentFrame % 180 == 0)
	{
		Attack();
	}
	
	for (auto bullet : bulletList)
		bullet->Update();



	//¾î´ÀÁ¤µµ ÀÌµ¿ÇÏ¸é ¸ØÃã ÃÑ¸¸ ½ð´Ù.
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

