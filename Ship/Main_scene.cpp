#include "stdafx.h"
#include "Main_scene.h"
#include"Intro_scene.h"
#include"land_stage.h"

Main_scene::Main_scene() : menuIndex(0)
{
	selectMenu = new AnimationSprite(1, 1);
	selectMenu->AddFrame(Sprite::Create("Resources/UI/menu.png"));
	selectMenu->AddFrame(Sprite::Create("Resources/UI/menu2.png"));
	selectMenu->SetCurrentFrane(0);
	selectMenu->SetAutoNext(false);
	selectMenu->SetPosition(200, 350);

	Main = Sprite::Create("Resources/Map/Main.png");
	this->AddChild(Main);
	this->AddChild(selectMenu);
}

Main_scene::~Main_scene()
{
	
}

void Main_scene::OnUpdate()
{
	menuIndex = min(max(menuIndex, 0), 1);

	if (InputMgr::GetInstance()->IsKeyDown(VK_DOWN))
		menuIndex++;


	if (InputMgr::GetInstance()->IsKeyDown(VK_UP))
	{
		menuIndex--;
	}

	switch (menuIndex)
	{
	case -1:
		selectMenu->SetCurrentFrane(0);
		break;

	case 0:
		selectMenu->SetCurrentFrane(0);
		break;

	case 1:
		selectMenu->SetCurrentFrane(1);
		break;

	case 2:
		selectMenu->SetCurrentFrane(1);
		break;
	}

	if (InputMgr::GetInstance()->IsKeyDown('P'))
		SceneMgr::GetInstance()->SetScene(new land_stage());


	if (InputMgr::GetInstance()->IsKeyDown(VK_RETURN))
	{
		switch (menuIndex)
		{
		case 0:
			SceneMgr::GetInstance()->SetScene(new Intro_scene());
			break;

		case 1:
			PostQuitMessage(0);
			break;
		}
	}
}

void Main_scene::OnDraw()
{
	
}
