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

land_stage::land_stage(string id)
{
	player = PlayerMgr::GetInstance()->GetPlayer();
	background = new Background();
	turtleShip = new TurtleShip();
	ui = new UI();
	
	this->AddChild(background);
	this->AddChild(player);
	this->AddChild(BulletMgr::GetInstance());
	this->AddChild(UnitSpawner::GetInstance());
	this->AddChild(turtleShip);
	this->AddChild(ui);
	

	background->SetBackGround(Sprite::Create("Resources/Map/land.png"));

	cout << "Current Scene : " << id << endl;

	spawn = true;
	//SetSize({
	//	static_cast<float>(1280),
	//	static_cast<float>(720)
	//});
}

land_stage::~land_stage()
{
}

void land_stage::OnUpdate()
{
	// ī�޶� ��ġ�� �÷��̾� �̵� ������ �ݴ������� �̵����ֱ����� -�� ����
	D3DXVECTOR2 cameraPosition = -GetPosition();

	// ī�޶� ��ġ�� �÷��̾� ��ġ �߽��� �����ֱ����� ���
	D3DXVECTOR2 targetPosition = player->GetPosition() - GetCenter();

	D3DXVECTOR2 transform;
	D3DXVec2Lerp(&transform, &cameraPosition, &targetPosition, 2.f);

	// ī�޶�� �� �ȿ����� ����������
	// 0 ~ �� ���� - ī�޶� ����

	if (transform.x >= 0 && transform.x < (2000 - GetSize().x))
	{
		SetPosition({ -transform.x , 0 });
	}


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
		//unitSpawner->GetInstance()->SpawnEnemy(1400, 100);
		//unitSpawner->GetInstance()->SpawnArrowTurret(500 , 100);
		//unitSpawner->GetInstance()->SpawnFriendly(500,500);
	}

	spawn = false;

}

void land_stage::OnDraw()
{
	
}
