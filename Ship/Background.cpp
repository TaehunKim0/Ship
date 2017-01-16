#include "stdafx.h"
#include "Background.h"
#include"Sprite.h"

Background::Background()
{
}


Background::~Background()
{

}

void Background::AddBackground(Sprite * background)
{
	BackgroundList.push_back(background);
}

void Background::RemoveBackground()
{
	BackgroundList.clear();
}

void Background::OnUpdate()
{
	for (auto back : BackgroundList)
	{
		back->Update();
	}
}

void Background::OnDraw()
{
	for (auto back : BackgroundList)
	{
		back->Draw();
	}
}
