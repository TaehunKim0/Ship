#include "stdafx.h"
#include "End_scene.h"


End_scene::End_scene()
{
	GameTime::CurrentFrame = 0;


	//��Ʈ�ΰ� ������ ���� ����
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
