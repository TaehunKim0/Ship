#include "stdafx.h"
#include"Unit.h"
#include"Friendly.h"


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
	
}

void Friendly::Move()
{
	this->position.x += speed;
}

void Friendly::OnUpdate()
{
	//�����ð�����
	Attack();

	//���� ������� �̵��ϸ� ����
	Move();
	
}

void Friendly::OnDraw()
{

}
