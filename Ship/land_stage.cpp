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

	//만약 캐릭터가 가운데 있고 방향이 있으면 그쪽으로 맵이 움직인다. 코드가 조금 이상하다.
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

	//가운데에서 이동
	if (player->GetPositionX() == 550 / 2)
	{
		player->state = PlayerState::middleStand;
	}

	//맨 왼쪽에 왔을 때 캐릭터 자유 이동 가능
	if (land->GetPositionX() > 0)
	{
		player->state = PlayerState::move;
		land->position.x = 0;
	}
	//맨 오른쪽에 왔을 때 캐릭터 자유 이동 가능
	if (land->GetPositionX() < -720)
	{
		player->state = PlayerState::move;
		land->position.x = -720;
	}
}


void land_stage::OnDraw()
{
}
