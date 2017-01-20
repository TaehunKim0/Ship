#include "stdafx.h"
#include "land_stage.h"
#include"Sprite.h"
#include"Player.h"
#include"Background.h"
#include"Loading_scene.h"

land_stage::land_stage()
{
	player = PlayerMgr::GetInstance()->GetPlayer();
	background = new Background("land");

	this->AddChild(background);
	this->AddChild(player);

	//게임 시간 초기화
}

land_stage::~land_stage()
{
}

void land_stage::OnUpdate()
{
	//만약 + 버튼을 눌럿을 경우, Friendly 소환


	//스코어가 600, 1단 완성


	//스코어 1200, 2단 완성


	//스코어 1800, 3단 완성


	//스코어 2000, 거북선 제작 완료
		//로딩 씬 후 sea_stage
}

void land_stage::OnDraw()
{
}
