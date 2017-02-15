#include "stdafx.h"
#include "End_scene.h"


End_scene::End_scene()
{
	id = "End";


	GameTime::CurrentFrame = 0;

	cout << "Current Scene : " << id << endl;

	//인트로가 끝나면 게임 종료
	auto timer = new Timer([]()
	{
		PostQuitMessage(1);
	}, 6000);



	timer->Run();
}


End_scene::~End_scene()
{
}

void End_scene::OnUpdate()
{
	end->Update();

	
}

void End_scene::OnDraw()
{
	end->Draw();
}
