#pragma once
class Scene : public GameObject
{

public:
	Scene();
	Scene(string id) : id(id) {}
	virtual ~Scene();

	string id;

public:
	virtual void OnUpdate();
	virtual void OnDraw();

};

