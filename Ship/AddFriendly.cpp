#include "stdafx.h"
#include "AddFriendly.h"
#include"AddFriendly_Plus.h"

AddFriendly::AddFriendly()
{
	CanPlus = Sprite::Create("Resources/UI/CanPlus.png");
	CannotPlus = Sprite::Create("Resources/UI/CannotPlus.png");
	int p = 0;
	for (int i = 0; i < 3; i++)
	{
		plus[i] = new AddFriendly_Plus();
		AddChild(plus[i]);
		plus[i]->SetVisible(false);

		plus[i]->SetPosition(500, 500+p);
		p += 250;
	}

	AddChild(CanPlus);
	AddChild(CannotPlus);
	
	

	CanPlus->SetPosition(1080, 550);
	CannotPlus->SetPosition(1080, 550);


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
			printf("마우스 클릭 \n");
			for (int i = 0; i < 3; i++)
			{
				plus[i]->SetVisible(true);
			}
		}

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
	
	if(CollisionMgr::GetInstance()->IsPointInRect(CanPlus))
		SetUIState(UIState::Hover);

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
