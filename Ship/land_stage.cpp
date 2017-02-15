#include "stdafx.h"
#include "land_stage.h"

#include"Sprite.h"
#include"Player.h"
#include"Background.h"
#include"UnitSpawner.h"
#include"TurtleShip.h"
#include"UI.h"

land_stage::land_stage()
{
	
	id = "land";
	player = PlayerMgr::GetInstance()->GetPlayer();
	background = new Background("land");
	unitSpawner = new UnitSpawner();
	turtleShip = new TurtleShip();
	ui = new UI();


	this->AddChild(background);
	this->AddChild(player);
	this->AddChild(BulletMgr::GetInstance());
	this->AddChild(unitSpawner);
	this->AddChild(turtleShip);
	this->AddChild(ui);


	cout << "Current Scene : " << id << endl;

	spawn = true;

	
}

land_stage::~land_stage()
{
}

void land_stage::OnUpdate()
{
	//만약 + 버튼을 눌럿을 경우, Friendly 소환


	//스코어가 600, 1단 완성
	if (GameTime::TotalFrame == 600)
		turtleShip->SetTurtleShipForm(TurtleShipForm::Form2);


	if (GameTime::TotalFrame == 900)
		turtleShip->SetTurtleShipForm(TurtleShipForm::Form3);

	//스코어 1200, 2단 완성


	//스코어 1800, 3단 완성


	//스코어 2000, 거북선 제작 완료
		//로딩 씬 후 sea_stage

	if(spawn)
		unitSpawner->SpawnEnemy();
	
	if (spawn)
		unitSpawner->SpawnArrowTurret();

	spawn = false;
}

void land_stage::OnDraw()
{
}
