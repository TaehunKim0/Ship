#include "stdafx.h"
#include "Scene.h"

Scene::Scene()
{
	SetSize({
		static_cast<float>(1280),
		static_cast<float>(720)
	});
}


Scene::~Scene()
{
}

void Scene::OnUpdate()
{
}

void Scene::OnDraw()
{
}
