#include "stdafx.h"
#include "sea_stage.h"
#include"Player.h"
#include"Friendly.h"
#include"Enemy.h"
#include"End_scene.h"

sea_stage::sea_stage()
{
	id = "Sea";
	player = PlayerMgr::GetInstance()->GetPlayer();

	friendly = new Friendly("sea");
	enemy = new Enemy("sea");


	this->AddChild(player);
	this->AddChild(friendly);
	this->AddChild(enemy);

	cout << "Current Scene : " << id << endl;
}

sea_stage::~sea_stage()
{

}

void sea_stage::OnUpdate()
{
	//바다 배경으로 바뀜



	//wave 1
	

	//wave 2


	//wave 3
		//보스 등장

	//보스를 죽인다면 
	SceneMgr::GetInstance()->SetScene(new End_scene());	//End_scene 시작


}

void sea_stage::OnDraw()
{

}