#include "stdafx.h"
#include "Intro_scene.h"
#include"Loading_scene.h"

Intro_scene::Intro_scene()
{
	GameTime::CurrentFrame = 0;
	Intro = new AnimationSprite(2, 150);
	Intro->AddFrame(Sprite::Create("Resources/Intro1.png"));
	Intro->AddFrame(Sprite::Create("Resources/Intro2.png"));
	Intro->AddFrame(Sprite::Create("Resources/Intro3.png"));
	Intro->SetCurrentFrane(0);
	Intro->parentObject = this;
	Intro->SetAutoNext(true);

	auto timer = new Timer([]()
	{
		SceneMgr::GetInstance()->SetScene(new Loading_scene());
	},7000);
	timer->Run();
}

Intro_scene::~Intro_scene()
{
	SAFE_DELETE(Intro);
}

void Intro_scene::OnUpdate()
{
	Intro->Update();
}

void Intro_scene::OnDraw()
{
	Intro->Draw();
}
