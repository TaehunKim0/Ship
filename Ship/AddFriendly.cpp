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
