#include "stdafx.h"
#include "Loading_scene.h"
#include"land_stage.h"
#include"sea_stage.h"

Loading_scene::Loading_scene()
{
	id = "Loading";

	loadingTurtle = Sprite::Create("Resources/turtle.png");
	loadingTurtle->SetPosition(0, 150);

	loadingBackground = Sprite::Create("Resources/Map/Background2.png");

	this->AddChild(loadingBackground);
	this->AddChild(loadingTurtle);

	cout << "Current Scene : " << id << endl;

	auto timer = new Timer([]()
	{
		SceneMgr::GetInstance()->SetScene(new land_stage("land"));
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
