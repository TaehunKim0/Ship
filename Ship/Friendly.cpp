#include "stdafx.h"
#include"Friendly.h"
#include"Bullet.h"

Friendly::Friendly(string type)
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

Friendly::~Friendly()
{

}

void Friendly::Attack()
{
	bullet = new Bullet();

	bullet->direction = bulletDirection::right;

	bulletList.push_back(bullet);
}

void Friendly::Move()
{
	this->position.x += speed;
}

void Friendly::OnUpdate()
{
	//�����ð�����
	if (GameTime::CurrentFrame % 180 == 0)
	{
		Attack();
	}

	for (auto bullet : bulletList)
		bullet->Update();
	//���� ������� �̵��ϸ� ����
	Move();
	
}

void Friendly::OnDraw()
{
	for (auto bullet : bulletList)
		bullet->Draw();
}
