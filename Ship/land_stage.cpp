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
	// 카메라 위치를 플레이어 이동 방향의 반대편으로 이동해주기위해 -로 변경
	D3DXVECTOR2 cameraPosition = -GetPosition();

	// 카메라 위치와 플레이어 위치 중심을 맞춰주기위해 계산
	D3DXVECTOR2 targetPosition = player->GetPosition() - GetCenter();

	D3DXVECTOR2 transform;
	D3DXVec2Lerp(&transform, &cameraPosition, &targetPosition, 2.f);

	// 카메라는 맵 안에서만 움직여야함
	// 0 ~ 맵 가로 - 카메라 가로

	if (transform.x >= 0 && transform.x < (2000 - GetSize().x))
	{
		SetPosition({ -transform.x , 0 });
	}


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
		//unitSpawner->GetInstance()->SpawnEnemy(1400, 100);
		//unitSpawner->GetInstance()->SpawnArrowTurret(500 , 100);
		//unitSpawner->GetInstance()->SpawnFriendly(500,500);
	}

	spawn = false;

}

void land_stage::OnDraw()
{
	
}
