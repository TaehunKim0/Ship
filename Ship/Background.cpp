#include "stdafx.h"
#include "Background.h"
#include"Sprite.h"
#include"Player.h"

Background::Background()
{
	if (SceneMgr::GetInstance()->GetScene()->id == "land")
	{
		this->background = Sprite::Create("Resources/Map/land.png");
	};

	if (SceneMgr::GetInstance()->GetScene()->id == "sea")
	{
		this->background = Sprite::Create("Resources/Map/sea.png");
	};

	this->background->parentObject = this;
	this->AddChild(this->background);
}      

Background::~Background()
{

}

void Background::OnUpdate()
{
}

void Background::OnDraw()
{
	//printf("DRAW \n");
}
