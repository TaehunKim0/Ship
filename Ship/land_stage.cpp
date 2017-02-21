#include "stdafx.h"
#include "land_stage.h"
#include"Scene.h"

#include"Sprite.h"
#include"Player.h"
#include"Background.h"
#include"UnitSpawner.h"
#include"TurtleShip.h"
#include"UI.h"
#include"sea_stage.h"

land_stage::land_stage(string id) : Scene(id)
{
	std::string a = this->id;

	player = PlayerMgr::GetInstance()->GetPlayer();
	background = new Background();
	unitSpawner = new UnitSpawner();
	turtleShip = new TurtleShip();
	ui = new UI();

	this->AddChild(background);
	this->AddChild(player);
	this->AddChild(BulletMgr::GetInstance());
	this->AddChild(unitSpawner);
	this->AddChild(turtleShip);
	this->AddChild(ui);
	
	background->SetBackGround(Sprite::Create("Resources/Map/land.png"));

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
	if (GameTime::TotalFrame == 300)
		turtleShip->SetTurtleShipForm(TurtleShipForm::Form1);

	//스코어 1200, 2단 완성
	if (GameTime::TotalFrame == 600)
		turtleShip->SetTurtleShipForm(TurtleShipForm::Form2);
	

	//스코어 1800, 3단 완성
	if (GameTime::TotalFrame == 800)
		turtleShip->SetTurtleShipForm(TurtleShipForm::Form3);


	//스코어 2000, 거북선 제작 완료
		//로딩 씬 후 
	if (GameTime::TotalFrame == 1000)
		turtleShip->SetTurtleShipForm(TurtleShipForm::Form4);

	//SceneMgr::GetInstance()->SetScene(new sea_stage("sea"));

	if (spawn)
	{
		unitSpawner->SpawnEnemy(1400, 100);
		unitSpawner->SpawnArrowTurret(500 , 100);
		unitSpawner->SpawnFriendly(500,500);
	}

	spawn = false;

}

void land_stage::OnDraw()
{
}
