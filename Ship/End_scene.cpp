#include "stdafx.h"
#include "End_scene.h"


End_scene::End_scene()
{
	GameTime::CurrentFrame = 0;


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
