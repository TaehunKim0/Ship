#include "stdafx.h"
#include "GameMgr.h"
#include"Console.h"

GameMgr::GameMgr()
{
}


GameMgr::~GameMgr()
{
}

void GameMgr::Init(HWND hWindow, bool windowed)
{
	GraphicMgr::GetInstance()->Init(hWindow, windowed);
	TextureMgr::GetInstance()->Init();
	InputMgr::GetInstance()->Init(hWindow);

	Console::Init();
}

void GameMgr::Release()
{
	TextureMgr::GetInstance()->Release();
	GraphicMgr::GetInstance()->Release();

	Console::Release();
}

void GameMgr::Update()
{
	InputMgr::GetInstance()->Update();

	SceneMgr::GetInstance()->Update();
	
}

void GameMgr::Draw()
{
	SceneMgr::GetInstance()->Draw();
}
