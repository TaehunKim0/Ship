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
}

void BulletMgr::OnDraw()
{
}

