#include "stdafx.h"
#include "AddFriendly_Plus.h"
#include"AddFriendly.h"
#include"UnitSpawner.h"
AddFriendly_Plus::AddFriendly_Plus()
{
	plus = Sprite::Create("Resources/UI/Plus.png");

	AddChild(plus);

	SetPlusState(PlusState::Not);
}

AddFriendly_Plus::~AddFriendly_Plus()
{

}

void AddFriendly_Plus::OnDraw()
{

}

void AddFriendly_Plus::OnUpdate()
{
	if (IsPlused)
		SetVisible(false);

	if (CollisionMgr::GetInstance()->IsPointInRect(plus))
	{
		SetPlusState(PlusState::Hover);
		printf("PLUS_HOVER \n");
	}
	
	if (GetPlusState() == PlusState::Hover)
		if (InputMgr::GetInstance()->IsKeyDown(VK_LBUTTON))
		{
			printf("Plus Pressed\n");
			SetVisible(false);
			UnitSpawner::GetInstance()->SpawnFriendly(position.x, position.y);
		}

}

void AddFriendly_Plus::SetIsPlused(bool plused)
{
	IsPlused = plused;
}

void AddFriendly_Plus::SetPlusState(PlusState::Enum state)
{
	plusState = state;
}

PlusState::Enum AddFriendly_Plus::GetPlusState()
{
	return plusState;
}