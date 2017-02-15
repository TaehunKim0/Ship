#include "stdafx.h"
#include"Unit.h"
#include "ArrowTurret.h"

#include"Bullet.h"

ArrowTurret::ArrowTurret()
{
	turret = Sprite::Create("Resources/Unit/ArrowTurret.png");

	AddChild(turret);

	
}


ArrowTurret::~ArrowTurret()
{

}

void ArrowTurret::OnUpdate()
{
	if (GameTime::TotalFrame % 180 == 0)
	{
		Attack();
	}
}

void ArrowTurret::OnDraw()
{

}

void ArrowTurret::Move()
{
}

void ArrowTurret::Attack()
{
	auto bullet = new Bullet("Player");

	bullet->SetPosition(GetPosition() + (turret->GetSize() / 2) - (bullet->bullet->GetSize() / 2));

	bullet->direction = bulletDirection::right;

	BulletMgr::GetInstance()->RegisterBullet(bullet);
}
