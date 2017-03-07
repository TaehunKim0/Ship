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
	//��ư�� ������ �� ��� Visible�� Ų��.


	for (int i = 0; i < 4; i++)
	{
		if (!plus[i]->visible)
			for (int i = 0; i < 4; i++)
				plus[i]->SetVisible(false);

	}//�ϳ��� Visible�� ������ ��� visible�� ����.


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

	//���� ���� ��ȯ�� Ȱ��ȭ�� ������ �� ��ȯ��ư�� ������ �÷��� ��ư�� ������ ������ �� �ڸ��� �������� ���ֻ�����(�ű��� , �Ʊ����)

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
