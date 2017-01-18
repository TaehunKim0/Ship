#include "stdafx.h"
#include "land_stage.h"
#include"Sprite.h"
#include"Player.h"
land_stage::land_stage()
{
	land = Sprite::Create("Resources/Background.png");
	player = PlayerMgr::GetInstance()->GetPlayer();
	
	land->SetPosition(0, 0);
	this->AddChild(land);
	this->AddChild(player);
	player->state = PlayerState::move;

}

land_stage::~land_stage()
{
}

void land_stage::OnUpdate()
{

	//���� ĳ���Ͱ� ��� �ְ� ������ ������ �������� ���� �����δ�. �ڵ尡 ���� �̻��ϴ�.
	if (player->state == PlayerState::middleStand)
	{
		if (player->direction == PlayerDirection::left)
		{
			land->position.x += 3.0f;
		}
		
		if (player->direction == PlayerDirection::right)
		{
			land->position.x -= 3.0f;
		}
			

	}

	//������� �̵�
	if (player->GetPositionX() == 550 / 2)
	{
		player->state = PlayerState::middleStand;
	}

	//�� ���ʿ� ���� �� ĳ���� ���� �̵� ����
	if (land->GetPositionX() > 0)
	{
		player->state = PlayerState::move;
		land->position.x = 0;
	}
	//�� �����ʿ� ���� �� ĳ���� ���� �̵� ����
	if (land->GetPositionX() < -720)
	{
		player->state = PlayerState::move;
		land->position.x = -720;
	}
}


void land_stage::OnDraw()
{
}
