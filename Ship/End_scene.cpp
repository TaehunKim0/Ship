#include "stdafx.h"
#include "End_scene.h"


End_scene::End_scene()
{
	id = "End";


	GameTime::CurrentFrame = 0;

	cout << "Current Scene : " << id << endl;

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
