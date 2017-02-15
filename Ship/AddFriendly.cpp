#include "stdafx.h"
#include "AddFriendly.h"


AddFriendly::AddFriendly()
{
	CanPlus = Sprite::Create("Resources/UI/CanPlus.png");
	CannotPlus = Sprite::Create("Resources/UI/CannotPlus.png");
	Plus = Sprite::Create("Resources/UI/Plus.png");


	AddChild(Plus);
	AddChild(CanPlus);
	AddChild(CannotPlus);
	
	SetActivation(AddActivation::Cannot);

	CanPlus->SetPosition(1080, 550);
	CannotPlus->SetPosition(1080, 550);

}


AddFriendly::~AddFriendly()
{

}

void AddFriendly::OnUpdate()
{
	if (GameTime::TotalFrame == 500)
	{
		SetActivation(AddActivation::Can);
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