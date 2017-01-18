#include "stdafx.h"
#include "sea_stage.h"
#include"Player.h"

sea_stage::sea_stage()
{
	player = PlayerMgr::GetInstance()->GetPlayer();

	this->AddChild(player);


}


sea_stage::~sea_stage()
{

}

void sea_stage::OnUpdate()
{

}

void sea_stage::OnDraw()
{

}