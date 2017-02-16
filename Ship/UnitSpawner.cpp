#include "stdafx.h"
#include "UnitSpawner.h"

#include"Unit.h"
#include"Friendly.h"
#include"Enemy.h"
#include"ArrowTurret.h"

#include"land_stage.h"
#include"sea_stage.h"

UnitSpawner::UnitSpawner()
{
}


UnitSpawner::~UnitSpawner()
{
}

void UnitSpawner::OnUpdate()
{
	for (auto unit : unitList)
		unit->Update();
}

void UnitSpawner::OnDraw()
{
	for (auto unit : unitList)
		unit->Draw();
}

void UnitSpawner::SpawnFriendly(int x, int y)
{

	if(SceneMgr::GetInstance()->GetScene()->id == "land")	
	{
		auto friendly = new Friendly("land");
		unitList.push_back(friendly);

		friendly->SetPosition(x, y);
		//500 500
	}

	if (SceneMgr::GetInstance()->GetScene()->id == "sea")
	{
		auto friendly = new Friendly("sea");
		unitList.push_back(friendly);

		friendly->SetPosition(x, y);

	}
	printf("Spawn Friendy!");
}

void UnitSpawner::SpawnEnemy(int x, int y)
{
	cout << "Current Scene : " << SceneMgr::GetInstance()->GetScene()->id << endl;
	if (SceneMgr::GetInstance()->GetScene()->id == "land")
	{
		auto enemy = new Enemy("land");
		unitList.push_back(enemy);

		enemy->SetPosition(x, y);
		//1400 100
	}

	if (SceneMgr::GetInstance()->GetScene()->id == "sea")
	{
		auto enemy = new Enemy("sea");
		unitList.push_back(enemy);

		enemy->SetPosition(x, y);
	}

	if (SceneMgr::GetInstance()->GetScene()->id == "Main")
		printf("Main");

	if (SceneMgr::GetInstance()->GetScene()->id == "Loading")
		printf("Loading");

	printf("Spawn Enemy!");
}

void UnitSpawner::SpawnArrowTurret(int x, int y)
{
	auto turret = new ArrowTurret();
	unitList.push_back(turret);

	turret->SetPosition(x, y);
	//500 100
}
