#include "stdafx.h"
#include "CollisionMgr.h"


CollisionMgr::CollisionMgr()
{
}


CollisionMgr::~CollisionMgr()
{
}

bool CollisionMgr::IsPointInRect(Sprite * sprite)
{
	int xx = InputMgr::GetInstance()->GetMousePosition().x;
	int yy = InputMgr::GetInstance()->GetMousePosition().y;

	/*if ((CanPlus->position.x < xx && CanPlus->GetSourceRect().right <= xx)
	&& (CanPlus->position.y <= yy && CanPlus->GetSourceRect().bottom <= yy))
	{
	printf("Hover");
	SetUIState(UIState::Hover);
	}
	*///사각형 충돌

	float deltaX = sprite->position.x - xx;
	float deltaY = sprite->position.y - yy;

	float length = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	//printf("length : %f", length);

	if (length < sprite->GetSourceRect().right / 2)
	{
		return true;
	}

	return false;
}
