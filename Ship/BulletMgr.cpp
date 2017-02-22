#include "stdafx.h"
#include "BulletMgr.h"

#include"Bullet.h"
BulletMgr::BulletMgr()
{
}


BulletMgr::~BulletMgr()
{
}

void BulletMgr::RegisterBullet(Bullet * bullet)
{
	AddChild(bullet);
}

void BulletMgr::OnUpdate()
{

	for (auto b : bulletList)
	{
		if (b->GetVisisble() == false)
		{
			vector<Bullet*>::iterator iter = std::find(bulletList.begin(), bulletList.end(), b);
			bulletList.erase(iter);
			printf("ERASE");
		}
	}
}

void BulletMgr::OnDraw()
{
}