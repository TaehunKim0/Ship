#include "stdafx.h"
#include "UnitSpawner.h"

#include"Unit.h"
#include"Friendly.h"
#include"Enemy.h"

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

void UnitSpawner::SpawnFriendly()
{

	if(SceneMgr::GetInstance()->GetScene()->id == "land")	
	{
		auto friendly = new Friendly("land");
		unitList.push_back(friendly);

		friendly->SetPosition(200, 100);

	}

	if (SceneMgr::GetInstance()->GetScene()->id == "sea")
	{
		auto friendly = new Friendly("sea");
		unitList.push_back(friendly);

		friendly->SetPosition(200, 100);
	}
	printf("Spawn Friendy!");
}

void UnitSpawner::SpawnEnemy()
{
	cout << "Current Scene : " << SceneMgr::GetInstance()->GetScene()->id << endl;
	if (SceneMgr::GetInstance()->GetScene()->id == "land")
	{
		auto enemy = new Enemy("land");
		unitList.push_back(enemy);

		enemy->SetPosition(700, 100);
	}

	if (SceneMgr::GetInstance()->GetScene()->id == "sea")
	{
		auto enemy = new Enemy("sea");
		unitList.push_back(enemy);

		enemy->SetPosition(700, 100);
	}

	printf("Spawn Enemy!");
}
