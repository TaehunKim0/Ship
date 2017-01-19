#include "stdafx.h"
#include "Loading_scene.h"
#include"land_stage.h"
#include"sea_stage.h"

Loading_scene::Loading_scene(string load)
{
	loadingTurtle = Sprite::Create("Resources/turtle.png");

	loadingTurtle->SetPosition(50, 400);

	loadingBackground = Sprite::Create("Resources/Background2.png");

	this->AddChild(loadingBackground);
	this->AddChild(loadingTurtle);

	if (load == "intro")
	{
		auto timer = new Timer([]()
		{
			SceneMgr::GetInstance()->SetScene(new land_stage());
		}, 6000);


		timer->Run();
	}
	
	if (load == "stage")
	{
		auto timer = new Timer([]()
		{
			SceneMgr::GetInstance()->SetScene(new sea_stage());
		}, 6000);


		timer->Run();
	}
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
