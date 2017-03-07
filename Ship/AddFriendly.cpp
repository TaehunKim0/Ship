#include "stdafx.h"
#include "AddFriendly.h"
#include"AddFriendly_Plus.h"

AddFriendly::AddFriendly()
{
	CanPlus = Sprite::Create("Resources/UI/CanPlus.png");
	CannotPlus = Sprite::Create("Resources/UI/CannotPlus.png");
	int xx =0, yy = 0;
	

	for (int i = 0; i < 4; i++)
	{
		plus[i] = new AddFriendly_Plus();
		AddChild(plus[i]);
		plus[i]->SetVisible(false);

		plus[i]->SetPosition(700-xx, 100+yy);
		yy += 150;
		xx += 70;
	}

	AddChild(CanPlus);
	AddChild(CannotPlus);
	
	CanPlus->SetPosition(1170, 630);
	CannotPlus->SetPosition(1170, 630);

	SetActivation(AddActivation::Cannot);
	SetUIState(UIState::Not);
}


AddFriendly::~AddFriendly()
{

}

void AddFriendly::OnUpdate()
{
	CheckState();

	if (GetUIState() == UIState::Hover)
		SetActivation(AddActivation::Can);

	if(GetActivation() == AddActivation::Can)
		if (InputMgr::GetInstance()->IsKeyDown(VK_LBUTTON))
		{
			for (int i = 0; i < 4; i++)
			{
				plus[i]->SetVisible(true);
			}
		}
	//버튼을 눌렀을 떄 모두 Visible을 킨다.


	for (int i = 0; i < 4; i++)
	{
		if (!plus[i]->visible)
			for (int i = 0; i < 4; i++)
				plus[i]->SetVisible(false);

	}//하나라도 Visible이 꺼지면 모두 visible을 끈다.


	switch (addActivation)
	{
	case AddActivation::Can:
		CannotPlus->SetVisible(false);
		CanPlus->SetVisible(true);
		break;

	case AddActivation::Cannot:
		CanPlus->SetVisible(false);
		CannotPlus->SetVisible(true);
		break;

	default:
		
		break;
	}
	
	if (CollisionMgr::GetInstance()->IsPointInRect(CanPlus))
	{
		printf("HOVER");
		SetUIState(UIState::Hover);
	}
		

	else
	{
		SetUIState(UIState::Not);
		SetActivation(AddActivation::Cannot);
	}

	//만약 유닛 소환이 활성화된 상태일 때 소환버튼을 누르면 플러스 버튼이 나오고 누르면 그 자리에 랜덤으로 유닛생성됨(신기전 , 아군사람)

}

void AddFriendly::OnDraw()
{

}

void AddFriendly::SetActivation(AddActivation::Enum activation)
{
	addActivation = activation;
}

AddActivation::Enum AddFriendly::GetActivation()
{
	return addActivation;
}

void AddFriendly::SetUIState(UIState::Enum state)
{
	uiState = state;
}

UIState::Enum AddFriendly::GetUIState()
{
	return uiState;
}

void AddFriendly::CheckState()
{
	
	
}
