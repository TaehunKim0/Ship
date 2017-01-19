#include "stdafx.h"
#include "Background.h"
#include"Sprite.h"
#include"Player.h"

Background::Background(string background)
{
	if (background == "land")
	{
		this->background = Sprite::Create("Resources/land.png");
	};

	if (background == "sea") 
	{

	};

	this->background->parentObject = this;
	player = PlayerMgr::GetInstance()->GetPlayer();

	player->state = PlayerState::move;

	this->AddChild(this->background);
}

Background::~Background()
{

}

void Background::OnUpdate()
{
	//���� ĳ���Ͱ� ��� �ְ� ������ ������ �������� ���� �����δ�.
	if (player->state == PlayerState::middleStand)
	{
		if (player->direction == PlayerDirection::left)
		{
			background->position.x += 3.0f;
		}

		if (player->direction == PlayerDirection::right)
		{
			background->position.x -= 3.0f;
		}
	}


	//������� �̵�
	if (player->GetPositionX() == 550 / 2)
	{
		player->state = PlayerState::middleStand;
	}

	//�� ���ʿ� ���� �� ĳ���� ���� �̵� ����
	if (background->GetPositionX() > 0)
	{
		player->state = PlayerState::move;
		background->position.x = 0;
	}
	//�� �����ʿ� ���� �� ĳ���� ���� �̵� ����
	if (background->GetPositionX() < -720)
	{
		player->state = PlayerState::move;
		background->position.x = -720;
	}
}

void Background::OnDraw()
{
	printf("DRAW \n");
}
