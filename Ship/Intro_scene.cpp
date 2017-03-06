#include "stdafx.h"
#include "Intro_scene.h"
#include"Loading_scene.h"

Intro_scene::Intro_scene()
{
	id = "Intro";

	Intro = new AnimationSprite(2, 150);
	Intro->AddFrame(Sprite::Create("Resources/Intro/Intro1.png"));
	Intro->AddFrame(Sprite::Create("Resources/Intro/Intro2.png"));
	Intro->AddFrame(Sprite::Create("Resources/Intro/Intro3.png"));
	Intro->SetCurrentFrane(0);
	Intro->parentObject = this;
	Intro->SetAutoNext(true);

	AddChild(Intro);

	cout << "Current Scene : " << id << endl;

	auto timer = new Timer([]()
	{
		SceneMgr::GetInstance()->SetScene(new Loading_scene());
	},6800);
	timer->Run();
}

Intro_scene::~Intro_scene()

{
}   

void Intro_scene::OnUpdate()
{
}

void Intro_scene::OnDraw()
{
}
