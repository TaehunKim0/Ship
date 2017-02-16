#include "stdafx.h"
#include "sea_stage.h"
#include"Player.h"
#include"UnitSpawner.h"
#include"Background.h"
#include"UI.h"

#include"End_scene.h"

sea_stage::sea_stage(string id) :Scene(id)
{
	player = PlayerMgr::GetInstance()->GetPlayer();
	background = new Background();
	unitSpawner = new UnitSpawner();

	ui = new UI();

	AddChild(background);
	AddChild(player);
	AddChild(unitSpawner);
	AddChild(ui);
	AddChild(BulletMgr::GetInstance());

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