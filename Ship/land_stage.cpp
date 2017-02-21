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
	//���� + ��ư�� ������ ���, Friendly ��ȯ


	//���ھ 600, 1�� �ϼ�
	if (GameTime::TotalFrame == 300)
		turtleShip->SetTurtleShipForm(TurtleShipForm::Form1);

	//���ھ� 1200, 2�� �ϼ�
	if (GameTime::TotalFrame == 600)
		turtleShip->SetTurtleShipForm(TurtleShipForm::Form2);
	

	//���ھ� 1800, 3�� �ϼ�
	if (GameTime::TotalFrame == 800)
		turtleShip->SetTurtleShipForm(TurtleShipForm::Form3);


	//���ھ� 2000, �źϼ� ���� �Ϸ�
		//�ε� �� �� 
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
