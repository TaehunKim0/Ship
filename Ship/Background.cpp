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
	//만약 캐릭터가 가운데 있고 방향이 있으면 그쪽으로 맵이 움직인다.
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


	//가운데에서 이동
	if (player->GetPositionX() == 550 / 2)
	{
		player->state = PlayerState::middleStand;
	}

	//맨 왼쪽에 왔을 때 캐릭터 자유 이동 가능
	if (background->GetPositionX() > 0)
	{
		player->state = PlayerState::move;
		background->position.x = 0;
	}
	//맨 오른쪽에 왔을 때 캐릭터 자유 이동 가능
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
