#include "stdafx.h"
#include "Bullet.h"


Bullet::Bullet(string id) : speed(3.0f) , LifeTime(0)
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
	LifeTime++;

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

	//만약 총알이 발사된지 5초가 지나면 없어짐

	if (LifeTime == 300)
	{
		this->SetVisible(false);
	}


}

void Bullet::OnDraw()
{
}

float Bullet::GetSpeed()
{
	return speed;
}

