#include "stdafx.h"
#include "SceneMgr.h"

#include"Scene.h"
SceneMgr::SceneMgr()
{
	currentScene = NULL;
}


SceneMgr::~SceneMgr()
{
	if (currentScene)
		SAFE_DELETE(currentScene);
}

void SceneMgr::Update()
{
	if (currentScene)
		currentScene->Update();
}

void SceneMgr::Draw()
{
	GraphicMgr::GetInstance()->BeginDraw();

	if (currentScene)
		currentScene->Draw();

	GraphicMgr::GetInstance()->EndDraw();
}

void SceneMgr::SetScene(Scene * scene)
{
	if (currentScene)
		SAFE_DELETE(currentScene);

	currentScene = scene;

}

Scene * SceneMgr::GetScene()
{
	return currentScene;
}