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
	//���� + ��ư�� ������ ���, Friendly ��ȯ


	//���ھ 600, 1�� �ϼ�
	if (GameTime::TotalFrame == 600)
		turtleShip->SetTurtleShipForm(TurtleShipForm::Form2);


	if (GameTime::TotalFrame == 900)
		turtleShip->SetTurtleShipForm(TurtleShipForm::Form3);

	//���ھ� 1200, 2�� �ϼ�


	//���ھ� 1800, 3�� �ϼ�


	//���ھ� 2000, �źϼ� ���� �Ϸ�
		//�ε� �� �� sea_stage

	if(spawn)
		unitSpawner->SpawnEnemy();
	
	if (spawn)
		unitSpawner->SpawnArrowTurret();

	spawn = false;
}

void land_stage::OnDraw()
{
}
