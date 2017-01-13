#include "stdafx.h"
#include "PlayerMgr.h"
#include"Player.h"

PlayerMgr::PlayerMgr()
{
	player = new Player();
}


PlayerMgr::~PlayerMgr()
{
	delete player;
}

Player * PlayerMgr::GetPlayer()
{
	return player;
}
