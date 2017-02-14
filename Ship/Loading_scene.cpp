#include "stdafx.h"
#include "Loading_scene.h"
#include"land_stage.h"
#include"sea_stage.h"

Loading_scene::Loading_scene()
{
	loadingTurtle = Sprite::Create("Resources/turtle.png");

	loadingTurtle->SetPosition(50, 400);

	loadingBackground = Sprite::Create("Resources/Map/Background2.png");

	this->AddChild(loadingBackground);
	this->AddChild(loadingTurtle);

	
	auto timer = new Timer([]()
	{
		SceneMgr::GetInstance()->SetScene(new land_stage());
	}, 6000);

	timer->Run();
}

Loading_scene::~Loading_scene()
{

}

void Loading_scene::OnUpdate()
{
	loadingTurtle->position.x += 1.0f;

}

void Loading_scene::OnDraw()
{

}
