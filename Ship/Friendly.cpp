#include "stdafx.h"
#include"Friendly.h"
#include"Bullet.h"

Friendly::Friendly(string type)
{
	life = 2;
	attack = 1;
	speed = 1.0f;

	//�ʿ� ���� ����� �ٲ�
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
	//�����ð�����
	if (GameTime::TotalFrame % 180 == 0)
	{
		Attack();
	}

	//���� ������� �̵��ϸ� ����
	//Move();
	
}

void Friendly::OnDraw()
{

}