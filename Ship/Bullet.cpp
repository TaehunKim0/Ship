#include "stdafx.h"
#include "Bullet.h"


Bullet::Bullet(string id) : speed(3.0f)
{
	if (id == "Player")
		bullet = Sprite::Create("Resources/bullet/Arrow.png");
	
	if (id == "Friendly")
		bullet = Sprite::Create("Resources/bullet/UnitBullet.png");
	
	if (id == "Enemy")
		bullet = Sprite::Create("Resources/bullet/UnitBullet.png");



	bullet->parentObject = this;
	this->AddChild(bullet);

	direction = bulletDirection::right;

}


Bullet::~Bullet()
{
}

void Bullet::OnUpdate()
{
	switch (direction)
	{
	case bulletDirection::left:
		this->position.x -= speed;
		break;

	case bulletDirection::right:
		this->position.x += speed;
		break;

	default:
		printf("Default \n");
	}



}

void Bullet::OnDraw()
{
}

float Bullet::GetSpeed()
{
	return speed;
}

