#include "stdafx.h"
#include "Bullet.h"


Bullet::Bullet() : speed(3.0f)
{
	bullet = Sprite::Create("Resources/Bullet.png");
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

