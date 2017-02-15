#include "stdafx.h"
#include "Background.h"
#include"Sprite.h"
#include"Player.h"

Background::Background(string background)
{
	if (background == "land")
	{
		this->background = Sprite::Create("Resources/Map/land.png");
	};

	if (background == "sea") 
	{

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
