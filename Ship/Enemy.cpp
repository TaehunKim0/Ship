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
	//if (SceneMgr::GetInstance()->GetScene()->id == "land")
		enemy = Sprite::Create("Resources/Unit/Enemy.png");
	
	if (SceneMgr::GetInstance()->GetScene()->id == "sea")
		return;


	this->AddChild(enemy);
	this->AddChild(item);
	printf("New Enemy!");
}


Enemy::~Enemy()
{
	DropItem();
	
}

void Enemy::Attack()
{
	auto bullet = new Bullet("Enemy");
	bullet->SetPosition(GetPosition() + (enemy->GetSize() / 2) - (bullet->bullet->GetSize() / 2));

	bullet->direction = bulletDirection::left;

	BulletMgr::GetInstance()->RegisterBullet(bullet);
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

	//������� �̵��ϸ� ���� �Ѹ� ���.
	Move();
}

void Enemy::OnDraw()
{

}

void Enemy::DropItem()
{	
	item = new Item(this->position.x, this->position.y);
}