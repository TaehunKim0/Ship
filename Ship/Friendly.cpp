#include "stdafx.h"
#include"Friendly.h"
#include"Bullet.h"

Friendly::Friendly(string type)
{
	life = 2;
	attack = 1;
	speed = 1.0f;

	//맵에 따라 모습이 바뀜
	if (SceneMgr::GetInstance()->GetScene()->id == "land")
		friedly = Sprite::Create("Resources/Unit/friendly.png");
	
	if (SceneMgr::GetInstance()->GetScene()->id == "sea")
		return;

	this->AddChild(friedly);
}

Friendly::~Friendly()
{

}

void Friendly::Attack()
{
	auto bullet = new Bullet("Friendly");

	bullet->SetPosition(GetPosition() + (friedly->GetSize() / 2) - (bullet->bullet->GetSize() / 2));

	bullet->direction = bulletDirection::right;

	BulletMgr::GetInstance()->RegisterBullet(bullet);
}

void Friendly::Move()
{
	this->position.x += speed;
}

void Friendly::OnUpdate()
{
	//일정시간마다
	if (GameTime::TotalFrame % 180 == 0)
	{
		Attack();
	}

	//만약 어느정도 이동하면 멈춤
	//Move();
	
}

void Friendly::OnDraw()
{

}