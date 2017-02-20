#include "stdafx.h"
#include "Background.h"
#include"Sprite.h"
#include"Player.h"
//dmlwhstjd
Background::Background()
{
	/*if (id == "land")
	{
		this->background = Sprite::Create("Resources/Map/land.png");
	};

	if (id == "sea")
	{
		this->background = Sprite::Create("Resources/Map/sea.png");
	};

	this->background->parentObject = this;
	this->AddChild(this->background);	*/
}

Background::~Background()
{

}

void Background::OnUpdate()
{
	for (auto back : backgroundList)
		back->Update();
}

void Background::OnDraw()
{
	for (auto back : backgroundList)
		back->Draw();
	//printf("DRAW \n");
}

void Background::SetBackGround(Sprite * sprite)
{
	backgroundList.push_back(sprite);
}
