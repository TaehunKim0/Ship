#pragma once
class Scene : public GameObject
{

public:
	Scene();
	virtual ~Scene();

public:
	virtual void OnUpdate();
	virtual void OnDraw();

};

